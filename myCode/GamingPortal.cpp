/*
 * GamingPortal.cpp
 *
 *  Created on: Nov 11, 2023
 *      Author: zakis
 */

/**
 * @file GamingPortal.cpp
 * @brief Implementation file for the GamingPortal class.
 *
 * This file contains the implementation of the GamingPortal class, which
 * represents a portal for playing multiplayer games.
 */

#include <iostream>
#include <string>

#include "GamingPortal.h"
#include "TicTacToeGame.h"
#include "MaxPlayers_t.h"

using namespace std;

/**
 * @brief Constructor for the GamingPortal class.
 * Initializes the gaming portal by showing a welcome message,
 * selecting a game, and getting player details. Then, it creates
 * an instance of the selected game and starts the gameplay.
 */
GamingPortal::GamingPortal() {
    showWelcomeMessage();
    Game_t game = getGame();
    pair<vector<Player_Type_t>, vector<string>> players = getPlayerDetails(game);
    currentGame = new TicTacToeGame(players.first, players.second);
    currentGame->play();
}

/**
 * @brief Displays a welcome message for the gaming portal.
 */
void GamingPortal::showWelcomeMessage() {
    cout << "Welcome to my multiplayer gaming portal where you can enjoy classic "
            "games with your friends... "
         << endl << "or without them (in case you don't have any :/). " << endl;
}

/**
 * @brief Gets the selected game for the portal.
 * Currently, only Tic Tac Toe is available.
 * @return The selected game.
 */
Game_t GamingPortal::getGame() {
    cout << endl << "Only Tic Tac Toe is available at the moment. "
    		"(More games are coming soon!)" << endl;
    return Game_t::TIC_TAC_TOE;
}

/**
 * @brief Gets player details for the selected game.
 * Prompts the user to choose player types (Human or Bot)
 * and enter their names. For bots, it generates a random name.
 * @param game The selected game.
 * @return A pair containing vectors of player types and player names.
 */
pair<vector<Player_Type_t>, vector<string>> GamingPortal::getPlayerDetails
															(Game_t game) {
	/*  Get the name of the game in order to display on the screen. */
    string gameName = getGameName(game);

    /* Prompt user to select players */
    cout << endl << "Select players for " << gameName << endl;

    /* Declare player types and their names */
    vector<Player_Type_t> playerTypes;
    vector<string> playerNames;

    /* If the player chosen is a human, ask for a name. In case of bot players,
     * get a random name.
     */
    for (int i = 1; i <= MaxPlayers_t::TIC_TAC_TOE_PLAYERS; ++i) {
        int choice = -1;

        while (choice == -1) {
            cout << endl << "Please make the choice for player " << i << ": " << endl
                 << "1. Human" << endl
                 << "2. Bot" << endl;
            cin.clear();
            cin >> choice;

            if (choice == 1) {
                playerTypes.push_back(Player_Type_t::HUMAN);
                cout << "Please enter name: ";
                string playerName = "";
                cin.clear();
                cin >> playerName;

                while ((i != 1) && (playerName == playerNames[0])) {
                    cout << "Player already exists. Please choose another name: ";
                    cin.clear();
                    cin >> playerName;
                }
                playerNames.push_back(playerName);

            } else if (choice == 2) {
                playerTypes.push_back(Player_Type_t::BOT);
                string botName = GamingPortal::getBotPlayerName();

                while ((i != 1) && (botName == playerNames[0])) {
                    botName = GamingPortal::getBotPlayerName();
                }
                playerNames.push_back(botName);

                cout << endl << "Initializing Bot: " + botName <<
                        endl << "Status: Online" << endl;

            } else {
                cout << "Please choose either 1 or 2" << endl;
                choice = -1;
            }
        }
    }

    return make_pair(playerTypes, playerNames);
}

/**
 * @brief Gets the name of the selected game.
 * Currently, only Tic Tac Toe is supported.
 * @param game The selected game.
 * @return The name of the game.
 */
string GamingPortal::getGameName(Game_t game) {
    switch (game) {
    case TIC_TAC_TOE:
        return "Tic Tac Toe";
    default:
        return "";
    }
}

/**
 * @brief Gets a random bot player name from a predefined list.
 * @return A random bot player name.
 */
string GamingPortal::getBotPlayerName() {
    vector<string> botNames {"Gabe", "HAL 9000", "Skynet", "Agent Smith", "JARVIS",
                            "FRIDAY", "Vision", "Ultron", "GLaDOS"};
    srand(time(0));
    int randomBotNumber = rand() % botNames.size();
    return botNames[randomBotNumber];
}

/**
 * @brief Destructor for the GamingPortal class.
 * Frees the memory allocated for the current game instance.
 */
GamingPortal::~GamingPortal() {
    delete currentGame;
}


