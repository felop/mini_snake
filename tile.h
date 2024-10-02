#ifndef _TILE_H
#define _TILE_H


#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define X_MAP_SIZE 10
#define Y_MAP_SIZE 9

typedef struct _tile tile;
struct _tile {
    short int x;
    short int y;
    short int direction;
    tile* next;
};

int     colliding(tile* A, tile* B);
int     wall_hit(tile* A);


#endif