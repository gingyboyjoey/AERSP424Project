#pragma once

#include <array>
#include "Aircraft.h"
// This class defines a bomber that is inherited from the Aircraft class
class Bomber : public Aircraft
{
public:
	// constructor and deconstructor here
	Bomber()
	{

	}

	// this function moves the Bomber aircraft. Movement is always two spaces forward and one space left or right
	virtual void move() override
	{

	}
};