//********************************************************************
// Checking account program
// Programmer:  Matt Denton
// Completed: 9/14/13.
// Status: Complete
//

#include <iostream> // input/output declarations
#include <iomanip>  // i/o manipulator declarations

using namespace std;

int main()
{
    const double SERVICE_FEE = 0.25; //service fee for each written check
    
    double balance,         //monthly balance
           totalSvcCharge=0;  //end of the month sum of all service fees
    double transAmount,      //transaction amount
           finalBalance;    //End of month processing
    int numServCharge = 0; //accumulator for total number of service fees
    
    
    
    char choice;            //User input as a character
    
    //set all amounts entered to have two decimal places displayed
    cout <<fixed <<showpoint<< setprecision (2);
    cout <<"Checkbook Balancing Program\n";
    cout <<"Enter the beginning balance: \n";
    cin>> balance;
    cout <<endl;
    
    do
    { //Display the menu and get the user's choice
        
        cout << "Commands:\n";
        cout << "C - process a check\n";
        cout << "D - process a deposit\n";
        cout << "E - end the program\n";
        cout << "Enter transaction type: ";
        cin >> choice;
        cout << endl;
        
        //Validate the menu selection
        while ((choice < 'C')|| (choice > 'E') )
        {
            cout <<"Please enter (in caps) C for checks, D for deposit\n";
            cout <<"or E for end of month processing and exit\n";
            cin >> choice;
        }
        //Process the user's choice
        if (choice != 'E')
        { cout << "Enter transaction amount: ";
            cin >> transAmount;
        } //Ensure the user enters a positive number
        while (transAmount <=0)
        {   //error statement for negative amount
            cout << "Please enter a positive number (larger than zero): ";
            cin >>transAmount;
        }
        
        if (choice == 'C')
        {
        //process checking transactions
        cout << "Processing check for: $"<<transAmount<<"\n";
            balance -= transAmount;
            cout << "Balance: $" << balance<<"\n";
            cout << "Service charge: $0.25 for a check\n";
            numServCharge++; //accumulates total for each service fee charged
            totalSvcCharge= numServCharge * SERVICE_FEE;
            cout << "Total service charges: $ "<<totalSvcCharge;
            cout <<endl;
            cout <<endl;
        }
        
        if (choice == 'D')
        {
            cout << "Processing deposit for: $"<<transAmount <<"\n";
            balance += transAmount;
            cout << "Balance: $" << balance<<"\n";
            cout << "Total service charges: $"<<totalSvcCharge<<"\n";
            cout <<endl;
            cout <<endl;
                
            
        }
        
    } while (choice != 'E'); //loop again if the user did not select
                             // choice E to do end of month processing
                             // and exit the program
    
    
    if (choice == 'E')
    {
        cout <<"Processing end of month\n"; //Service fees charged at month's
                                            //end
        finalBalance = balance - totalSvcCharge;
        cout <<"Final balance: $"<< finalBalance;
        
    }
    
    
    
    return 0;

}

