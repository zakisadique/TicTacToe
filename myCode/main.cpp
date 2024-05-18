/**
 * @mainpage 1.1 Requirements
 *
 * @section task Task
 * Develop a console-based version of the board game TicTacToe with the following specifications:
 * - The game consists of a 3x3 board.
 * - On every position, players place an "x" (Player 1) or an "o" (Player 2) stone.
 * - The first player with 3 stones in a row (horizontally, vertically, or diagonally) wins the game.
 *
 * @section technical_requirements Technical Requirements
 * - Players 1 and 2 can be human or computer, i.e.,
 *   - Human against Computer
 *   - Human against Human
 *   - Computer against Human
 *   - Computer against Computer are possible combinations.
 * - The computer may never lose.
 */

/**
 * @file main.cpp
 * @brief Main program file for the Gaming Portal application.
 */

#include <iostream>
#include "GamingPortal.h"

using namespace std;

/**
 * @brief The main function of the program.
 * @return Exit code of the program.
 */
int main() {
    /* Create an instance of the GamingPortal */
    GamingPortal myGaming;

    /* Return 0 to indicate successful program execution */
    return 0;
}
