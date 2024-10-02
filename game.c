#include "game.h"

tile* init_snake(short int x, short int y, short int direction)
{
    tile *snake = (tile*)malloc(sizeof(tile));
    tile *neck = (tile*)malloc(sizeof(tile));
    neck->x = x - (1 - direction) % 2;
    neck->y = y - (direction - 2) % 2;
    neck->direction = direction;
    neck->next = NULL;
    snake->x = x;
    snake->y = y;
    snake->direction = direction;
    snake->next = neck;
    return snake;
}

tile* init_apple(short int x, short int y)
{
    tile* apple = (tile*)malloc(sizeof(tile));
    apple->x = x;
    apple->y = y;
    apple->direction = -1;
    apple->next = NULL;
    return apple;
}

int step_forward(tile* snake, tile* apple)
{
    tile *new_neck = (tile *) malloc(sizeof(tile));
    new_neck->x = snake->x;
    new_neck->y = snake->y;
    new_neck->direction = snake->direction;
    new_neck->next = snake->next;
    snake->x += (1 - snake->direction) % 2;
    snake->y += (snake->direction - 2) % 2;

    int state = 1;
    if (wall_hit(snake)) {
        free(new_neck);
        return 0;
    } else if (colliding(snake, apple)) {
        snake->next = new_neck;
        state = 2;
    } else {
        tile *current_tile = new_neck;
        tile *prev_tile = NULL;
        while (state == 1 && current_tile != NULL) {
            if (colliding(snake, current_tile)) {
                state = 0;
                free(new_neck);
            } else if (current_tile->next == NULL) {
                free(current_tile);
                prev_tile->next = NULL;
                current_tile = NULL;
            } else {
                prev_tile = current_tile;
                current_tile = current_tile->next;
            }
        }
    }
    if (state == 1) { snake->next = new_neck; }
    return state;
}

void move_apple(tile* snake, tile* apple)
{
    tile* current_tile = NULL;
    do {
        apple->x = rand() % X_MAP_SIZE;
        apple->y = rand() % Y_MAP_SIZE;
        if (colliding(snake, apple)) { continue; }

        current_tile = snake->next;
        while (current_tile != NULL) {
            if (current_tile->x == apple->x && current_tile->y == apple->y) { break; }
            else if (current_tile != NULL) { current_tile = current_tile->next; }
        }
    } while (current_tile != NULL);
}