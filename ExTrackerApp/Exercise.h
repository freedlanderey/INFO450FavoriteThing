#pragma once
#include "stdafx.h"
#include <string>

using namespace std;

class Exercise
{
private:
	string name;
	int weight;
	string type;
	int time;
	int sets;
	int reps;

public:
	int getInput();
	void displayInput();
	
	//constructors
	Exercise();
	Exercise(string n, int w, string ty, int ti, int s, int r);

	friend ofstream& operator<<(ofstream &fs, Exercise *item);
};