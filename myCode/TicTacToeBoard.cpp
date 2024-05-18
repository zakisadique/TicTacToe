/*
 * TicTacToeBoard.cpp
 *
 *  Created on: Nov 11, 2023
 *      Author: zakis
 */

/**
 * @file TicTacToeBoard.cpp
 * @brief Implementation of the TicTacToeBoard class.
 *
 * This file contains the implementation of the TicTacToeBoard class,
 * which represents the game board for a Tic Tac Toe game.
 */

#include <iostream>
#include "TicTacToeBoard.h"

using namespace std;

/**
 * @brief TicTacToeBoard class.
 *
 * The TicTacToeBoard class represents the game board for a Tic Tac Toe game.
 * It is derived from the GameBoard class and implements specific
 * functionalities for a Tic Tac Toe board.
 */
TicTacToeBoard::TicTacToeBoard() : GameBoard(3, 3) {
    setDefaultBoard();
}

/**
 * @brief Default constructor for the TicTacToeBoard class.
 */
void TicTacToeBoard::setDefaultBoard() {
    for (size_t i = 0; i < board.size(); ++i) {
        for (size_t j = 0; j < board[i].size(); ++j)
            board[i][j] = EMPTY;
    }
}

/**
 * @brief Destructor for the TicTacToeBoard class.
 */
TicTacToeBoard::~TicTacToeBoard() {
    /* Object destroyed */
}

/**
 * @brief Clear the Tic Tac Toe board.
 * Overrides the virtual function in the base class.
 */
void TicTacToeBoard::clearBoard() {
	setDefaultBoard();
}

/**
 * @brief Print the current state of the Tic Tac Toe board.
 * Overrides the virtual function in the base class.
 */
void TicTacToeBoard::printBoard() const {
    for (size_t i = 0; i <= 3; ++i) {
        for (size_t j = 0; j <= 3; ++j) {
            if (i == 0) {
                if (j == 0) {
                    cout << "  ";
                } else if (j != 0) {
                    cout << j << " ";
                } else {}
            } else if (j == 0) {
                if (i == 0) {
                    cout << "  ";
                } else if (i != 0) {
                    cout << i << " ";
                } else {}
            } else {
                if (board[i - 1][j - 1] == EMPTY) {
                    cout << ". ";
                } else if (board[i - 1][j - 1] == PLAYER_ONE) {
                    cout << "X ";
                } else if (board[i - 1][j - 1] == PLAYER_TWO) {
                    cout << "O ";
                } else {
                    // do nothing
                }
            }
        }
        cout << endl;
    }
}

/**
 * @brief Check for a win condition for the specified player.
 * @param player The player for whom the win condition is checked.
 * @return True if the player has won, false otherwise.
 */
bool TicTacToeBoard::winCondition(Player_t player) {
    for (int i = 0; i < 3; ++i) {
        /* Check rows */
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player) {
            return true;
        }

        /* Check columns */
        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player) {
            return true;
        }
    }

    /* Check diagonals */
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player) {
        return true;
    }

    if (board[2][0] == player &&
        board[1][1] == player &&
        board[0][2] == player) {
        return true;
    }

    return false;
}

/**
 * @brief Check if there are remaining moves on the board.
 * @return True if there are remaining moves, false otherwise.
 */
bool TicTacToeBoard::movesRemaining() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == Player_t::EMPTY) {
                return true;
            }
        }
    }
    return false;
}

