/*
 * humanPlayer.cpp
 *
 *  Created on: Nov 10, 2023
 *      Author: zakis
 */

/**
 * @file TicTacToeHumanPlayer.cpp
 * @brief Implementation of the TicTacToeHumanPlayer class.
 *
 * This file contains the implementation of the TicTacToeHumanPlayer class,
 * which represents a human player in the Tic Tac Toe game.
 */


#include <iostream>
#include "TicTacToeHumanPlayer.h"

using namespace std;

/**
 * @brief Constructor for the TicTacToeHumanPlayer class.
 * @param playerName Name of the human player.
 * @param playerNumber Player number assigned to the human player.
 * @param ticTacToeBoard Pointer to the Tic Tac Toe board.
 */
TicTacToeHumanPlayer::TicTacToeHumanPlayer(const std::string playerName,
                                           Player_t playerNumber, TicTacToeBoard* ticTacToeBoard) {
    this->playerGame = Game_t::TIC_TAC_TOE;
    this->playerType = Player_Type_t::HUMAN;
    this->playerName = playerName;
    this->playerNumber = playerNumber;
    this->ticTacToeBoard = ticTacToeBoard;
}

/**
 * @brief Destructor for the TicTacToeHumanPlayer class.
 */
TicTacToeHumanPlayer::~TicTacToeHumanPlayer() {
    // No dynamic memory allocation in this class, so no cleanup needed.
}

/**
 * @brief Override the move function for human players.
 * Implements the specific logic for human player moves.
 * @return True if the move results in a win, false otherwise.
 */
bool TicTacToeHumanPlayer::move() {
    int x = -1;
    int y = -1;

    cout << playerName + "'s turn" << endl << endl;
    cout << "Please enter your move (x y): ";

    /* Loop until a valid move is entered */
    while (x == -1 || y == -1) {
        cin >> x;
        cin >> y;

        /* Convert the move to 0-index */
        --x;
        --y;

        /* Check if the move is within the valid range */
        if (!(x >= 0 && x <= 2 && y >= 0 && y <= 2)) {
            cout << "Incorrect move. Please try again" << endl;
            x = y = -1;
        } else {
        	/* Check if the chosen position is already occupied */
            if (ticTacToeBoard->getStone(x, y) != EMPTY) {
                cout << "Incorrect move. Please try again" << endl;
                x = y = -1;
            }
        }
    }

    /* Set the stone on the board and check for a win condition */
    ticTacToeBoard->setStone(x, y, playerNumber);
    return ticTacToeBoard->winCondition(playerNumber);
}
