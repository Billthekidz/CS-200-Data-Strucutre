/*
Tang, Paul

CS A200
November 16, 2018

Lab #4
*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Declaration of function processStacks
void processStacks(int *a,int* &small,int* &large);
// Declaration of function printSmallValues
void printSmallValues(const int*a, int* &small);
// Declaration of function printLargeValues
void printLargeValues(const int*a, int* &large);

int main()
{
	int cap = 0;

	cout << "Enter max number of integers: ";	
	cin >> cap;

	int *a = new int[cap] ;

	// declare any needed variables
	int* small = a;
	int* large = a+ cap -1;
	// call to function processStacks
	processStacks(a, small, large);
	// call to function printSmallValues
	printSmallValues(a, small);
	// call to function printLargeValues
	printLargeValues(a, large);
	// what else?

	cout << endl;
	system("Pause");
	return 0;
}

// Definition of function processStacks
void processStacks(int *a, int* &small, int* &large)
{
	int num;
	cout << "Enter intergers (-1 to quit): ";
	if (small == large)
	{
		cerr << "there is no place to insert number." << endl;
	}
	do
	{
		cin >> num;
		
		if (num != -1)
		{
			if (num <= 1000)
			{
				*small = num;
				++small;
			}
			else
			{
				*large = num;
				--large;
			}
		}

	}while (num != -1);
}

// Definition of function printSmallValues
void printSmallValues(const int*a, int* &small)
{
	cout << "Stack with small values (top): ";
	for (int* i = small; i != nullptr; i--)
	{
		cout << *i << " ";
	}
	
}
// Definition of function printLargeValues
void printLargeValues(const int*a, int* &large)
{
	cout << "Stack with large values (top): ";
	for (int* i = large; i != nullptr; i++)
	{
		cout << *i << " ";
	}
}