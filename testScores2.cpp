// Programmer: Matt Denton
// Program: Test Scores
// Status: Complete
// Date: 26 Nov 2013
// This program dynamically allocates an array of any size containing students 
// and their scores to calculate the average of test scores.

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;

struct TestScores 
       {
       string studentName;
       int testScore;
       };
       
void showArray(TestScores *, int);
void fillArray (TestScores [], int);                 
void sortArray(TestScores [], int);
double getAverage (double, int);

int main()
{
    TestScores *scores;      // To dynamically allocate an array
    double total = 0.0, // Accumulator
    averageResult;     // To hold average test score
    int numTests,        // To hold number of tests
    count;           // Counter
    
    // Get the number of scores
    cout << "\nEnter the number of students: ";
    cin >> numTests;
    
    // Dynamically allocate an array large enough to hold that many tests
    scores = new TestScores [numTests];
    
    // call function to fill array
    fillArray (scores, numTests);
    
    // Call function to sort array
    sortArray(scores, numTests);
    
    // Calculate the total of the scores
    for (count = 0; count < numTests; count++)
    {
        total += scores[count].testScore;
    }
    
    // Display results
    cout << left << "\nName "<< "\t\t\t" << "Score\n";
    cout << "-------------------------------\n";
    cout << endl;
    showArray(scores, numTests);
    cout << endl;
    cout << "-------------------------------\n";
    cout << "Average score: " << right << getAverage (total, numTests) << endl;
    
    // Free dynamically allocated memory
    delete [] scores;
    scores = 0;
    system ("pause");
    return 0;
}

void fillArray (TestScores scores[], int numTests)
{
     
     // Get the student name and their individual scores
    cout << "\nEnter the test scores:\n";
    for (int count = 0; count < numTests; count++)
    {   
        cin.ignore();
        cout << "Student name: ";
        getline(cin, scores[count].studentName);
        while (scores[count].studentName.length() > 30)
        {
            cout << "Invalid name length. Enter a name within 30 characters." << endl;
            cout << "Student name: ";
            getline(cin, scores[count].studentName);
        }
        cout << scores[count].studentName << "'s test score: ";
        cin >> scores[count].testScore;
        while (scores[count].testScore < 0 || scores[count].testScore > 105)
        {
            cout << "Invalid test score. Enter only positive test scores." << endl;
            cout << scores[count].studentName << "'s test score: ";
            cin >> scores[count].testScore;
        }
        
    }
 }
 
// sort array in ascending order

void sortArray(TestScores array[], int size)
{
    TestScores temp;
    bool swap;
    
    do
    {
        swap = false;
        for (int count = 0; count < (size - 1); count++)
        {
            if (array[count].testScore > array[count + 1].testScore)
            {
                temp = array[count];
                array[count] = array[count + 1];
                array[count + 1] = temp;
                swap = true;
            }
        }
    }
    while (swap);
}

// Calculate the average of the test scores
double getAverage (double total, int numTests)
{return total / numTests;}
       
       
//this function uses pointer notation
//the structure pointer operator accesses members of the struct
void showArray(TestScores *array, int size)
{
    for (int count = 0; count < size; count++)
    {    cout << left << setw(18) << array->studentName << " "
        << right << setw (12) << array->testScore << endl;
        array++;
    }
    cout << endl;
}
