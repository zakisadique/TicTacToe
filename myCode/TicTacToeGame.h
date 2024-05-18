/*
 * TicTacToeGame.h
 *
 *  Created on: Nov 10, 2023
 *      Author: zakis
 */

/**
 * @file TicTacToeGame.h
 * @brief Header file for the TicTacToeGame class.
 *
 * This file contains the declaration of the TicTacToeGame class,
 * which represents the Tic Tac Toe game within the gaming portal.
 */

#ifndef TICTACTOEGAME_H_
#define TICTACTOEGAME_H_

#include <vector>
#include <string>
#include "Game.h"
#include "TicTacToeBoard.h"
#include "Player_Type_t.h"
#include "TicTacToePlayer.h"


/**
 * @brief TicTacToeGame class.
 *
 * The TicTacToeGame class represents the Tic Tac Toe game.
 * It is derived from the Game class and implements the specific
 * functionality for the Tic Tac Toe game, including the game board
 * and player management.
 */
class TicTacToeGame : public Game {
private:
    TicTacToeBoard* ticTacToeBoard; /**< Pointer to the Tic Tac Toe board. */
    std::vector<TicTacToePlayer*> players; /**< Vector of Tic Tac Toe players. */

public:
    /**
     * @brief Constructor for the TicTacToeGame class.
     * Initializes the Tic Tac Toe game by setting its name and creating
     * instances of the game board and players based on the provided player
     * types and names.
     * @param playerTypes A vector containing the player types (Human or Bot).
     * @param PlayerNames A vector containing the player names.
     */
    TicTacToeGame(std::vector<Player_Type_t> playerTypes,
    		std::vector<std::string> PlayerNames);

    /**
     * @brief Overrides the play function for the Tic Tac Toe game.
     * Implements the specific game logic for Tic Tac Toe.
     */
    void play() override;

    /**
     * @brief Destructor for the TicTacToeGame class.
     * Frees the memory allocated for the Tic Tac Toe game board.
     */
    ~TicTacToeGame();

};

#endif /* TICTACTOEGAME_H_ */
