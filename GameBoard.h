#pragma once

#include <iostream>
#include "Aircraft.h"

using namespace std;

// This class defines the game board that will be played on
class GameBoard
{
public:
	// constructor
	GameBoard()
	{
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				// Set the value of each element to ' '
				this->Board[i][j] = ' ';
			}
		}
	}

	~GameBoard() {}	// deconstructor

	// this function prints the current game board
	void print_board()
	{
		// defines the column labels 
		char columnLabels[16] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P' };

		for (int i = 0; i < 8; i++)
		{

			cout << "|+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+|" << endl;

			if (i != 7)
			{
				for (int j = 0; j < 16; j++)
				{
					if (j == 0)
					{
						cout << "||";
					}

					cout << this->Board[i][j] << "|";

					if (j == 15)
					{
						cout << "| " << i + 1 << endl;
					}
				}
			}
		}

		for (int i = 0; i < 16; i++)
		{
			if (i == 0)
			{
				cout << "  " << columnLabels[i];
			}

			else
			{
				cout << " " << columnLabels[i];
			}

		}

		cout << "\n\n" << endl;
	}

	// this function resets the board 
	void reset_board()
	{
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				// Set the value of each element to ' '
				this->Board[i][j] = ' ';
			}
		}
	}

	// this function updates the game board grid
	void update_board(Aircraft* a)
	{
		for (int k = 0; k < a->location.size(); k++)
		{
			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					// check if the pair in the location vector of pairs equals the position pair in the board
					if (a->location[k].first == i && a->location[k].second == j)
					{
						this->Board[i][j] = a->labels[k]; // change the char at the position in the board to the char in label
					}
				}
			}
		}
	}

private:
	char Board[7][16];
};