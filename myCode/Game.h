/*
 * Game.h
 *
 *  Created on: Nov 14, 2023
 *      Author: zakis
 */

/**
 * @file Game.h
 * @brief Header file for the abstract Game class.
 * The Game class serves as the base class for specific game implementations.
 */

#ifndef GAME_H_
#define GAME_H_

#include "Game_t.h"

/**
 * @brief Abstract Game class.
 *
 * The Game class defines the interface for specific game implementations.
 * It includes a pure virtual function play(), which must be implemented
 * by derived classes for specific game behaviors.
 */
class Game {
protected:
    Game_t gameName; /**< The type of the game. */

public:
    /**
     * @brief Pure virtual function to start playing the game.
     */
    virtual void play() = 0;

    /**
     * @brief Virtual destructor for the Game class.
     */
    virtual ~Game() = 0;
};

#endif /* GAME_H_ */

