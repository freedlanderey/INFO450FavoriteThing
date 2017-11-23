// ExTrackerApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>	
#include "Exercise.h"
#include <fstream>

using namespace std;

const int LISTSIZE = 50;

int main()
{
	int numInputs;
	int i;
	int count = 0;
	char response = 'Y';
	Exercise **myEntry;
	string filePath = "";

	myEntry = new Exercise*[LISTSIZE];

	cout << "Welcome to my exercise tracker!" << endl;

	cout << "Enter the location of your file: " << endl;
	getline(cin, filePath);

	// read from a file - get saved inventory items
	ifstream infile(filePath);
	if (infile.good())
	{
		while (!infile.eof())
		{
			string name, weight, type, time, sets, reps;
			getline(infile, name, ',');
			if (name.length())
			{
				getline(infile, name, ',');
				getline(infile, weight, ',');
				getline(infile, type, ',');
				getline(infile, time, ',');
				getline(infile, sets, ',');
				getline(infile, reps, '\n');
				myEntry[count] = new Exercise(name, stoi(weight), type, stoi(time), stoi(sets), stoi(reps));
				count++;
			}
		}
	}

	// enter more???
	cout << "you have " << count << " records.  More??? \n" << endl;
	cin >> response;
	cin.ignore();
	cin.clear();

	// get inventory items from user
	while (response == 'Y' || response == 'y')
	{
		myEntry[count] = new Exercise();
		if (myEntry[count]->getInput() == 0)
			count++;

		cout << "Another one???" << endl;
		cin >> response;
	}

	// now that we have array populated w/ object, show them
	for (i = 0; i < count; i++)
	{
		myEntry[i]->displayInput();
	}

	//Save to a File
	ofstream outfile(filePath);
	if (!outfile.good())
	{
		cout << "ERROR - cant open file for output! " << endl;
		return -1;
	}
	// printing to console
	for (i = 0; i < count; i++)
	{
		outfile << myEntry[i];
	}

	// cleaning up
	for (i = 0; i < count; i++)
	{
		delete myEntry[i];
	}
	delete myEntry;

	return 0;
}

