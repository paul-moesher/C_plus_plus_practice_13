//-----------------------------------------------------------------------------------------------------
// CS2010											Program 7							Date:4/11/18
// Paul Moesher																		Class time: 10:30
//
// Purpose:		The purpose of this program is to read data from a text file and determine miles per gallon 
//				for a few different car types.
// Input:		The input is the text file which this program will read data from about car milage. There
//				will be a function that requires the user to enter a car name and then the information about
//				that specific car will be displayed to them.
// Processing:	The program will read the data from each car (the car type and the gallons used per 100 miles)
//				then take 100 and divide it by the number to get mpg.
//	Outout:		The output will show car model, gallons used per 100 miles, and miles per gallon, as well as a
//				line of information about whatever car it is that the user has entered.


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Function declarations
int read_file(string[], double[]);
void calulate_miles_per_gallon(double[], double[], int);
void display_info(string[], double[], double[], int);
void user_question(string[], double[], int);
void sort(string[], double[], double[], int);

int main()

{
	// Define constant variable(s)
	const int size = 20; // The arrays can handle up to 20 data types

	// Define arrays
	string car_model[size]; // This array handles the car model
	double gallons[size]; // This array handles the gallons 
	double miles_per_gallon [size]; // This arrays handles miles per gallon

	// Define variable(s)
		int car_total; // The actual number of cars in the txt file 

	// Load the data into the arrays and return number of cars then call the function that reads the txt doc
		car_total = read_file(car_model, gallons);
	
	// Call the function that finds the mpg for the cars
		calulate_miles_per_gallon(gallons, miles_per_gallon, car_total);

	// Display message to the user after they enter the car type
		cout << " " << endl; // Line for space
		cout << "\t\t Vehicle Miles Per Gallon: " << endl;

	// Call the function that displays the info
		display_info(car_model, gallons, miles_per_gallon, car_total);

	// Call the fuction that asks the user to enter a question and finds the answer
		user_question(car_model, miles_per_gallon, car_total);

	// Display a message stating that the data is now sorted 
		cout << "\t Vehicles Sorted by Gallons used per 100 miles " << endl;

	// Call the function that sorts that data in descending order of gallons used
		sort(car_model, gallons, miles_per_gallon, car_total);

	// Call the function that displays the info again now that the data is sorted
		display_info(car_model, gallons, miles_per_gallon, car_total);


	system("pause");
	return 0;
}

// Function to read the data from the txt file

int read_file(string car_model[], double gallons[])
{
	ifstream open("pgm7.txt");

	int data = 0;

	if (open.is_open())

	{
		while (!open.eof())
		{
			open >> car_model[data];
			open >> gallons[data];
			data++;
		}
	}
	else

		cout << "unable to open file";
	open.close();
	return data;
	
}

// Function that calualates the miles per gallon

void calulate_miles_per_gallon(double gallons[], double miles_per_gallon[], int total)
{
	for (int i = 0; i < total; i++)

	{
		miles_per_gallon[i] = (100 / gallons[i]);
	}
}

// Function to display the data 

void display_info(string car_model[], double gallons[], double miles_per_gallon[], int total)
{
	cout <<  "\t       Paul Moesher  CS2010    10:30" << endl;
	cout << "" << endl;
	cout << "\t Model" << setw(5) << "\t Gallons used/100 miles" << setw(10) << "\t MPG" << endl;
	cout << "\t-------------------------------------------------" << endl;
	for (int i = 0; i < total; i++)

	{
		cout<< setw(15) << car_model[i]<< setprecision(2) << setw(15) << gallons[i] << setw(22) << miles_per_gallon[i] << endl;

	}
}

//  Function that searches that data to display that answer to the question that the user asks

void user_question(string car_model[], double miles_per_gallon[], int total)

{
	// Declare local variables

	double mpg = 0;
	double fin = 0;
	string model;

	// Ask the user to enter a car type

	cout << " " << endl; // Line for space
	cout << "Enter a model name to see what the miles per gallon for that model is " << endl;
	cin >> model;

	for (int i = 0; i < total; ++i)
	{
		if (car_model[i] == model)
		{
			mpg = mpg + miles_per_gallon[i];
			fin++;
		}
	}

	if (fin == 0) cout << "No " << model << " vehicles tested.";
	else
	cout << " " << endl; // Line for space
	cout << "The average miles per gallon for " << model << " vehicles tested is " << mpg / fin << " gallons.\n" << endl;
	cout << " " << endl; // Line for space
}
// Function that sorts that data in descending order

void sort(string car_model[], double gallons[], double miles_per_gallon[], int total)

{

	int max;

	for (int i = 0; i<total - 1; i++)

	{

		max = i;

		for (int j = i + 1; j<total; j++)

		{

			if (gallons[j] > gallons[max])

				max = j;

		}

		if (max != i)

		{

			string tempModel = car_model[i];

			car_model[i] = car_model[max];

			car_model[max] = tempModel;

			double tempGallonsUsed = gallons[i];

			gallons[i] = gallons[max];

			gallons[max] = tempGallonsUsed;

			double tempMilesPerGallon = miles_per_gallon[i];

			miles_per_gallon[i] = miles_per_gallon[max];

			miles_per_gallon[max] = tempMilesPerGallon;

		}

	}

}




