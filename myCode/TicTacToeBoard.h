/*
 * TicTacToeBoard.h
 *
 *  Created on: Nov 11, 2023
 *      Author: zakis
 */

/**
 * @file TicTacToeBoard.h
 * @brief Header file for the TicTacToeBoard class.
 *
 * This file contains the declaration of the TicTacToeBoard class,
 * which represents the game board for a Tic Tac Toe game.
 */

#ifndef TICTACTOEBOARD_H_
#define TICTACTOEBOARD_H_

#include "GameBoard.h"

/**
 * @brief TicTacToeBoard class.
 *
 * The TicTacToeBoard class represents the game board for a Tic Tac Toe game.
 * It is derived from the GameBoard class and implements specific
 * functionalities for a Tic Tac Toe board.
 */
class TicTacToeBoard : public GameBoard {

public:
    /**
     * @brief Default constructor for the TicTacToeBoard class.
     */
    TicTacToeBoard();

    /**
     * @brief Destructor for the TicTacToeBoard class.
     */
    ~TicTacToeBoard();

    /**
     * @brief Set the default configuration for the Tic Tac Toe board.
     * Overrides the virtual function in the base class.
     */
    virtual void setDefaultBoard() override;


    virtual void clearBoard() override;

    /**
     * @brief Print the current state of the Tic Tac Toe board.
     * Overrides the virtual function in the base class.
     */
    void printBoard() const override;

    /**
     * @brief Check for a win condition for the specified player.
     * @param player The player for whom the win condition is checked.
     * @return True if the player has won, false otherwise.
     */
    bool winCondition(Player_t player);

    /**
     * @brief Check if there are remaining moves on the board.
     * @return True if there are remaining moves, false otherwise.
     */
    bool movesRemaining();
};

#endif /* TICTACTOEBOARD_H_ */

