/*
 * Bot.cpp
 *
 *  Created on: Nov 10, 2023
 *      Author: zakis
 */

/**
 * @file TicTacToeBotPlayer.cpp
 * @brief Implementation of the TicTacToeBotPlayer class.
 *
 * This file contains the implementation of the TicTacToeBotPlayer class,
 * which represents a bot player for a Tic Tac Toe game.
 */

#include "TicTacToeBotPlayer.h"

#include <iostream>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

/**
 * @brief Constructor for the TicTacToeBotPlayer class.
 * @param playerName The name of the bot player.
 * @param playerNumber The player number of the bot.
 * @param ticTacToeBoard Pointer to the Tic Tac Toe board.
 */
TicTacToeBotPlayer::TicTacToeBotPlayer(const std::string playerName,
		Player_t playerNumber, TicTacToeBoard* ticTacToeBoard) {
	this -> playerGame = Game_t::TIC_TAC_TOE;
	this -> playerType = Player_Type_t::BOT;
	this -> playerName = playerName;
	this -> playerNumber = playerNumber;
	this -> ticTacToeBoard = ticTacToeBoard;

}

/**
 * @brief Destructor for the TicTacToeBotPlayer class.
 */
TicTacToeBotPlayer::~TicTacToeBotPlayer() {
    /* No dynamic memory allocation in this class, so no cleanup needed. */
}

/**
 * @brief Evaluate the quality of a move for the specified player.
 * @param playerNumber The player number for whom the move is evaluated.
 * @return The evaluation score for the move (positive in case of win,
 * negative in case of a loss, 0 for a draw).
 */
int TicTacToeBotPlayer::evaluateMove(Player_t currentPlayer) {
    Player_t opponentPlayer = (currentPlayer == Player_t::PLAYER_ONE) ?
                                Player_t::PLAYER_TWO : Player_t::PLAYER_ONE;

    /* Check if the current player wins, loses, or if it's a draw */
    if (ticTacToeBoard->winCondition(currentPlayer)) {
        return 10;
    } else if (ticTacToeBoard->winCondition(opponentPlayer)) {
        return -10;
    } else {
        return 0;
    }
}


/**
 * @brief Overrides the move function for the bot player.
 * Implements the move strategy for the bot player.
 * @return True if the move resulted in a win, false otherwise.
 */
bool TicTacToeBotPlayer::move() {
    cout << playerName + "'s turn: ";

    Player_t currentPlayer = playerNumber;

    int bestMoveValue = -100;
    int bestMoveRow = -1;
    int bestMoveCol = -1;

    /* Iterate through all possible moves to find the best move using minimax */
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (ticTacToeBoard->getStone(i, j) == Player_t::EMPTY) {
            	/* If the place is empty, make a move for the current player */
                ticTacToeBoard->setStone(i, j, currentPlayer);

                /* Evaluate the move using minimax algorithm */
                int currentMoveValue = minimax(0, false);

                /* Undo the move */
                ticTacToeBoard->setStone(i, j, Player_t::EMPTY);

                /* Update the best move if the current move is better */
                if (currentMoveValue > bestMoveValue) {
                    bestMoveValue = currentMoveValue;
                    bestMoveRow = i;
                    bestMoveCol = j;
                }
            }
        }
    }

    /* Make the best move and display the coordinates */
    ticTacToeBoard->setStone(bestMoveRow, bestMoveCol, currentPlayer);
    cout << "(" << bestMoveRow + 1 << " " << bestMoveCol + 1 << ")" << endl << endl;

    /* Check if the current player won */
    return ticTacToeBoard->winCondition(currentPlayer);
}

/**
 * @brief Minimax algorithm for move evaluation.
 * @param depth The depth of the search in the minimax algorithm.
 * @param isMax Indicates whether it is the maximizing player's turn.
 * @return The evaluation score for the move.
 */
int TicTacToeBotPlayer::minimax(int depth, bool isMax) {
	/* Evaluate the current state of the game */
	int score = evaluateMove(playerNumber);

	/* Check if the game has reached a terminal state */
	if (score == 10){
		return score - depth;

	}
	if (score == -10){
		return score - depth;

	}
	if (!ticTacToeBoard->movesRemaining()){
		return 0 - depth;
	}

	/* Recursive minimax algorithm to find the best move from current player's
	 * perspective
	 */
	if (isMax){
		int bestScore = -100;

		for (int i = 0; i < 3; ++i){
			for (int j = 0; j < 3; ++j){

				if (ticTacToeBoard->getStone(i, j) == Player_t::EMPTY){
					/* Make a move if an empty place is found */
					ticTacToeBoard->setStone(i, j, playerNumber);
					/* Evaluate the move by calling minimax from perspective of
					 * the opponent, and save the possible score */
					bestScore = max(bestScore, minimax(depth + 1, !isMax));
					/* Undo the move */
					ticTacToeBoard->setStone(i, j, Player_t::EMPTY);
				}
			}

		}
		return bestScore;

	/* Recursive minimax algorithm to find the best move from opponent's
	* perspective
	*/
	} else {
		int bestScore = 100;
		/* Get the opponent's player number */
		Player_t opponent = (playerNumber == PLAYER_ONE) ?
				PLAYER_TWO : PLAYER_ONE;

		for (int i = 0; i < 3; ++i){
			for (int j = 0; j < 3; ++j){

				if (ticTacToeBoard->getStone(i, j) == Player_t::EMPTY){
					/* Make a move if an empty place is found */
					ticTacToeBoard->setStone(i, j, opponent);
					/* Evaluate the move by calling minimax from perspective of
					* current player, and save the possible score
					*/
					bestScore = min(bestScore, minimax(depth + 1, !isMax));
					ticTacToeBoard->setStone(i, j, Player_t::EMPTY);
				}
			}

		}
		return bestScore;
	}

}
