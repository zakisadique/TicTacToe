/*
 * Player.cpp
 *
 *  Created on: Nov 10, 2023
 *      Author: zakis
 */

/**
 * @file Player.cpp
 * @brief Implementation of the abstract Player class.
 *
 * This file contains the implementation of the abstract Player class,
 * which represents a player in a game.
 */

#include <iostream>
#include "Player.h"

using namespace std;

/**
 * @brief Virtual destructor for the Player class.
 *
 * The destructor is declared as virtual to ensure proper destruction
 * of objects when using polymorphism.
 */
Player::~Player() {
}

/**
 * @brief Get the name of the player.
 * @return The name of the player.
 */
string Player::getPlayerName() {
	return this -> playerName;
}
