#include "stdafx.h"
#include "Exercise.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

//Default constructor
Exercise::Exercise()
{
	name = "";
	weight = 0;
	type = "";
	time = 0;
	sets = 0;
	reps = 0;
}

//Overload constructor
Exercise::Exercise(string n, int w, string ty, int ti, int s, int r)
{
	name = n;
	weight = w;
	type = ty;
	time = ti;
	sets = s;
	reps = r;
}

/*string Exercise::getFilePath()
{
	string filePath;

	cout << "Enter the location of your file: " << endl;
	cin >> filePath;

	return filePath;
}
*/
int Exercise::getInput()
{
	cout << "Name of exercise? " << endl;
	getline(cin, name);
	cout << "What type of exercise? " << endl;
	getline(cin, type);
	cout << "What weight, resistance, or speed was used? " << endl;
	cin >> weight;
	cin.ignore();
	cin.clear();
	cout << "How much time did you do this exercise for (in minutes)? " << endl;
	cin >> time;
	cin.ignore();
	cin.clear();
	cout << "How many sets did you do? " << endl;
	cin >> sets;
	cin.ignore();
	cin.clear();
	cout << "How many reps did you do? " << endl;
	cin >> reps;

	return 0;
}

void Exercise::displayInput()
{
	cout << "Name: " << name << endl;
	cout << "Type: " << type << endl;
	cout << "Weight: " << weight << endl;
	cout << "Time: " << time << endl;
	cout << "Sets: " << sets << endl;
	cout << "reps: " << reps << endl;
}

ofstream& operator<<(ofstream &fs, Exercise *item)
{
	fs << item->name << "," << item->type << "," << item->weight << "," << item->time << "," << item->sets << "," << item->reps << endl;
	return fs;
}