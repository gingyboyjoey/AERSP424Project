#pragma once

#include <vector>
#include "Aircraft.h"
#include "GameManager.h"

using namespace std;

// This class defines a fighter jet that is inherited from the Aircraft class
class FighterJet : public Aircraft
{
public:
	// constructor and deconstructor here
	FighterJet()
	{
		startrow = Aircraft::getRandomNumber(0, 6); // random starting row
		startcol = 1; // starting column of the nose is always 1

		// sizes the location vector of pairs and labels vector
		location.resize(2);
		labels.resize(2);

		// set the starting location of the bomber
		location[0] = make_pair(startrow, startcol);
		location[1] = make_pair(startrow, startcol - 1);

		// set the initial labels
		labels[0] = 'F';
		labels[1] = 'F';
	}

	~FighterJet() {}

	// this function moves the fighter jet aircraft. Movement is two to three spaces forward and left or right one space
	virtual void move() override
	{
		int newRow = Aircraft::getRandomNumber(0,1);  // random integer that is either 0 or 1

		// move the fighter jet up one space if newRow equals 0 and the fighter jet will remain in bounds
		if (newRow == 0 && location[0].first != 0)
		{
			for (int i = 0; i < 2; i++)
			{
				location[i].first = location[i].first - 1; // shifts the row of each element in the vector of pairs
			}
		}

		// move the fighter jet down one space if newRow equals 1 and the fighter jet will remain in bounds
		else if (newRow == 1 && location[0].first != 6)
		{
			for (int i = 0; i < 2; i++)
			{
				location[i].first = location[i].first + 1; // shifts the row of each element in the vector of pairs
			}
		}

		// always move the fighter jet to the right 2 spaces
		for (int i = 0; i < 2; i++)
		{
			location[i].second = location[i].second + 2; // shifts the column of each element in the vector of pairs
		}
	}

private:
	int startrow, startcol;
};
