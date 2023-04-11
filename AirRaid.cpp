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
	GameManager::runGame();	// runs the game
	
	return 0;
}