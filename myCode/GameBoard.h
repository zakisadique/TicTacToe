/*
 * GameBoard.h
 *
 *  Created on: Nov 9, 2023
 *      Author: zakis
 */
/**
 * @file GameBoard.h
 * @brief Header file for the abstract GameBoard class.
 * The GameBoard class serves as the base class for specific game boards
 * implementations.
 */

#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

#include <vector>
#include "Player_t.h"

/**
 * @brief Abstract GameBoard class.
 *
 * The GameBoard class represents the game board for various board games.
 * It includes functions to set stones, get stones, clear the board, and print
 * the board.
 */
class GameBoard {
protected:
    int numRows; /**< Number of rows in the game board. */
    int numColumns; /**< Number of columns in the game board. */
    std::vector<std::vector<Player_t>> board; /**< 2D vector representing the
    											game board. */

public:
    /**
     * @brief Default constructor for the GameBoard class.
     */
    GameBoard();

    /**
     * @brief Parameterized constructor for the GameBoard class.
     * @param numRows Number of rows in the game board.
     * @param numColumns Number of columns in the game board.
     */
    GameBoard(int numRows, int numColumns);

    /**
     * @brief Copy constructor for the GameBoard class.
     * @param boardInstance Another instance of the GameBoard to copy.
     */
    GameBoard(const GameBoard& boardInstance);

    /**
     * @brief Virtual destructor for the GameBoard class.
     *
     * The destructor is declared as virtual to ensure proper destruction
     * of objects when using polymorphism.
     */
    virtual ~GameBoard();

    /**
     * @brief Set the default configuration for the game board.
     */
    virtual void setDefaultBoard();

    /**
     * @brief Clear the contents of the game board.
     */
    virtual void clearBoard();

    /**
     * @brief Set a stone on the game board at the specified position.
     * @param row Row index of the game board.
     * @param col Column index of the game board.
     * @param player The player number to set at the specified position.
     */
    void setStone(int row, int col, Player_t player);

    /**
     * @brief Get the player number at the specified position on the game board.
     * @param row Row index of the game board.
     * @param col Column index of the game board.
     * @return The player type at the specified position.
     */
    Player_t getStone(int row, int col);

    /**
     * @brief Pure virtual function to print the current state of the game board.
     */
    virtual void printBoard() const = 0;
};

#endif /* GAMEBOARD_H_ */

