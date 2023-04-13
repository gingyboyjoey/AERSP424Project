#pragma once
 
#include <iostream>
#include <cstdio>
#include <vector>
#include <random>
#include <string>
#include "GameBoard.h" 
#include "Aircraft.h"
#include "Bomber.h"
#include "FighterJet.h"

using namespace std;

// This class defines functions that will run the Game. This includes if the game has started or ended, and whose 
// turn it is to make a move.
class GameManager
{
public:
	GameManager() {}	// constructor
	~GameManager() {}	// deconstructor

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

	}

    // this function runs the game
    static void runGame()
    {
        // Instantiate a GameBoard and GameManager object
        GameBoard board;
        GameManager M;

        // creates an pointer to an Aircraft object
        Aircraft* current_AC;

        int hitCounter = 0; // holds the number of aircraft that have reached the base
        int x = 0, y = 0; // intitialize player shot coordinates

        while (!M.isOver(hitCounter))
        {
            board.print_board();

            int AC_type = Aircraft::getRandomNumber(0, 1);

            // spawn in a random aircraft type of either Bomber or FighterJet
            if (AC_type == 0)
            {
                Bomber B; // spawn a Bomber object and get the pointer
                current_AC = &B;

                while (!Aircraft::isDefeated(current_AC))
                {
                    M.playerShot(x, y);
                    current_AC->move();
                    for (int i = 0; i < current_AC->location.size(); i++)
                    {
                        if (current_AC->location[i].first == x && current_AC->location[i].second == y)
                        {
                            current_AC->labels[i] = 'X';
                        }
                    }
                    
                    // update the board and print it
                    board.reset_board();
                    board.update_board(current_AC);
                    board.print_board();

                    // add a check for if the AC gets to the goal
                    if (current_AC->location[0].second == 15)
                    {
                        hitCounter = hitCounter + 1;
                        break;
                    }

                    else if (Aircraft::isDefeated(current_AC))
                    {
                        M.Score(5);
                        break;
                    }
                }

            }

            else
            {
                FighterJet F; // spawn a FighterJet object and get the pointer
                current_AC = &F;

                while (!Aircraft::isDefeated(current_AC))
                {
                    M.playerShot(x, y);
                    current_AC->move();
                    for (int i = 0; i < current_AC->location.size(); i++)
                    {
                        if (current_AC->location[i].first == x && current_AC->location[i].second == y)
                        {
                            current_AC->labels[i] = 'X';
                        }
                    }

                    // update the board and print it
                    board.reset_board();
                    board.update_board(current_AC);
                    board.print_board();

                    // check if aircraft has reached the goal
                    if (current_AC->location[0].second == 15)
                    {
                       hitCounter = hitCounter + 1;
                        break;
                    }

                    // check of the aircraft is defeated
                    else if (Aircraft::isDefeated(current_AC))
                    {
                        M.Score(10);
                        break;
                    }
                }
            }
        } 
    }

    // this function takes the player's input and checks if it is valid
    void playerShot(int& x, int& y) 
    {
        string input;
        bool validInput = false;
        while (!validInput) 
        {
            cout << "Enter the coordinates of your shot (e.g. A3): ";
            cin >> input;
            if (input.length() == 2 && isalpha(tolower(input[0])) && isdigit(input[1])) 
            {
                x = tolower(input[0]) - 'a'; // convert letter to corresponding index (0-15)
                y = input[1] - '1'; // convert number to corresponding index (0-8)
                if (x >= 0 && x < 16 && y >= 0 && y < 7) 
                {
                    validInput = true;
                }
            }
            if (!validInput) 
            {
                cout << "Invalid input. Please enter a valid coordinate within the 16x9 grid." << endl;
            }
        }
    }


	// this function determines whether the game has ended or not
	bool isOver(int Counter)
	{
        if (Counter == 5)
        {
            cout << "FINAL SCORE: " << this->score;
            return true;
        }
        else
        {
            return false;
        }
	}


    // this function adds up the score and prints the total score if the game has ended
    void Score(int points)
    {
        this->score = this->score + points;
    }


private:
    int score = 0;
};