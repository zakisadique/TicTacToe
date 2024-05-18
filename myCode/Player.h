/*
 * Player.h
 *
 *  Created on: Nov 10, 2023
 *      Author: zakis
 */


/**
 * @file Player.h
 * @brief Header file for the abstract Player class.
 *
 * This file contains the declaration of the abstract Player class,
 * which represents a player in a game.
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include "Game_t.h"
#include "Player_t.h"
#include "Player_Type_t.h"

/**
 * @brief Abstract Player class.
 *
 * The Player class represents a player in a game. It includes information about
 * the player's game, type, name, and number. This class is intended to be a base
 * class for specific player implementations.
 */
class Player {
protected:
    Game_t playerGame; /**< The type of game the player is associated with. */
    Player_Type_t playerType; /**< The type of player (HUMAN or BOT). */
    std::string playerName; /**< The name of the player. */
    Player_t playerNumber; /**< The player number (PLAYER_ONE or PLAYER_TWO). */

public:
    /**
     * @brief Virtual destructor for the Player class.
     *
     * The destructor is declared as virtual to ensure proper destruction
     * of objects when using polymorphism.
     */
    virtual ~Player() = 0;

    /**
     * @brief Pure virtual function representing a player move.
     * @return True if the move results in a win, false otherwise.
     */
    virtual bool move() = 0;

    /**
     * @brief Get the name of the player.
     * @return The name of the player.
     */
    std::string getPlayerName();
};

#endif /* PLAYER_H_ */
