// Program written by Tommy Trinh
// April 29
// this program uses recursion to calculate temperature and
// display it in a table
#include <iostream>
#include <iomanip>
using namespace std;

// global constants
const double MIN_TEMP = -40.0;
const int INCREMENT = 5;

// function prototypes
void header();			// display program information
void calcTemp(double);	// calculate temperature

int main()
{
	// declare variables
	double sTemp;	// starting temp

	// show program details
	header();
	bool validInput = false;
	// ask for starting temp
	do
	{
		cout << "Enter the starting temperature in degrees Celsius: ";
		cin >> sTemp;
		if (sTemp < MIN_TEMP)
			cout << "Error - please enter a value greater than " << MIN_TEMP << "!\n";
		else if (cin.fail())
		{
			cout << "Error - Input must be numeric\n";
			cin.clear();
			cin.ignore();
		}
		else
		{
			validInput = true;
		}
	} while (validInput==false);

	// show temp chart
	cout << "\nTemperature Conversion Chart\n"
		<< "------------------------------\n\n";
	cout << setw(7) << "Celsius" << setw(12) << "Fahrenheit" << setw(11) << "Kelvin\n";
	calcTemp(sTemp);

	return 0;
}

// display program information to user
void header()
{
	cout << "\t\t\tCMSY 171 Lab 9\n"
		<< "Copyright 2024 - Howard Community College All rights reserved; "
		<< " Unauthorized duplication prohibited.\n\n"
		<< "\t\tWelcome to CMSY-171 Temperature Conversion Program\n\n";
}

void calcTemp(double temp)
{
	double fTemp = temp,	// used to calculate fahrenheit
		kTemp = temp;		// used to calculate kelvin

	cout << fixed << setprecision(1) << showpoint;
	if (temp < MIN_TEMP)	// base case
	{
		// goodbye message
		cout << "\n\nThank you for using the program\n";
	}
	else					// recursive cases
	{
		cout << setw(6) << temp << setw(10) << ((static_cast<double>(9) / 5 * fTemp) + 32)
			<< setw(13) << kTemp + 273.15 << endl;
		calcTemp(temp - INCREMENT); // recursive call
	}

}