/*
 * Bot.h
 *
 *  Created on: Nov 10, 2023
 *      Author: zakis
 */

/**
 * @file TicTacToeBotPlayer.h
 * @brief Header file for the TicTacToeBotPlayer class.
 *
 * This file contains the declaration of the TicTacToeBotPlayer class,
 * which represents a bot player for a Tic Tac Toe game.
 */

#ifndef TICTACTOEBOTPLAYER_H_
#define TICTACTOEBOTPLAYER_H_

#include "TicTacToePlayer.h"

/**
 * @brief TicTacToeBotPlayer class.
 *
 * The TicTacToeBotPlayer class represents a bot player for a Tic Tac Toe game.
 * It is derived from the TicTacToePlayer class and implements specific
 * functionality
 * for a bot player, such as evaluating moves using the minimax algorithm.
 */
class TicTacToeBotPlayer : public TicTacToePlayer {

public:
    /**
     * @brief Constructor for the TicTacToeBotPlayer class.
     * @param playerName The name of the bot player.
     * @param playerNumber The player number of the bot.
     * @param ticTacToeBoard Pointer to the Tic Tac Toe board.
     */
    TicTacToeBotPlayer(const std::string playerName, Player_t playerNumber, TicTacToeBoard* ticTacToeBoard);

    /**
     * @brief Destructor for the TicTacToeBotPlayer class.
     */
    ~TicTacToeBotPlayer();

    /**
     * @brief Overrides the move function for the bot player.
     * Implements the move strategy for the bot player.
     * @return True if the move resulted in a win, false otherwise.
     */
    virtual bool move() override;

    /**
     * @brief Evaluate the quality of a move for the specified player.
     * @param playerNumber The player number for whom the move is evaluated.
     * @return The evaluation score for the move (positive in case of win,
     * negative in case of a loss, 0 for a draw).
     */
    int evaluateMove(Player_t playerNumber);

    /**
     * @brief Minimax algorithm for move evaluation.
     * @param depth The depth of the search in the minimax algorithm.
     * @param isMax Indicates whether it is the maximizing player's turn.
     * @return The evaluation score for the move.
     */
    int minimax(int depth, bool isMax);
};

#endif /* TICTACTOEBOTPLAYER_H_ */

