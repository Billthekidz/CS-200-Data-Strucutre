/*
Tang, Paul

CS A262
November 5, 2018

Lab #3
*/

#include<iostream>
#include<string>
#include<fstream>


using namespace std;

int getN(int p, int q)
{
	return p * q;
}

bool isPrime(int number)
{
	for (int i = 2; i <= number/2; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	return true;
}

int gcd(int a, int b)
{
	if (a == 0)
	{
		return b;
	}
	return gcd(b % a, a);
}

bool relativelyPrime(int a, int b)
{
	if (gcd(a, b) == 1)
	{
		return true;
	}
	return false;
}

int main()
{
	
	cout << "------------------------------" << endl;
	cout << "RSA Encryption" << endl;
	cout << "------------------------------" << endl;
	cout << "You will implement an encryption/decryption program using RSA encryption."
		 << "The input to theprogram will be read from a file.  The output will be printed to the console." << endl;
	cout << "------------------------------" << endl;
	

	int p, q = 0;
	int e = 0;
	int d = 0;


	cout << "Enter the values for p and q:  ";
	cin >> p >> q;
	while (!isPrime(p) || !isPrime(q))
	{
		cout << "p and q must be prime numbers" << endl;
		cout << "Enter the values for p and q:  ";
		cin >> p >> q;
	}

	cout << "Enter the value for e: ";
	cin >> e;
	while (e < 0)
	{
	cout << "e cannot be negative" << endl;
	cout << "Enter the value for e: ";
	cin >> e;
	}
	while ((gcd((p - 1)*(q - 1), e)) != 1)
	{
		cout << "e and φ must be relatively prime." << endl;
		cout << "Enter the value for e: ";
		cin >> e;
	}

	cout << "Enter the value for d: ";
	cin >> d;
	while (d < 0)
	{
		cout << "d must be positive" << endl;
		cout << "Enter the value for d: ";
		cin >> d;
	}
	while ((e*d % ((p - 1)*(q - 1))) != 1)
	{
		cout << "d must be the multiplicative inverse of e" << endl;
		cout << "e*d mod phi = " << (e*d % ((p - 1)*(q - 1))) << endl;
		cout << "Enter d again: ";
		cin >> d;
	}

	char answer;
	cout << "Do you want to encrypt(E) or decrypt(D)? ";
	cin >> answer;
	while (answer != 'E' && answer != 'D')
	{
		cout << "Your input is invalid." << endl;
		cout << "Do you want to encrypt(E) or decrypt(D)";
		cin >> answer;
	}

	string fileName;
	cout << "Enter the input filename: ";
	cin >> fileName;

	ifstream ins(fileName);
	if (!ins)
	{
		cerr << "Could not open the file." << endl;
		return 0;
	}
	ofstream out("results.txt");

	if (answer == 'E')
	{
		char ch;
		while (ins.get(ch))
		{
			int convert = static_cast<int>(ch);
			int temp = convert;
			for (int i = 1; i < e; i++)
			{
				convert = (convert * temp) % (getN(p, q));
			}
			out << convert << " ";
		}
	}
	else
	{
		int num;
		while (ins >> num)
		{
			int temp = num;
			for (int i = 1; i < d; i++)
			{
				num = (num*temp) % (getN(p, q));
			}
			char ch = static_cast<char>(num);
			out << ch;
		}
	}

	out << endl;

	ins.close();
	out.close();

	system("Pause");
	return 0;
}