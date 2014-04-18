//  Monkey Business
//
//  Status: Completed
//  Created by Matthew Denton on 11/7/13.
//  Copyright (c) 2013 Matthew Denton. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


const int NUM_MONKEYS = 3;  // Number of rows
const int NUM_DAYS = 7;     // Number of columns

//Function prototypes
void fillArray (float [][NUM_DAYS], int);
void showArray (float [][NUM_DAYS], int, float, float, float);//[NUM_DAYS], int);
float calcMax  (float [][NUM_DAYS], int);
float calcMin  (float [][NUM_DAYS], int);
float calcAvg  (float [][NUM_DAYS], int);


int main()
{
    
    //Define 2-D array to hold monkey feeding data
    float food[NUM_MONKEYS][NUM_DAYS]; // Holds the daily feeding amounts
    float min;                         // Holds the minimum feeding weight
    float max;                         // Holds the maximum feeding weight
    float average;                     // Holds the average amount of food eater per day
    
    fillArray (food, NUM_MONKEYS);
    max = calcMax (food, NUM_MONKEYS);
    min = calcMin (food, NUM_MONKEYS);
    average = calcAvg (food, NUM_MONKEYS);
    
    showArray (food, NUM_MONKEYS, average, max, min);
    system("pause");
    return 0;
}


//This function receives the address of a 2-D array and fills it with data input by user.
void fillArray (float array[][NUM_DAYS], int NUM_MONKEYS)
{
    // Fill array with numbers
    for (int monkeys = 0; monkeys < NUM_MONKEYS; monkeys++)
    {
        for (int days = 0; days < NUM_DAYS; days++)
       do {
            cout << " Enter food eaten (in pounds) by each monkey per day\n";
            cout << " Monkey " << (monkeys + 1)
            << ", Day " << (days + 1) << ": ";
            cin >> array[monkeys][days];
            if (array[monkeys][days] <0) // data validation for values less than zero
	            cout << "Food cannot be negative" << endl;
            } while (array[monkeys][days] <0);
        cout << endl;
        }    
}

float calcAvg (float array[][NUM_DAYS], int NUM_MONKEYS)
{
    float total = 0.0;   //Accumulator
    float average = 0;
    // Sum all food eaten (array elements) by all monkeys
    for (int monkeys = 0; monkeys < NUM_MONKEYS; monkeys++)
    {
        for (int days = 0; days < NUM_DAYS; days++)
            total += array[monkeys][days];
            average = total / 21;
            }
    return average;

    // Average amount of food eaten per day by all monkeys
    
}

/*This function finds and returns the largest value in the array whose
 address is passed to it*/
float calcMax (float array[][NUM_DAYS], int NUM_MONKEYS)
{
    // Determine the most amount eaten
    float max = array[0][0]; /* set values for comparison starting from the beginning of the array*/
    for (int monkeys = 0; monkeys < NUM_MONKEYS; monkeys++)
    {
        for (int days = 0; days < NUM_DAYS; days++)
        {   if (array[monkeys][days] > max)
            max = array[monkeys][days];
        }
    }
    return max;
    
}

/*This function finds and returns the smallest value in the array whose
 address is passed to it*/
float calcMin (float array[][NUM_DAYS], int NUM_MONKEYS)
{
    // Determine the least amount eaten
    float min = array[0][0];
    for (int monkeys = 0; monkeys < NUM_MONKEYS; monkeys++)
    {
        for (int days = 0; days < NUM_DAYS; days++)
        { if (array[monkeys][days] < min)
            min = array[monkeys][days];
        }
    }
    return min;
}


void showArray (float array[][NUM_DAYS], int NUM_MONKEYS, float average, float max, float min)//[NUM_DAYS])
{
    cout <<"Pounds of Food Eaten by Monkey and Day of Week";
    cout <<endl;
    cout <<"Monkey"<<setw(7) << "Sun" << setw(8)<< "Mon" <<setw(8)<< "Tue" <<setw(8)<< "Wed" <<setw(8)<< "Thu"<< setw(8)<< "Fri" <<setw(8)<< "Sat";
    cout <<endl;
    cout << fixed << showpoint << setprecision(1);
    
    for (int monkeys = 0; monkeys < NUM_MONKEYS; monkeys++)
    {
        cout<< "\n"<<left<<setw(10)<<(monkeys+1);
        for (int days = 0; days < NUM_DAYS; days++)
            cout<< left<< setw (7) << array[monkeys][days]<< " ";
    }
    cout << endl;
    cout << endl;
    cout << "The average amount of food eaten (in pounds) by all monkeys is: " << setw(4) << fixed << setprecision(1) << average << " pounds." << endl;
    cout << "The greatest amount of food eaten (in pounds) by one monkey this week is: " << setw(4) << fixed << setprecision(1) << max << " pounds." << endl;
    cout << "The least amount of food eaten (in pounds) by one monkey this week is: " << setw(4) << fixed << setprecision(1) << min << " pounds." << endl;
    
    cout << endl;
}
