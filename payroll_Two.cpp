//  Payroll_Version 2.0
//  Assignment #9
//  Created by Matthew Denton on 12/5/13.
//  Copyright (c) 2013 Matthew Denton. All rights reserved.
//  Status:Complete
// Payroll program adapted to use a class. An array is used as an Employee class object
// with each element of the array holding the employee info being an instance of the object.

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//Class declaration for Employee
class Employee 
{
  private:
    int id;             // employee ID
    string name;        // employee name
    double hourlyPay;   // pay per hour
    int numDeps;        // number of dependents
    int type;           // employee type
    
  public:
    Employee( int initId=0, string initName="", 
              double initHourlyPay=0.0, 
              int initNumDeps=0, int initType=0 );  // Constructor

    bool set(int newId, string newName, double newHourlyPay,
             int newNumDeps, int newType);
    
    int getEmpId();
    string getName();
    double getHourlyPay();
    int getDependents();
    int getType();
    
};

//End of Class Declaration


//Employee class Constructor

Employee::Employee( int initId, string initName, 
                    double initHourlyPay,
                    int initNumDeps, int initType )
{
  bool status = set( initId, initName, initHourlyPay, 
                     initNumDeps, initType );

  if ( !status )
  {
    id = 0;
    name = "";
    hourlyPay = 0.0;
    numDeps = 0;
    type = 0;    
  }
}


//Employee class set function

bool Employee::set( int newId, string newName, double newHourlyPay,
                                 int newNumDeps, int newType )
{
  bool status = false;

  if ( newId > 0 && newHourlyPay > 0 && newNumDeps >= 0 && 
       newType >= 0 && newType <= 1 )
  {
    status = true;
    id = newId;
    name = newName;
    hourlyPay = newHourlyPay;
    numDeps = newNumDeps;
    type = newType;
  }
  return status;
}

//Employee class get functions

//* get employee ID function/*

int Employee::getEmpId()
{
    return id;
}
//* get employee Name function/*
string Employee::getName()
{
    return name;       
}
//* get employee HourlyPay function/*    
double Employee::getHourlyPay()
{
    return hourlyPay;
}
//* get employee number of dependents function/*
int Employee::getDependents()
{
    return numDeps;
}
//* get employee Type function/*
int Employee::getType()
{
    return type;
}


//Struct Declaration for TransInfo

struct TransInfo
{    
     int empID;
     double hoursWorked;
     double normalPay;    
};

int main ()
{
    const int NUM_EMPLOYEES = 6; // number of employees
    //Define an arry for Employee objects
    Employee masterFile[NUM_EMPLOYEES]; //array of class Employee
    TransInfo paycheck[NUM_EMPLOYEES]; //array of structures TransInfo
    
    //Main variables
    int index;
    double grossPay=0.0, netPay=0.0, insurance=0, tax=0.0, totalGrossPay=0.0, totalNetPay=0.0;
    int count=0; //counter
    
    // temporary variables
    int tempId;           // employee ID
    string tempName;      //employee name
    double tempHourlyPay; //pay per hour
    int tempNumDeps;      //number of dependents
    int tempType;         //employee type
    int hoursWorked;      // hours worked by each employee
    int countTrans=0;
    // define name of input file then open
    ifstream inputfile1 ("master9.txt");
    if (!inputfile1)
    {
      cout << "Unable to open data file\n";              
    }//end if
    else
    {
        //Fill masterFile class array from file
        for (index =0; index < NUM_EMPLOYEES; index++)
        {
        
            //Read employee masterfile into temporary variables and set class array
            //Employee class object will do validation of employee info
            inputfile1 >> tempId;
            getline (inputfile1,tempName, '#');
            inputfile1 >> tempHourlyPay >> tempNumDeps >> tempType;
            //getline (inputfile1 >> tempId >> tempName >> tempHourlyPay >> tempNumDeps >> tempType;
            masterFile[index].set(tempId, tempName, tempHourlyPay, tempNumDeps, tempType);
            //cout << tempId << "   " << tempName << "   " << tempHourlyPay << "   " << tempNumDeps << "   " << tempType <<"   " <<endl;
         }//end for loop
    }//end else
    //Close input file
    inputfile1.close();
    
    //define name of input file and open
    ifstream inputfile2("trans9.txt");
    if (!inputfile2)
    {
       cout << "Unable to open data file\n";
    }// end if
    else
    {
    // Fill TransInfo Struct array from file
        for (index = 0; index < NUM_EMPLOYEES; index++)
        {
               //Read transaction file into struct array
               inputfile2 >> paycheck[index].empID >> paycheck[index].hoursWorked;
               //paycheck[index].normalPay=0;
               paycheck[index].normalPay = (paycheck[index].hoursWorked * masterFile[index].getHourlyPay());
               //cout << masterFile[index].getEmpId() << "   " << paycheck[index].hoursWorked << "   " << paycheck[index].normalPay << endl;
        }//end for loop
    }//end else
    inputfile2.close();
    
    // define name and open output file
    ofstream outputFile("payroll9.txt");
    outputFile << fixed << showpoint << setprecision (2);
    outputFile << "ID" << setw(20) << "Name" << setw(25) << "Gross Pay" << setw(15) << "Tax" << setw (15) << "Insurance" << setw(15) << "Net Pay"<<endl;
    
    //Payroll processing
    // Read arrays if employee ID !0
    for (index =0; index< NUM_EMPLOYEES; index++)
    {
        if (masterFile [index].getEmpId()>0)
        {
           //if hoursWorked ==0
           if (paycheck[index].hoursWorked > 0)
           {
              //calculate Grosspay validate type and apply payrate
              if ((masterFile[index].getType() == 0) && (paycheck[index].hoursWorked > 40)) //Union workers
              {
                 grossPay = (paycheck[index].hoursWorked - 40)* 1.5 * masterFile[index].getHourlyPay() + 40 * masterFile[index].getHourlyPay();
                 //cout << "in final loop" << endl;
              } 
              else
              {
                  grossPay= paycheck[index].hoursWorked * masterFile[index].getHourlyPay(); //regular pay
              }
              
              //Calculate Insurance cost for employees who have greater than 0 dependents
              insurance = masterFile[index].getDependents() * 20;
                
              //Calculate Tax for all employees
              tax = grossPay * .15;
                
              //Calculate net pay
              netPay = (grossPay - tax - insurance);
              
              //Write emp data
              outputFile << left << setw(17) << masterFile[index].getEmpId() << setw(11) << right << masterFile[index].getName() << setw(9)<< grossPay << setw(15)<< tax << setw(15)<< insurance << setw(15)<< netPay << endl;
              
              //Sum all Gross pay
              totalGrossPay += grossPay;
            
              //Sum all Net Pay    
              totalNetPay += netPay;
              countTrans++;
                
            }//end if
          else
          {
              //error message if hoursWorked<0
              cout <<masterFile[index].getName()<<"has less then 0.0 hours worked. This employee will not be included in the payroll report" << endl;  
          }                           
        }// end masterFile getEmpID if loop
    }//end employee ID for loop
    cout <<"\nNumber of successful transactions: "<< countTrans <<endl;
    //Print Payroll Report to file-One line for each transaction/ tabular row and column 
     for (index =0; index< NUM_EMPLOYEES; index++)
    {
     
     } 
     //provide total for gross pay and net pay for all records
     outputFile << "\nTotal Gross Pay: " << totalGrossPay << "\nTotal Net Pay  : " << totalNetPay <<endl;
           
     //Close output file
     outputFile.close();
      
//print to screen the total number of transactions that were processed correctly to screen




    system("PAUSE");
    return EXIT_SUCCESS;
        
    
    
    
} //end of main
