#include "display.h"

int get_direction(SDL_Event event)
{
    int direction = -1;
    switch (event.key.keysym.scancode) {
        case SDL_SCANCODE_RIGHT:
            direction = 0;
            break;
        case SDL_SCANCODE_UP:
            direction = 1;
            break;
        case SDL_SCANCODE_LEFT:
            direction = 2;
            break;
        case SDL_SCANCODE_DOWN:
            direction = 3;
            break;
        case SDL_SCANCODE_D:
            direction = 0;
            break;
        case SDL_SCANCODE_W:
            direction = 1;
            break;
        case SDL_SCANCODE_A:
            direction = 2;
            break;
        case SDL_SCANCODE_S:
            direction = 3;
            break;
        default:
            break;
    }
    return direction;
}

int shift_buffer(int shift_amount, int buffer[2])
{
    int result = -1;
    for (int i=0; i<shift_amount; i++) {
        result = buffer[0];
        buffer[0] = buffer[1];
        buffer[1] = -1;
    }
    return result;
}

int update_direction(SDL_Event event, tile* snake, int dir_buffer[2], int* started)
{
    int new_direction = get_direction(event);
    if (new_direction != -1) {
        if ( (snake->direction-new_direction)%2 != 0 ) {
            dir_buffer[0] = new_direction;
        } else if (dir_buffer[0] != -1) {
            dir_buffer[1] = new_direction;
        }
        if (new_direction != 2) {
            *started = 1;
        }
    }
    return 1;
}

void draw_bodytile(SDL_Renderer* renderer, int x, int y, int direction, int r, int g, int b)
{
    SDL_Rect rect = {
            DotPerTile*x + 1,
            DotPerTile*y + 1,
            DotPerTile - 2,
            DotPerTile - 2
    };
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void draw_bodyboundary(SDL_Renderer* renderer, int x, int y, int direction, int r, int g, int b)
{
    SDL_Rect rect = {
            DotPerTile*x + (DotPerTile-1)*(direction==0) + ((direction)%2),
            DotPerTile*y + (DotPerTile-1)*(direction==3) + ((direction+1)%2),
            1 + (DotPerTile - 3)*(direction%2),
            1 + (DotPerTile - 3)*((direction+1)%2)
    };
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void draw_body(SDL_Renderer* renderer, tile* current_tile, tile* next_tile)
{
    draw_bodytile(renderer, current_tile->x, current_tile->y, current_tile->direction, 68, 107, 208);
    draw_bodyboundary(renderer, current_tile->x, current_tile->y, current_tile->direction, 68, 107, 208);
    if (next_tile) {
        draw_bodyboundary(renderer, current_tile->x, current_tile->y, (next_tile->direction+2)%4, 68, 107, 208);
    } else {
        // add eyes
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
        SDL_RenderDrawPoint(renderer, current_tile->x, current_tile->y);
    }
}

void draw_snake(tile* snake, SDL_Renderer* renderer)
{
    tile* current_tile = snake;
    while (current_tile != NULL) {
        draw_body(renderer, current_tile, current_tile->next);
        current_tile = current_tile->next;
    }
}

void draw_apple(tile* apple, SDL_Renderer* renderer)
{
    draw_bodytile(renderer, apple->x, apple->y, 0, 255, 0, 0);
}

void clear_screen(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 140, 169, 110, 255);
    SDL_RenderClear(renderer);
}

void render_screen(SDL_Renderer* renderer)
{
    SDL_RenderPresent(renderer);
    SDL_PollEvent(0);
    clear_screen(renderer);
}