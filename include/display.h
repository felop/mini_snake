#ifndef _DISPLAY_H
#define _DISPLAY_H


#include <SDL.h>
#include "tile.h"

#define DOT_PER_TILE 7
#define PIX_PER_DOT 7
#define X_RES X_MAP_SIZE * DOT_PER_TILE
#define Y_RES Y_MAP_SIZE * DOT_PER_TILE
#define X_WINDOW_SIZE X_RES * PIX_PER_DOT
#define Y_WINDOW_SIZE Y_RES * PIX_PER_DOT
#define INV_FPS .1

typedef struct _tile tile;

int     get_direction(SDL_Event event);
int     shift_buffer(int shift_amount, int buffer[2]);
int     update_direction(SDL_Event event, tile* snake, int dir_buffer[2], int* started);
void    draw_bodytile(SDL_Renderer* renderer, int x, int y, int direction, int r, int g, int b);
void    draw_bodyboundary(SDL_Renderer* renderer, int x, int y, int direction, int r, int g, int b);
void    draw_body(SDL_Renderer* renderer, tile* current_tile, tile* next_tile);
void    draw_snake(tile* snake, SDL_Renderer* renderer);
void    draw_apple(tile* apple, SDL_Renderer* renderer);
void    clear_screen(SDL_Renderer* renderer);
void    render_screen(SDL_Renderer* renderer);


#endif