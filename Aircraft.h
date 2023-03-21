#pragma once

//This class defines the general parameters and functions that will used by the bomber and fighter classes
class Aircraft
{
public:
	Aircraft() {} // constructor
	~Aircraft() {} // deconstructor

	virtual void move() = 0;
};