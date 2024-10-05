#include "game.h"
#include "display.h"


int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("snake 30/09/2024", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, X_WINDOW_SIZE, Y_WINDOW_SIZE, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    //SDL_Surface* surface = SDL_CreateRGBSurface(0, X_WINDOW_SIZE, Y_WINDOW_SIZE, 32, 0, 0, 0, 0);
    SDL_RenderSetLogicalSize(renderer, X_RES, Y_RES);
    clear_screen(renderer);

    SDL_Event event;
    int running = 1;
    int started = 0;
    float time = 0, last_time = 0;

    int score = 0;
    int game_state = 1;
    tile* snake = init_snake(2, 4, 0);
    tile* apple = init_apple(7, 4);
    int dir_buffer[2] = {-1,-1};

    draw_snake(snake, renderer);
    draw_apple(apple, renderer);

    render_screen(renderer);

    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT :
                    running = 0;
                    break;
                case SDL_KEYDOWN :
                    update_direction(event, snake, dir_buffer, &started);
            }
        }
        if (!started) { continue; }

        clock_t t = clock();
        time = (float)t / CLOCKS_PER_SEC;

        if (time >= last_time+INV_FPS) {
            last_time = time;

            if (dir_buffer[0] != -1) {
                snake->direction = dir_buffer[0];
                shift_buffer(1, dir_buffer);
            }
            game_state = step_forward(snake, apple);
            if (game_state == 0) { running = 0; }
            else if (game_state == 2) {
                score++;
                move_apple(snake, apple);
            }

            draw_snake(snake, renderer);
            draw_apple(apple, renderer);

            render_screen(renderer);
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    printf("\nscore : %d\n\n", score);
    return 0;
}