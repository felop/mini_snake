#ifndef _GAME_H
#define _GAME_H


#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "display.h"


typedef struct _tile tile;
struct _tile {
    short int x;
    short int y;
    short int direction;
    tile* next;
};


tile*   init_snake(short int x, short int y, short int direction);
tile*   init_apple(short int x, short int y);
int     colliding(tile* A, tile* B);
int     wall_hit(tile* A);
int     step_forward(tile* snake, tile* apple);
void    move_apple(tile* snake, tile* apple);


#endif _GAME_H