#pragma once

#include <iostream>

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
				// Set the value of each element
				this->Board[i][j] = ' ';
			}
		}
	}

	~GameBoard() {}	// deconstructor

	// this function prints the current game board
	void print_board()
	{
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

	// this function updates the game board grid
	void update_board()
	{

	}

private:
	char Board[7][16];
};