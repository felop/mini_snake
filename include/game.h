#ifndef _GAME_H
#define _GAME_H


#include "tile.h"

tile*   init_snake(short int x, short int y, short int direction);
tile*   init_apple(short int x, short int y);
int     step_forward(tile* snake, tile* apple);
void    move_apple(tile* snake, tile* apple);


#endif