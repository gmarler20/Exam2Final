// I affirm that all code below was written by solely me, Griffen Marler and that any help I received adhered to the rules stated for this exam. 

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Runner
{

public:
	// Default empty runner
	Runner() {
		firstname = "";
		lastname = "";
		pace = 0;
	}

	// Overload constructor
	Runner(string x, string y, int z) {
		firstname = x;
		lastname = y;
		pace = z;
	}

	string get_firstname() 
	{
		return firstname;
	}
	
	string get_lastname()
	{
		return lastname;
	}

	int get_pace()
	{
		return pace;
	}


private:
	string firstname;
	string lastname;
	int pace;
	

};

void fillVector(vector<Runner>& newRun) {
	string fname;
	string lname;
	int time;
fstream input("registrants.txt");
if (input.fail())
{
	cout << "File was invalid " << endl;

}

while (input >> fname >> lname >> time) {

	Runner newRunner(fname, lname, time);
	// Adding new runner into the end of the vector until the file runs out of data to read
	newRun.push_back(newRunner);

}
}

void PrintVector(vector <Runner>& newRun) {
	for (int i = 0; i < newRun.size(); i++)
	{
		cout << newRun[i].get_firstname() << " " << newRun[i].get_lastname() << " " << newRun[i].get_pace() << " " << endl;
	}
}

/* The following function is responsible for writing runners to files based on the table
given on the exam 2 sheet. The runners are put into the correct files, however they are not in
ascending order because I never got my sort function to work. */
void WritetoFile(vector <Runner>& newRun) {
	// ofstream because we are outputting a new file
	ofstream white;
	// Open a new file with the given name "white"
	white.open("white.txt");
		for (int i = 0; i < newRun.size(); i++) {
			// Output all the data within the given pace range. 
			if (newRun[i].get_pace() >= 0 && newRun[i].get_pace() <= 360) {
				white << newRun[i].get_firstname() << " " << newRun[i].get_lastname() << " " << newRun[i].get_pace() << endl;
		}

		}
		// Make sure we close it off before moving to the next file. 
		// The rest of the code for this function is very similar to eachother,
		// the only things that change are the filename and pace range. 
					white.close();

	ofstream yellow;
	yellow.open("yellow.txt");
	for (int a = 0; a < newRun.size(); a++) {
		if (newRun[a].get_pace() >= 361 && newRun[a].get_pace() <= 420) {
			yellow << newRun[a].get_firstname() << " " << newRun[a].get_lastname() << " " << newRun[a].get_pace() << endl;
		}

	}

	yellow.close();

	ofstream green;
	green.open("green.txt");
		for (int b = 0; b < newRun.size(); b++) {
			if (newRun[b].get_pace() >= 421 && newRun[b].get_pace() <= 480) {
				green << newRun[b].get_firstname() << " " << newRun[b].get_lastname() << " " << newRun[b].get_pace() << endl;
			}

		}

		green.close();

		ofstream orange;
		orange.open("orange.txt");
			for (int c = 0; c < newRun.size(); c++) {
				if (newRun[c].get_pace() >= 481 && newRun[c].get_pace() <= 540) {
					orange << newRun[c].get_firstname() << " " << newRun[c].get_lastname() << " " << newRun[c].get_pace() << endl;
				}

			}

			ofstream blue;
			blue.open("blue.txt");
			for (int d = 0; d < newRun.size(); d++) {
				if (newRun[d].get_pace() >= 541 && newRun[d].get_pace() <= 600) {
					blue << newRun[d].get_firstname() << " " << newRun[d].get_lastname() << " " << newRun[d].get_pace() << endl;
				}

			}

			ofstream lilac;
			lilac.open("lilac.txt");
			for (int e = 0; e < newRun.size(); e++) {
				if (newRun[e].get_pace() >= 601 && newRun[e].get_pace() <= 720) {
					lilac << newRun[e].get_firstname() << " " << newRun[e].get_lastname() << " " << newRun[e].get_pace() << endl;
				}

			}
			lilac.close();

			ofstream red;
			red.open("red.txt");
			for (int f = 0; f < newRun.size(); f++) {
				if (newRun[f].get_pace() >= 721 && newRun[f].get_pace() <= 1200) {
					red << newRun[f].get_firstname() << " " << newRun[f].get_lastname() << " " << newRun[f].get_pace() << endl;
				}

			}
			
}

void sortVector(vector <Runner>& newRun) {
	int currentMin = 0;

	for (int i = 0; i < newRun.size(); i++) {

		int currentMin = newRun[i].get_pace();
		int currentMinIndex = i;

		for (int j = i + 1; i < newRun.size() - 1; i++)
		{
			// if the minimum is greater than the next item in the vector
			if (currentMin > newRun[j].get_pace())
			{
				// then the new current minimum is the next item in the vector
				currentMin = newRun[j].get_pace();
				currentMinIndex = j;
			}
		}


	}
	// I used this to test to see if my sort function worked. 
	/*
	for (int a = 0; a < newRun.size(); a++)
	{
		cout << newRun[a].get_firstname() << " " << newRun[a].get_lastname() << " " << newRun[a].get_pace() << " " << endl;
	}*/
	
}

/* This was my second attempt at geting a sort function that worked. I actually believe this attempt was closer
than my other one, but I have commented it out because whenever I use this sort code and try to run my function
I get a Debug Assertion Failed Error. I decided to leave the function that allowed the program to run in. Expression: vector subscript out of range. */
	/*vector <Runner> temp;
	
	for (int i = 0; i <= newRun.size() - 1; i++) {

		for (int j = i + 1; j <= newRun.size() - 1; j++) {

			if (newRun[i].get_pace() > newRun[j].get_pace())
			{
				temp[i] = newRun[i];
				newRun[i] = newRun[j];
				newRun[j] = temp[i];
			}
		}
	}
}*/
	

int main()
{
	vector <Runner> Run;

	fillVector(Run);
	PrintVector(Run);
	sortVector(Run);
	WritetoFile(Run);

}

