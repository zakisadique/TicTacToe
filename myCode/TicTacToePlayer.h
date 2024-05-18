/*
 * TicTacToePlayer.h
 *
 *  Created on: Nov 15, 2023
 *      Author: zakis
 */

/**
 * @file TicTacToePlayer.h
 * @brief Header file for the TicTacToePlayer class.
 *
 * This file contains the declaration of the TicTacToePlayer class,
 * which represents a player in the Tic Tac Toe game.
 */

#ifndef TICTACTOEPLAYER_H_
#define TICTACTOEPLAYER_H_

#include <string>

#include "TicTacToeBoard.h"
#include "Player.h"

/**
 * @brief TicTacToePlayer class.
 *
 * The TicTacToePlayer class represents a player in the Tic Tac Toe game.
 * It is an abstract base class for all Tic Tac Toe players, defining
 * common properties and methods.
 */
class TicTacToePlayer : public Player {
protected:
    TicTacToeBoard* ticTacToeBoard; /**< Pointer to the Tic Tac Toe board. */

public:
    /**
     * @brief Pure virtual function for the player's move.
     * Each derived class must implement this function to define
     * the specific logic for the player's move.
     * @return True if the move is successful, false otherwise.
     */
    virtual bool move() = 0;

    /**
     * @brief Destructor for the TicTacToePlayer class.
     */
    virtual ~TicTacToePlayer();
};

#endif /* TICTACTOEPLAYER_H_ */
