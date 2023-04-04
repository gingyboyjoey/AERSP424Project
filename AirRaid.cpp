/*

AERSP 424 Project: AIR RAID
Group Members: Darrian Petrakis, Joeseph Peters, and Jordon Zakarevicz

*/

#include <iostream>
#include "GameManager.h"
#include "Bomber.h"

#include<vector>

using namespace std;

int main()
{
	GameManager::start();	// starts the game
	Bomber b1, b2;
	b1.x = 1;
	b1.y = 2;
	b2.x = 3;
	b2.y = 4;
	//std::cout << b1.x << b1.y << b2.x << b2.y << std::endl;

	std::vector<int> v = { 1,2,3,4 };
	v.erase(v.end()-1);
	for (int i = 0; i < v.size(); i++) {
	std:cout << v[i] << std::endl;
	}
	return 0;
}