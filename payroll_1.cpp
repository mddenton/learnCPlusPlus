//  Payroll_Version_1.0
//
//  Created by Matthew Denton on 10/21/13.
//  Copyright (c) 2013 Matthew Denton. All rights reserved.
//  Status:Complete

#include <iostream> // input/output declarations
#include<string>
#include<iomanip> // i/o manipulator declarations

using namespace std;



struct empInfo //struct with Employee master information
{
    int id;
    string fullName;
    float payRate;
    int empType;
    
};

int main()
{
    const int NUM_EMPS = 4;//# of employees presently 4
    int n=0;//counter for array
    float tax, grossPay, netPay;
    double totalGross=0;
    double totalNet=0;
    float hoursArray[NUM_EMPS];
    empInfo empArray [NUM_EMPS]; //struct array with Employee master information
    
    for (n=0; n<NUM_EMPS; n++)//user input of Employee master information; iterates for each employee
    {
        cout<<"Employee information for employee "<< (n+1);
        cout<<endl;
        cout<<"Employee id: ";
        cin>> empArray[n].id;
        while (empArray[n].id<0){
            cout<<"Please enter positive integers (greater than zero)"<<endl;//validation for positive integers
            cin>> empArray[n].id;}
        cout<<"Employee name: ";
        cin.ignore();//useful function which skips the return key for input
        getline (cin, empArray[n].fullName);
        cout<<"Pay Rate: ";
        cin>> empArray[n].payRate;
        while (empArray[n].payRate<0){
        cout<<"Please enter positive integers (greater than zero)"<<endl;//validation for positive integers
            cin>> empArray[n].payRate;}
        cout<<"Employee Type; enter 0 for union or 1 management: ";
        cin>> empArray[n].empType;
        while ((empArray[n].empType>1) || (empArray[n].empType<0)){
            cout<<"Employee type should be 0 or 1.";//validation for employee type of 0 for Union and 1 for management.
            cin>> empArray[n].empType;}
    }
    
    for (n=0; n<NUM_EMPS; n++)
    {
        cout<<"Enter time card information for each employee: "<<endl;
        cout<<"Hours worked for " << empArray[n].fullName<<":";
        cin>>hoursArray[n];//for each employee this array will parallel the same position in memory to match the timesheet information to the master struct
    }
    
    
    cout<<"Payroll Report"<<endl;
    cout<<left<<setw(5)<<"ID"<<setw(15)<<"Name"<<setw(8)<<"Gross Pay"<<setw(8)<<"Tax"<<setw(8)<<"Net Pay";
    cout<<endl;
    for (int n=0; n<NUM_EMPS; n++)//calculations of timesheet included in output. For each iteration of the struct array this output will be added to.
    {
        if (hoursArray[n]>40 && empArray[n].empType==0)// if hours greater than 40 and employee is Union type, include this calculation for OT
            grossPay=((empArray[n].payRate*40) + (empArray[n].payRate * (hoursArray[n] - 40) * (1.5)));
        else
            grossPay = (hoursArray[n] * empArray[n].payRate);//if regular time and management employee you get regular pay...
            
        tax=grossPay * (.15); //tax rate is (.15)
        netPay= grossPay - tax;
        totalGross = totalGross + grossPay;//calculates the total Gross wages owed for entire payroll
        totalNet+=netPay;//calculates the total Net wages owed for entire payroll
        
        cout<<left<<setw(5)<<empArray[n].id<<setw(16)<<empArray[n].fullName<<setw(8)<<fixed<<setprecision(2)<<grossPay<<setw(8)<<tax<<setw(8)<<netPay<<endl;
    }
    cout<<endl;
    cout<<fixed<<setprecision(2);
    cout<<"Total Gross Pay $"<<totalGross<<endl;
    cout<<"Total Net Pay $"<<totalNet;

    
    
    
    
    

    system ("pause");
    return 0;
}

