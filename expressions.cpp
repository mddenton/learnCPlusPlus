//******************************************************************
// Expressions program
// Programmer: Matt Denton
// Completed : 9/08/2013
// Status    : Complete
//
// This program reads 2 integer values from the keyboard then calculates
// the sum, product, average, quotient and modulus.
//******************************************************************

#include <iostream>      // input/output declarations
#include <iomanip>       // i/o manupulator declarations

using namespace std;

int main()

{
    int a, b;
    cout <<"Enter two integers: "<<endl; //prints on screen to prompt
                                        //user to enter the number
    cin >> a >> b;  // inputs 2 numbers from user and stores them in integers a
                    // and b
    
    cout << left << setw(8) << "Sum"
         << right<< setw(3) << "is" <<setw(8)<< a + b <<endl;
    
    cout <<left<< setw(8) <<"Product"
         <<right<< setw(3) <<"is" << setw(8) << a * b <<endl;
    
    cout <<left << setw(8) <<"Average"
         <<right<< setw(3)<<"is" << setw(8) << ( a + b ) / 2 <<endl;
    
    cout <<left << setw(8) <<"Quotient"
         <<right<< setw(3)<<"is" << setw(8) << a / b <<endl;
    
    cout <<left << setw(8) <<"Modulus"
         <<right << setw(3)<<"is"<< setw(8) << a % b <<endl;
    
    return 0;
}
