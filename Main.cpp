#include <iostream>
#include <string>
#include <sstream>
#include <istream>
using namespace std;

// Declaration of function processStacks
void processStacks(int *a);
// Declaration of function printSmallValues

// Declaration of function printLargeValues


int main()
{
	int cap = 0;

	cout << "Enter max number of integers: ";	
	cin >> cap;

	int *a = new int[cap] ;

	// declare any needed variables
	
	// call to function processStacks

	// call to function printSmallValues

	// call to function printLargeValues

	// what else?

	cout << endl;
	system("Pause");
	return 0;
}

// Definition of function processStacks
void processStacks(int *a)
{
	string input;
	cout << "Enter intergers (-1 to quit): ";
	getline(cin, input);

	istringstream ss(input);
	string smallStacks = "";
	string bigStacks; "";

	int num;

	while (ss >> num)
	{
		ostringstream convert;
		if (num == -1)
		{
			break;
		}
		else if (num <= 1000)
		{
			convert << num;
			smallStacks += convert.str();
		}
		else
		{
			convert << num;
			bigStacks += convert.str();
		}
	}
}

// Definition of function printSmallValues
void printSmallValues(int *a)
{

}
// Definition of function printLargeValues
