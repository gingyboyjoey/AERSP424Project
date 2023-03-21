#pragma once

#include <iostream>
using namespace std;
// This class defines the game board that will be played on
class GameBoard
{
public:
	GameBoard() {}	// constructor
	~GameBoard() {}	// deconstructor

	// this function prints the current game board
	static void print_board()
	{
       const int ROWS = 8;
       const int COLS = 16;

            char board[ROWS][COLS];

            // initialize the board with empty spaces
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    board[i][j] = ' ';
                }
            }

            // print the board
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }

         
        }

	};
