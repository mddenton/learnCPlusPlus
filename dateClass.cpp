//********************************************************************
// Date Class program
// Programmer:  Matt Denton
// Completed: 9/28/13.
// Status: Complete
//

#include <iostream>
#include <string>
using namespace std;


class Date

{
    int month; //private variables
    int day;
    int year;
    //Note unauthorized use of array as anything else seemed inefficient.
    string monthName[12] = {"January","February","March","April","May","June","July",
        
        "August","September","October","November","December"};
    
public:
    Date () //default constructor sets month, day and year to default values
    { month=1;
        day=1;
        year=2001;
    }
    
    Date (int month, int day, int year) //second constructor (overloaded) with parameters
    {
        Date::month = month; //creation of a month object
        Date::day = day; //creation of a day object
        Date::year = year; //creation of a year object
    };
    void setDate ();
    void showFirstDate();//member function prototype
    void showSecondDate();//member function prototype
    void showThirdDate();//member function prototype
    ~Date(){} //destructor prototype to end class
};
//The member function implementation section follows. It contains the
//function definitions for the set function followed by three Date class "print" member functions.

void Date::setDate(){
    
    if (month > 12 || month < 1)
    {
        month = 1;
    }
    if (day > 31 || day < 1)
    {
        day = 1;
    }
    if (year > 2020 || year < 1950)
        
    {
        year = 2001;
    }


    
}

void Date::showFirstDate(){
    
    cout << month << "/" << day << "/" << year << endl;
}
//array definition specifies to subtract 1 from user entered value to display correct month.
void Date::showSecondDate(){
    cout << monthName[month-1] << " " << day << ", " << year << endl;
    }

void Date::showThirdDate(){
    cout << day << " " << monthName[month-1] << " " << year << endl;
}

int main()
{  
    int month;
    int day;
    int year;
    
    cout << "enter month (between 1 and 12)" << endl;
    cin >> month;

    cout << "enter day (between 1 and 31)" << endl;
    cin >> day;
    
    cout << "enter year (between 1950 and 2020)"<< endl;
    cin >> year;
    Date newDate(month, day, year); //call function to pass user date to class
    newDate.setDate();
    newDate.showFirstDate();
    newDate.showSecondDate();
    newDate.showThirdDate();

  
    
    
    return 0;
    
}