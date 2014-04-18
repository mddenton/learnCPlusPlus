//
//  main.cpp
//  Lone Star Test
//
//  Created by Matthew Denton on 11/16/13.
//  Copyright (c) 2013 Matthew Denton. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;


const int SIZE = 15;

//Function prototypes
int searchWeightArray (int [], int, int);
int getLargest (int, int, int);
int getGirth (int, int, int, int);

string pkgStatus (int, int);
void printPackageData (int, string, int, float);
void printTransNum (int, int);
void printPkgAcceptReject (int, int);

int main ()
{
    
	//declare arrays
	int weight[SIZE] = {1, 2, 3, 5, 7, 10, 13, 16, 20, 25, 30, 35, 40, 45, 50};
	double shipping[SIZE] = {1.50, 2.10, 4.00, 6.75, 9.90, 14.95, 19.40, 24.40, 27.30, 31.90, 38.50, 43.50, 44.80, 47.40, 55.20};
    
	//declare variables
	int transNum = 0;				//number of transactions
	int index;
    int packageWeight=0;      //the package weight
	int length = 0;						//the package length
	int width = 0;						//the package width
	int height = 0;						//the package height
	int girth = 0;						//the package girth
	int largest = 0;					//the package's largest side
    float packageCost;
	string status = " ";			//returned package status
    int numGood = 0;
    int numBad  = 0;
    
    while(true)//an infinite loop which repeats until pkgWeight = -1
    {
    	cout <<"Enter package weight in pounds and 3 separate dimensions in inches: "; // get input
    	cin >> packageWeight; //the first user input
        if (packageWeight == -1)
        {
            break;//stop program and print accepted and rejected transactions
        }
        cin >> length >> width >> height; //the sides of package
        
        //user validation still allows for negative numbers other than -1
    	if ((packageWeight <= 0)||(length <= 0)||(width <= 0)||(height <= 0))
    	{
    		cout << "Error: package dimensions must be greater than 0" << endl;
    		cout << "Please re-enter transaction" << endl;
    		continue;
    	}
    	// debug
        //cout << "you entered:" << endl << packageWeight << endl << length << endl << width << endl << height << endl;
        
    	// add 1 for each transaction
    	transNum++;
    	
        //get the largest number
        largest = getLargest(length, width, height);
        
        //calculate the girth
        girth = getGirth (length, width, height, largest);
        
        //accept or reject package based on girth and package weight
    	status = pkgStatus (girth, packageWeight);
    	
    	// # of accepted and rejected packages
    	// originally I had this in a separate function but less complicated to do in main
    	// packageCost is -1 if status rejected so that if else in print statement will 
    	//print a hyphen for package cost when status rejected
    	if (status == "Rejected")
        {
            numBad++;
            packageCost = -1;
        }
        else 
        {
            numGood++;
            
            //if package size accepted then
            //search the weight array for memory location
    	    index = searchWeightArray (weight, SIZE, packageWeight);
    	    // and use the placment of index in the weight array
            //to find the corresponding location of package cost in the shipping array
    	    packageCost = shipping[index];
        }//print the package data each time until user inputs -1
        printPackageData (transNum, status, packageWeight, packageCost);
    	
    }
    //number of accepted and rejected packages printed upon termination of program.
    printPkgAcceptReject (numGood, numBad);
    
    system ("pause");
    return 0;
    
}//end of main

int searchWeightArray (int weight[], int size, int packageWeight)
{
	//search the arrays for memory location
	int index = 0;					//holder variable for the index location of weight compared to shipping charge
	for (int i = 0; i < 15; i++)
	{
		if (packageWeight == weight[i])
		{
			index = i;
			break;
		}
		else if (packageWeight > weight[i])
			continue;
		else
		{
			packageWeight = weight[i];
			index = i;
			break;
		}
		return index;
	}//end for
	
}

//This function gets that largest side for the box for the girth calculation
int getLargest(int side1, int side2, int side3)
{
    int largest=0;
    if (side1 > side2 && side1 > side3)
        largest = side1;
    else if (side2 > side1 && side2 > side3)
        largest = side2;
    else if (side3 > side1 && side3 > side2)
        largest = side3;
    return largest;
}

int getGirth (int length, int width, int height, int largest)
{
    //calculate the girth
    int girth;
    girth = 2 * (length + width + height - largest);
	return girth;
}


//This function determines the package status and
//determines package status
string pkgStatus (int girth, int packageWeight)
{
    string status;
    if ((girth > 60)||(packageWeight > 50))
    {
        status = "Rejected";
	}
    else {
        status = "Accepted";
	}//end if
    return status;
}

//for each package processed, print the following output before accepting new package data
void printPackageData (int transNum, string status, int packageWeight, float packageCost)
{
	cout << left << setw(11) << "Transaction" << ":" << right << setw(10)<< transNum << endl;
	cout << left << setw(11) << "Status" << ":" << right << setw(10) << status << endl;
	cout << left << setw(11) << "Weight" << ":" << right << setw(10) <<packageWeight << endl;
	if (packageCost == -1)//in main, the package cost was made = to -1 when transaction status = rejected 
        cout << left << setw(11) << "Cost " << ":" << right << setw(10) << "-" << endl;
    else
	    cout << left << setw(11) << "Cost " << ":" << right << setw(10) << packageCost << endl;
}

//after user enters -1 to end program print the number of accepted and rejected packages
void printPkgAcceptReject (int numGood, int numBad)
{
    cout << "Number of Accepted packages: " << numGood << endl;
    cout << "Number of Rejected packages: " << numBad << endl;
}



