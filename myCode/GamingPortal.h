/*
 * GameBoard.h
 *
 *  Created on: Nov 9, 2023
 *      Author: zakis
 */

/**
 * @file GamingPortal.h
 * @brief Header file for the GamingPortal class.
 *
 * This file contains the declaration of the GamingPortal class, which
 * represents a portal for playing multiplayer games.
 */

#ifndef GAMINGPORTAL_H_
#define GAMINGPORTAL_H_

#include <vector>
#include <string>
#include "Game.h"
#include "Game_t.h"
#include "Player_Type_t.h"

using namespace std;

/**
 * @class GamingPortal
 * @brief Represents a gaming portal that contains various games.
 */
class GamingPortal {
private:

    Game* currentGame; /**< Pointer to the game instance being played. */

    /**
     * @brief Displays a welcome message to the user.
     */
    void showWelcomeMessage();

    /**
     * @brief Gets the type of game the user wants to play.
     * @return The type of game (e.g., Tic Tac Toe).
     */
    Game_t getGame();

    /**
     * @brief Gets details (types, and names) about players participating in the
     * game.
     * @param game The game being played.
     * @return A pair of vectors containing player types and names.
     */
    pair<vector<Player_Type_t>, vector<string>> getPlayerDetails(Game_t game);

    /**
     * @brief Gets the name of the specified game.
     * @param game The type of game.
     * @return A string representing the name of the game.
     */
    string getGameName(Game_t game);

    /**
     * @brief Gets the name of bot player during bot creation.
     * @return A string representing the name of a bot player.
     */
    static string getBotPlayerName();

public:

    /**
     * @brief Default constructor for the GamingPortal class.
     * Initializes the gaming portal by showing a welcome message,
     * selecting a game, and getting player details. Then, it creates
     * an instance of the selected game and starts the gameplay.
     */
    GamingPortal();

    /**
     * @brief Destructor for the GamingPortal class.
     */
    ~GamingPortal();

};

#endif /* GAMINGPORTAL_H_ */
