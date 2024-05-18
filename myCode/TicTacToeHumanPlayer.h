/*
 * humanPlayer.h
 *
 *  Created on: Nov 10, 2023
 *      Author: zakis
 */

/**
 * @file TicTacToeHumanPlayer.h
 * @brief Header file for the TicTacToeHumanPlayer class.
 *
 * This file contains the declaration of the TicTacToeHumanPlayer class,
 * which represents a human player in the Tic Tac Toe game.
 */

#ifndef TICTACTOEHUMANPLAYER_H_
#define TICTACTOEHUMANPLAYER_H_

#include "TicTacToePlayer.h"

/**
 * @brief TicTacToeHumanPlayer class.
 *
 * The TicTacToeHumanPlayer class represents a human player in the Tic Tac Toe
 * game.
 * It is derived from the TicTacToePlayer class and implements the specific
 * functionalities for human players.
 */
class TicTacToeHumanPlayer : public TicTacToePlayer {
public:
    /**
     * @brief Constructor for the TicTacToeHumanPlayer class.
     * @param playerName Name of the human player.
     * @param playerNumber Player number assigned to the human player.
     * @param ticTacToeBoard Pointer to the Tic Tac Toe board.
     */
    TicTacToeHumanPlayer(const std::string playerName, Player_t playerNumber, TicTacToeBoard* ticTacToeBoard);

    /**
     * @brief Destructor for the TicTacToeHumanPlayer class.
     */
    ~TicTacToeHumanPlayer();

    /**
     * @brief Override the move function for human players.
     * Implements the specific logic for human player moves.
     * @return True if the move results in a win, false otherwise.
     */
    bool move() override;
};

#endif /* TICTACTOEHUMANPLAYER_H_ */
