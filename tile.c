#include "tile.h"


int colliding(tile* A, tile* B)
{
    return A->x == B->x && A->y == B->y;
}

int wall_hit(tile* A)
{
    return A->x < 0 || A->x >= X_MAP_SIZE || A->y < 0 || A->y >= Y_MAP_SIZE;
}

