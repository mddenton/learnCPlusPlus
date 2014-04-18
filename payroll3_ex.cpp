//  Payroll_Version 3.0
//  Assignment #10
//  Created by Matthew Denton on 12/12/13.
//  Copyright (c) 2013 Matthew Denton. All rights reserved.
//  Status:Complete
// Payroll program adapted to use c-strings rather than string objects. Also processes partially filled arrays.

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
    char name[21];        // employee name
    double hourlyPay;   // pay per hour
    int numDeps;        // number of dependents
    int type;           // employee type

public:
    Employee();
    Employee( char initName [], int initId=0,
             double initHourlyPay=0.0,
             int initNumDeps=0, int initType=0 );  // Constructor

    bool set(char newName [], int newId, double newHourlyPay,
             int newNumDeps, int newType);

    int getEmpId();
    const char *getName();
    double getHourlyPay();
    int getDependents();
    int getType();

};

//End of Class Declaration


//Employee class Constructor
Employee::Employee()
{
    id = 0;
    //    for (int i=0; i<20; i++)
    name[0] = '\0';
    hourlyPay = 0.0;
    numDeps = 0;
    type = 0;
}


Employee::Employee( char initName [], int initId,
                   double initHourlyPay,
                   int initNumDeps, int initType )
{
    bool status = set( initName, initId, initHourlyPay,
                      initNumDeps, initType );

    if ( !status )
    {

        id = 0;
        //    for (int i=0; i<20; i++)
        name[0] = ' ';
        hourlyPay = 0.0;
        numDeps = 0;
        type = 0;
    }
}


//Employee class set function

bool Employee::set( char newName [], int newId, double newHourlyPay,
                   int newNumDeps, int newType )
{
    bool status = false;

    if ( newId > 0 && newHourlyPay > 0 && newNumDeps >= 0 &&
        newType >= 0 && newType <= 1 )
    {
        status = true;
        id = newId;
        for (int i=0; i<21; i++)
            name[i] = newName[i];
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
const char * Employee::getName()//since we have a pointer to the class function
{                               //important to make the char function a constant to prevent changes being made
    return name;                //by programmers using this class
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

int search (int emdID, Employee [], int);

int main ()
{
    const int NUM_EMPLOYEES = 100; // number of employees
    //Define an arry for Employee objects
    Employee masterFile[NUM_EMPLOYEES]; //array of class Employee
    TransInfo paycheck; //array of structures TransInfo

    //Main variables
    int index, numEmps;
    double grossPay=0.0, netPay=0.0, insurance=0, tax=0.0, totalGrossPay=0.0, totalNetPay=0.0;
    int count=0; //counter

    // temporary variables
    int tempId;           // employee ID
    char tempName [21];   //employee name
    double tempHourlyPay; //pay per hour
    int tempNumDeps;      //number of dependents
    int tempType;         //employee type
    int hoursWorked;      // hours worked by each employee
    char gender;
    int countTrans=0;
    int numMasterEmps=0;
    int position;
    // define name of input file then open
    ifstream inputfile1 ("master10.txt");
    if (inputfile1.fail())
    {
        cout << "Unable to open data file\n";
        system("PAUSE");
        exit(1);
    }//end if
    else
    {
        //Fill masterFile class array from file
        for (index =0; index < NUM_EMPLOYEES; index++)
        {

            //Read employee masterfile into temporary variables and set class array
            //Employee class object will do validation of employee info
            inputfile1 >> tempId;
            inputfile1.ignore();
            inputfile1.get(tempName, 20, '\n');
            inputfile1 >> tempHourlyPay >> tempNumDeps >> tempType >> gender;
            //getline (inputfile1 >> tempId >> tempName >> tempHourlyPay >> tempNumDeps >> tempType;
            if (inputfile1.eof())
                break;
            masterFile[index].set(tempName, tempId, tempHourlyPay, tempNumDeps, tempType);
            //cout << tempId << "   " << tempName << "   " << tempHourlyPay << "   " << tempNumDeps << "   " << tempType <<"   " << gender <<endl;
            numMasterEmps++;
            //system("pause");
        }//end for loop
    }//end else
    cout << "Number of employees in master file = " << numMasterEmps << endl;
    //Close input file
    inputfile1.close();

    //define name of input file and open
    ifstream inputfile2("trans10.txt");
    if (inputfile2.fail())
    {
        cout << "Unable to open data file\n";
        system("PAUSE");// pause output
        exit (1);
    }// end if
    else
    {
    // define name and open output file
    ofstream outputFile("payroll_report.txt");
    //Print Payroll Report to file-One line for each transaction/ tabular row and column
    outputFile << fixed << showpoint << setprecision (2);
    outputFile << "ID" << setw(20) << "Name" << setw(25) << "Gross Pay" << setw(12) << "Tax" << setw (16) << "Insurance" << setw(15) << "Net Pay"<<endl;

        // Fill TransInfo Struct variables from file
        index=0;
        inputfile2 >> paycheck.empID >> paycheck.hoursWorked;
        while (inputfile2)
        {
            //Read transaction file into struct variables
        	index++;
			position = search (paycheck.empID, masterFile, numMasterEmps);

            if (position == -1)
            {
                cout << "error: hours worked file id # " << paycheck.empID << " not found in master file" << endl;
            }
            else
            {
                //cout << "we need to pay " << masterFile[position].getName() << endl;
                //paycheck.normalPay = (paycheck.hoursWorked * masterFile[index].getHourlyPay());
                //   cout << masterFile[index].getEmpId() << "   " << paycheck.hoursWorked << "   " << paycheck.normalPay << endl;
                if (paycheck.empID >0)
                {
                //if hoursWorked ==0
                if (paycheck.hoursWorked > 0)
                {
                //calculate Grosspay validate type and apply payrate
                if ((masterFile[position].getType() == 0) && (paycheck.hoursWorked > 40)) //Union workers
                {
                    grossPay = (paycheck.hoursWorked - 40)*    1.5 * masterFile[position].getHourlyPay() + 40 * masterFile[position].getHourlyPay();
                    //cout << "in final loop" << endl;
                }//end if
                else
                {
                    grossPay= paycheck.hoursWorked * masterFile[position].getHourlyPay(); //regular pay
                }//end else

                //Calculate Insurance cost for employees who have greater than 0 dependents
                insurance = masterFile[position].getDependents() * 20;

                //Calculate Tax for all employees
                tax = grossPay * .15;

                //Calculate net pay
                netPay = (grossPay - tax - insurance);

                //Write emp data
                outputFile << left << setw(17) << paycheck.empID << setw(11) << right << masterFile[position].getName() << setw(9)<< grossPay << setw(15)<< tax << setw(15)<< insurance << setw(15)<< netPay << endl;

                //Sum all Gross pay
                totalGrossPay += grossPay;

                //Sum all Net Pay
                totalNetPay += netPay;
                countTrans++;

            }//end if
            else
            {
                //error message if hoursWorked<0
                cout <<masterFile[position].getName()<<"has less then 0.0 hours worked. This employee will not be included in the payroll report" << endl;
            }//end if




            }//end if



        }//end else loop
        inputfile2 >> paycheck.empID >> paycheck.hoursWorked;//repeat for next employee, must have before end of while loop
    }//end while loop                                        //in order for processing to be repeated for next employee
    inputfile2.close();                                      //until there are no more lines of data to process

    cout << "count of employees in transaction file = " << index << endl;

    cout <<"\nNumber of successful transactions: "<< countTrans <<endl;

    //provide total for gross pay and net pay for all records
    outputFile << "\nTotal Gross Pay: " << totalGrossPay << "\nTotal Net Pay  : " << totalNetPay <<endl;

    //Close output file
    outputFile.close();
    }//end of inputfile1 else loop
    //print to screen the total number of transactions that were processed correctly to screen

    system("PAUSE");
    return EXIT_SUCCESS;

} //end of main

//**************************************************************************
//*  FUNCTION search
//*
//*  Find the location of an item in a list
//*
//**************************************************************************

int search ( int empID, Employee masterFile[], int length)
{
    //search list for employee ID and return its position if found
    int index = 0;
    while (index < length)
    {
        if (empID == masterFile[index].getEmpId())
            return index;
        index++;
    }
    //item not found-return a flag
    return -1;
}
