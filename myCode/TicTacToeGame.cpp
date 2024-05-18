/*
 * TicTacToeGame.cpp
 *
 *  Created on: Nov 10, 2023
 *      Author: zakis
 */

/**
 * @file TicTacToeGame.cpp
 * @brief Implementation file for the TicTacToeGame class.
 *
 * This file contains the implementation of the TicTacToeGame class, which
 * represents the Tic Tac Toe game within the gaming portal.
 */

#include <iostream>
#include <utility>

#include "TicTacToeGame.h"
#include "TicTacToeBotPlayer.h"
#include "TicTacToeHumanPlayer.h"

using namespace std;

/**
 * @brief Constructor for the TicTacToeGame class.
 * Initializes the Tic Tac Toe game by setting its name and creating
 * instances of the game board and players based on the provided player types and names.
 * @param playerTypes A vector containing the player types (Human or Bot).
 * @param PlayerNames A vector containing the player names.
 */
TicTacToeGame::TicTacToeGame(vector<Player_Type_t> playerTypes,
		vector<string> PlayerNames) {
    /* Set the game name to Tic Tac Toe */
    gameName = Game_t::TIC_TAC_TOE;

    /* Create an instance of the Tic Tac Toe game board */
    ticTacToeBoard = new TicTacToeBoard();

    /* Create instances of players based on the provided player types and names */
    for (int i = 0; i < 2; ++i) {
        if (playerTypes[i] == HUMAN) {
            players.push_back(new TicTacToeHumanPlayer(PlayerNames[i],
            		static_cast<Player_t>(i), ticTacToeBoard));
        } else if (playerTypes[i] == BOT) {
            players.push_back(new TicTacToeBotPlayer(PlayerNames[i],
            		static_cast<Player_t>(i), ticTacToeBoard));
        }
    }
}

/**
 * @brief Starts the Tic Tac Toe game.
 * Plays the game for 9 rounds, allowing each player to make a move in each round.
 * Checks for a winner or a draw after each move.
 */
void TicTacToeGame::play() {
	/* Display a message indicating the start of the game */
    cout << endl << "The game of Tic Tac Toe begins " << endl << endl;

    /* Print the initial state of the game board */
    ticTacToeBoard->printBoard();

    /* Play the game for a maximum of 9 rounds */
    for (int i = 0; i < 9; ++i) {
    	/* Display a separator between rounds */
        cout << endl << "-------------------------------------" << endl;

        /* Display the current round number */
        cout << endl << "Round " << i + 1 << endl;

        /* Allow the current player to make a move which also checks for a game
         * over condition
         */
        bool gameOver = players[i % 2]->move();

        /* If there is a winner, display the winner and the final state of the
         * board
         */
        if (gameOver == true) {
            cout << "**happy noises**" << endl;
            cout << players[i % 2]->getPlayerName() + " wins!!!" << endl;
            ticTacToeBoard->printBoard();
            return;
        }

        /* Print the updated state of the game board */
        ticTacToeBoard->printBoard();
    }

    /* If no winner is determined after 9 rounds, the match ends in a draw */
    cout << "Match ended in a draw." << endl;
}

/**
 * @brief Destructor for the TicTacToeGame class.
 * Frees the memory allocated for the Tic Tac Toe game board.
 */
TicTacToeGame::~TicTacToeGame() {
    delete ticTacToeBoard;
}


