/*
 * GameBoard.cpp
 *
 *  Created on: Nov 9, 2023
 *      Author: zakis
 */

/**
 * @file GameBoard.cpp
 * @brief Implementation file for the abstract GameBoard class.
 * The GameBoard class serves as the base class for specific game boards
 * implementations.
 */
#include <iostream>
#include "GameBoard.h"


using namespace std;

/**
 * @brief Default constructor for the GameBoard class.
 */
GameBoard::GameBoard() : numRows {0}, numColumns {0} {
	board = std::vector<std::vector<Player_t>>(numRows,
			std::vector<Player_t>(numColumns, EMPTY));
}

/**
 * @brief Parameterized constructor for the GameBoard class.
 * @param numRows Number of rows in the game board.
 * @param numColumns Number of columns in the game board.
 */
GameBoard::GameBoard(int numRows, int numColumns) : numRows {numRows},
		numColumns {numRows} {
			board = vector<vector<Player_t>>(numRows, vector<Player_t>(numColumns, EMPTY));

}

/**
 * @brief Set the default configuration for the game board.
 */
void GameBoard::setDefaultBoard(){
    for (size_t i = 0; i < board.size(); ++i) {
    	for (size_t j = 0; j < board[i].size(); ++j)
    	board[i][j] = EMPTY;
    }
}

/**
 * @brief Copy constructor for the GameBoard class.
 * @param boardInstance Another instance of the GameBoard to copy.
 */
GameBoard::GameBoard(const GameBoard& gameBoard): numRows{gameBoard.numRows},
		numColumns {gameBoard.numColumns} {

	board = gameBoard.board;
}

/**
 * @brief Virtual destructor for the GameBoard class.
 *
 * The destructor is declared as virtual to ensure proper destruction
 * of objects when using polymorphism.
 */
GameBoard::~GameBoard() {
}

/**
 * @brief Clear the contents of the game board.
 */
void GameBoard::clearBoard() {

	setDefaultBoard();
}

/**
 * @brief Set a stone on the game board at the specified position.
 * @param row Row index of the game board.
 * @param col Column index of the game board.
 * @param player The player number to set at the specified position.
 */
void GameBoard::setStone(int row, int col, Player_t player) {

	board[row][col] = player;
}

/**
 * @brief Pure virtual function to print the current state of the game board.
 */
Player_t GameBoard::getStone(int row, int col) {
	return board[row][col];
}

