#pragma once

#include <vector>
#include <random>
#include "Aircraft.h"
#include "GameManager.h"

using namespace std;

// This class defines a bomber that is inherited from the Aircraft class
class Bomber : public Aircraft
{
public:
	// constructor and deconstructor here
	Bomber()
	{
		startrow = Aircraft::getRandomNumber(1, 5); // random starting row from 1 to 5
		startcol = 3;

		// sizes the location vector of pairs and labels vector
		location.resize(6);
		labels.resize(6);

		// set the starting location of the bomber
		location[0] = make_pair(startrow, startcol);
		location[1] = make_pair(startrow-1,startcol-1);
		location[2] = make_pair(startrow,startcol-1);
		location[3] = make_pair(startrow+1,startcol-1);
		location[4] = make_pair(startrow,startcol-2);
		location[5] = make_pair(startrow,startcol-3);

		// set the initial labels
		for (int i = 0; i < 6; i++)
		{
			labels[i] = 'B';
		}
	}

	~Bomber() {} // deconstructor

	// this function moves the Bomber aircraft. Movement is always two spaces to the right and one space up or down
	virtual void move() override
	{
		int newRow = Aircraft::getRandomNumber(0,1);

		// move the bomber up one space if it will remain in bounds
		if (newRow == 0 && location[0].first != 1)
		{
			for (int i = 0; i < 6; i++)
			{
				location[i].first = location[i].first - 1;
			}
		}

		// move the bomber down one space if it will remain in bounds
		else if (newRow == 1 && location[0].first != 5)
		{
			for (int i = 0; i < 6; i++)
			{
				location[i].first = location[i].first + 1;
			}
		}

		// always move the bomber to the right 1 space
		for (int i = 0; i < 6; i++)
		{
			location[i].second = location[i].second + 1;
		}
	}

private:
	int startrow, startcol;
};