#pragma once

#include <vector>
#include <random>
#include "GameManager.h"

using namespace std;

//This class defines the general parameters and functions that will used by the bomber and fighter classes
class Aircraft
{
public:
	Aircraft() {} // constructor
	~Aircraft() {} // deconstructor


	// creates a pure virtual function for movement of the two aircraft types
	virtual void move() = 0;


	// this function checks to see if an aircraft has been defeated
	static bool isDefeated(Aircraft* a)
	{
		int hits = 0;
		for (int i = 0; i < a->location.size(); i++)
		{
			// checks the chars inside of the labels vector 
			if (a->labels[i] == 'X')
			{
				hits = hits + 1; // adds one to hits if the char is 'X'
			}
		}

		// fighter jets are defeated in 1 hit
		if (a->location.size() == 2 && hits == 1)
		{
			return true;
		}

		// bombers are defeated in 3 hits
		else if (a->location.size() == 6 && hits == 3)
		{
			return true;
		}

		return false;
	}


	// this function generates a random number 
	static int getRandomNumber(int lower, int upper)
	{
		// Use a random device to generate a seed value
		random_device rd;

		// Use a Mersenne Twister engine for random number generation
		mt19937 mt(rd());

		// Use a uniform distribution to generate integers in a specified range
		uniform_int_distribution<int> dist(lower, upper);

		// Generate a random number
		return dist(mt);
	}


	vector<pair<int, int>> location; // holds the position of each aircraft
	vector<char> labels; // holds the char label for each part of the aircraft
};