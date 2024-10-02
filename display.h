#ifndef _DISPLAY_H
#define _DISPLAY_H


#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "game.h"


#define DotPerTile 7
#define PixPerDot 7
#define xMapSize 10
#define yMapSize 9
#define xRes xMapSize * DotPerTile
#define yRes yMapSize * DotPerTile
#define xWindowSize xRes * PixPerDot
#define yWindowSize yRes * PixPerDot
#define inv_fps .1


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


#endif _DISPLAY_H