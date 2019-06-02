// As of 1 June 2019, this shows a window with a cursor and a menubar.
// The only thing in the menubar is a copyright & licensing notice.
// I've only tested it on Linux; idk if it'll work on Windows/Mac.
// Compile with the following:
// g++ main.cpp `pkg-config --cflags --libs sdl2`

#ifndef SDL2_SDL_H
#define SDL2_SDL_H
#include <SDL2/SDL.h>
#endif // SDL2_SDL_H

#include <iostream>
#include <sstream>
#include "djf-SDL-text.h"
#include "air.hpp"

#define RED    255, 0, 0
#define YELLOW 255, 255, 0
#define GREEN  0, 255, 70
#define BLUE   32, 32, 255

#define METAL  64, 64, 64

#define WHITE  255, 255, 255
#define GREY   128, 128, 128
#define BLACK  0, 0, 0

int main() {
    SDL_Renderer *renderer;
    SDL_Window *main_window;
    SDL_Init(SDL_INIT_VIDEO);
    main_window = SDL_CreateWindow(
        "Powder Game 3",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000,
        600,
        0
    );
    renderer = SDL_CreateRenderer(
        main_window,
        0,
        0
    );
    if (main_window == NULL || renderer == NULL) {
        std::cout << "Error! Something went horribly wrong!\n";
        std::cout << "Error: " << SDL_GetError() << '\n';
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(main_window);
        SDL_Quit();
        return 1;
    }

    bool window_open = true;
    SDL_Event event;

    CoordPair cursor;
    cursor.x = 0;
    cursor.y = 0;

    AirCell air[40][100];
    for (int y = 0; y < 40; ++y) {
        for (int x = 0; x < 100; ++x) {
            air[y][x].set_position(x * 10, y * 10);
        }
    }
    while (window_open) {
        SDL_ShowCursor(SDL_DISABLE);
        SDL_SetRenderDrawColor(renderer, BLACK, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, METAL, 255);
        SDL_Rect menu_bg {0, 400, 1000, 200};
        SDL_RenderFillRect(renderer, &menu_bg);

        render_string(
            renderer,
            350,
            580,
            "COPYRIGHT (C) 2019 BY DANTE FALZONE UNDER GNU GPL 3.0",
            53,
            BLACK,
            255
        );

        SDL_SetRenderDrawColor(renderer, RED, 255);
        SDL_RenderDrawLine(renderer, cursor.x, cursor.y, cursor.x - 0xF, cursor.y + 0xF);
        SDL_RenderDrawLine(renderer, cursor.x, cursor.y + 2, cursor.x, cursor.y);
        SDL_RenderDrawLine(renderer, cursor.x - 2, cursor.y, cursor.x, cursor.y);
        SDL_RenderPresent(renderer);

        /* state modification goes here */

        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                window_open = false;
                break;
            case SDL_MOUSEMOTION:
                cursor.x = event.motion.x;
                cursor.y = event.motion.y;
                std::stringstream ss;
                ss << "X: " << cursor.x << " Y: " << cursor.y;
                SDL_SetWindowTitle(main_window, ss.str().c_str());
                break;
        }
    }

    /* if any heap memory was allocated, free it here */
    SDL_ShowCursor(SDL_ENABLE);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(main_window);
    SDL_Quit();
    return 0;
}
