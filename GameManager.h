#pragma once
 
#include <iostream>
#include <cstdio>
#include "GameBoard.h" 
#include "Aircraft.h"
#include "Bomber.h"
#include "FighterJet.h"
#include <cstdlib>
#include <time.h>

using namespace std;
// This class defines functions that will run the Game. This includes if the game has started or ended, and whose 
// turn it is to make a move.
class GameManager
{
public:
	GameManager() {}	// constructor
	~GameManager() {}	// deconstructor

    int hitCounter = 0; // holds the number of aircraft that have reached the base

	// this function starts the game
	static void start()
	{
        cout << "                              ._\n"
            "                              |* ;\n"
            "            `*-.              |\"\":\n"
            "             \\  \\             |\"\" \n"
            "              .  \\            |   :     \n"
            "              `   \\           |      \n"
            "               \\   \\          |    ;               +.\n"
            "                .   \\         |                   *._`-.\n"
            "                `    \\        |     :          .-*'  `. `.\n"
            "                _\\    \\.__..--**--...L_   _.-*'      .'`*'\n"
            "               /  `*-._\\   -.       .-*\"*+._       .'\n"
            "              :        ``*-._*.     \\      _.   .'\n"
            "          .-*'*-.       ;     `.    \\    /   `.'\n"
            "      .-*'  _.-*'.     .-'       `-.  `-.:   _.'`-.\n"
            "   +*' _.-*'      `..-'             `*-. `**'      `-.\n"
            "    `*'          .-'      ._            `*-._         `.\n"
            "              .-'         `.`-.____..+-**\"\"'         .*\"`.\n"
            "         ._.-'          _.-*'':$$$;._$              /     `.\n"
            "      .-'  `.      _.-*' `*-.__ $    `\"**--..__    :        `.\n"
            ".'..-'       \\_.-*'                            `\"**--..___.-*'\n"
            "`. `.    _.-*'\n"
            "  `. `:*'\n"
            "    `. `.\n"
            "      `*\n";

        cout << "  ___  ___________  ______  ___  ___________ \n"
            << " / _ \\|_   _| ___ \\ | ___ \\/ _ \\|_   _|  _  \\\n"
            << "/ /_\\ \\ | | | |_/ / | |_/ / /_\\ \\ | | | | | |\n"
            << "|  _  | | | |    /  |    /|  _  | | | | | | |\n"
            << "| | | |_| |_| |\\ \\  | |\\ \\| | | |_| |_| |/ / \n"
            << "\\_| |_/\\___/\\_| \\_| \\_| \\_\\_| |_/\\___/|___/\n";

        cout << "\n\nPress enter to start...  ";
        cin.get();

        #ifdef _WIN32
                system("cls"); // clear the terminal (Windows)
        #else
                system("clear"); // clear the terminal (Linux/MacOS)
        #endif

        cout << " Welcome to Air Raid. Your mission is to defend the base from enemy aircraft. The enemy has bombers that move \n"
            " slower but take more hits, and fighter jets that move quick but take less hits. If five aircraft reach the base\n "
            "we'll be forced to surrender...\n\n"
            " Good luck soldier! We're all counting on you...\n";

        cin.get();

        #ifdef _WIN32
                system("cls"); // clear the terminal (Windows)
        #else
                system("clear"); // clear the terminal (Linux/MacOS)
        #endif

        GameBoard board;
        board.print_board();
	}

	// this function determines whether the game has ended or not
	bool isOver(int Counter)
	{
        if (Counter == 5)
        {
            return true;
        }
        else
        {
            return false;
        }
	}

	// this function spawns in a random new aircraft (STILL NEEDS WORK!!)
	void spawn_AC()
	{
        srand(time(0));
        int AC_type = rand() % 2;

        if (AC_type == 0)
        {
            Bomber B;
        }

        else
        {
            FighterJet F;
        }
	}



    // this function adds up the score and prints the total score if the game has ended
    void Score(int points)
    {
        this->score = this->score + points;

        if (isOver(hitCounter))
        {
            cout << "FINAL SCORE: " << this->score;
        }
    }

private:
    int score = 0;
};