//
// Created by Moyo on 1/5/2021.
//

#ifndef POS_SEMESTRAL_KLIENT_MAIN_H
#define POS_SEMESTRAL_KLIENT_MAIN_H

#include <stdbool.h>

enum Player { PLAYER_1, PLAYER_2, PLAYER_3, PLAYER_4 };
const int MAX_PLAYER_COUNT = 4;
const int PAWN_COUNT = 4;
const int SPACING = 2;
const int SIZE = 11;

/**
 * Stores the y, x coordinates
 */
typedef struct coordinates {
    int y;
    int x;
} Position;

/**
 * Stores information about a pawn.
 * That includes: position, number of tiles travelled, its char representation
 */
typedef struct gamepawn {
    Position pos;
    int travelled;
    char symbol;
    bool isActive;
} Pawn;

/**
 * Game Data
 */
typedef struct gamedata {
    Pawn player[4][4];
} Data;

/**
 * Coordinates for each tile in the active game area.
 * Tiles are indexed 0 -> 39 with 0 being the leftmost tile at the top moving to the right
 */
const Position gameArea[40] = {
        {0, 4},
        {0, 5},
        {0, 6},
        {1, 6},
        {2, 6},
        {3, 6},
        {4, 6},
        {4, 7},
        {4, 8},
        {4, 9},
        {4, 10},
        {5, 10},
        {6, 10},
        {6, 9},
        {6, 8},
        {6, 7},
        {6, 6},
        {7, 6},
        {8, 6},
        {9, 6},
        {10, 6},
        {10, 5},
        {10, 4},
        {9, 4},
        {8, 4},
        {7, 4},
        {6, 4},
        {6, 3},
        {6, 2},
        {6, 1},
        {6, 0},
        {5, 0},
        {4, 0},
        {4, 1},
        {4, 2},
        {4, 3},
        {4, 4},
        {3, 4},
        {2, 4},
        {1, 4},
};

/**
 * Coordinates for each player area in the game for all players.
 * [playerIndex][areaIndex][tileIndex]
 * \playerIndex index of a player 0 -> 3
 * \areaIndex index of an area 0 -> 1 where 0 is startingArea and 1 is Home or ending area
 * \tileIndex index of a tile 0 -> 3, when addressing the ending area, the tile closest to the gameArea has index=0
 */
const Position playerPos[4][2][4] = {
        {
                { {0, 0}, {0, 1}, {1, 0}, {1, 1} },
                { {5, 1}, {5, 2}, {5, 3}, {5, 4} }
        },
        {
                { {0, 9}, {0, 10}, {1, 9}, {1, 10} },
                { {1, 5}, {2, 5}, {3, 5}, {4, 5} }
        },
        {
                { {9, 9}, {9, 10}, {10, 9}, {10, 10} },
                { {5, 9}, {5, 8}, {5, 7}, {5, 6} }
        },
        {
                { {9, 0}, {9, 1}, {10, 0}, {10, 1} },
                { {9, 5}, {8, 5}, {7, 5}, {6, 5} }
        }
};

/**
 * Prints given string at the given position using curses.h
 * Automatically adds spacing to the x-axis
 * @param position where should the string be printed
 * @param string what should be printed
 * @return upon successful completion, returns OK. Otherwise, returns ERR
 */
int movePrintSpacing(Position position, const char* string);

/**
 * Gives color pair number for the given player.
 * @param player
 * @return color pair number
 */
int getColor(enum Player player);

/**
 * Gives color pair number for the given player.
 * @param player number of the player [0 -> 3]
 * @return color pair number
 */
int colorFromPlayerNum(int player);

/**
 * Draws the initial game board.
 */
void drawBoard();

#endif //POS_SEMESTRAL_KLIENT_MAIN_H
