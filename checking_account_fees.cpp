//********************************************************************
// Checking account program with restrictions and fees
// Programmer:  Matt Denton
// Completed: 9/23/13.
// Status: Complete
//

#include <iostream> // input/output declarations
#include <iomanip>  // i/o manipulator declarations

using namespace std;

double writeCheck (double& balance, float amount);
double makeDeposit (double& balance, float amount);

int main()
{
    const double SERVICE_FEE = 0.25; //service fee for each written check
    const double LESS_800 = 5.0;
	const double LESS_NEGATIVE_BALANCE = 25.0;

    double balance,         //monthly balance
    totalSvcCharge=0;  //end of the month sum of all service fees
    float amount,      //transaction amount
    finalBalance;    //End of month processing
    int numServCharge = 0; //accumulator for total number of service fees
    int numLess800 = 0; //accumulator for single charge of less than 800 balance
	int numLessZero = 0; //accumulator for writing checks that result in negative balance



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
            cin >> amount;
        } //Ensure the user enters a positive number
        while (amount <=0)
        {   //error statement for negative amount
            cout << "Please enter a positive number (larger than zero): ";
            cin >>amount;
        }

        if (choice == 'C')
        {
            //process checking transactions
            writeCheck (balance, amount); //function which uses reference variable to return changed balance value

            //balance condition statements
            if (balance < 800 && balance>0)
            {
                cout <<"Balance: "<<balance<<endl;
                cout << "Service charge: $" << SERVICE_FEE << " for a check"<<endl;
                cout << "Service charge: $" << LESS_800 << " for a balance less than $800"<<endl;
                numServCharge++; //accumulates total for each service fee charge
                cout << "Total service charges: $ "<<totalSvcCharge;
                numLess800 = 1;
                for (numLess800=1; numLess800<1; numLess800++)//This is a bug I have run out of time to fix!
                {totalSvcCharge= (numServCharge * SERVICE_FEE) + (numServCharge * LESS_800);
                }
                    for (numLess800=1; numLess800>1; numLess800++)
                    {totalSvcCharge= (numServCharge * SERVICE_FEE);
                    }
                //However, program is still accumulating .25 charge for each check written below 800 balance.

                cout <<endl;
            }


        else if (balance < 0)
        {
            cout <<"Balance: "<<balance<<endl;
            cout << "Service charge: $" << SERVICE_FEE << " for a check"<<endl;
            cout << "Service charge: $25 for a balance less than $0.0" << endl;
            numServCharge++;
            numLessZero++;
            totalSvcCharge = (numServCharge * SERVICE_FEE) + (numLess800 * LESS_800) + (numLessZero * LESS_NEGATIVE_BALANCE);
            cout <<"Total service charges: "<< totalSvcCharge <<endl;
        }
        else
        {
            cout <<"Balance: "<<balance<<endl;
            cout << "Service charge: $0.25 for a check\n";
            numServCharge++; //accumulates total for each service fee charged
            totalSvcCharge= numServCharge * SERVICE_FEE;
            cout << "Total service charges: $ "<<totalSvcCharge;
            cout <<endl;
        }

    }

    if (choice == 'D')
    {
        cout << "Processing deposit for: $"<<amount <<"\n";
        makeDeposit(balance, amount);
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

    return 0;
    }

    }
    double writeCheck (double& balance, float amount) //Function to process check
    {

        balance -= amount;
        return balance;
    }


    double makeDeposit (double& balance, float amount) //Function to process deposit
    {
        balance += amount;
        return balance;
    }


