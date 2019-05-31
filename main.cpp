// As of 29 May 2019, all this does is show a large black window.
// I've only tested it on Linux; idk if it'll work on Windows/Mac.
// Compile with the following:
// g++ main.cpp `pkg-config --cflags --libs sdl2`

#include <SDL2/SDL.h>
#include <iostream>
/* TODO: create some header files
where I define the classes for particles. */

#define RED    255, 0, 0
#define YELLOW 255, 255, 0
#define GREEN  0, 255, 70
#define BLUE   32, 32, 255

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

    /* TODO: put state info here */

    while (window_open) {
        SDL_SetRenderDrawColor(renderer, BLACK, 0);
        SDL_RenderClear(renderer);
        /* TODO: put some code here to show the menu bar. */
        SDL_RenderPresent(renderer);

        /* state modification goes here */

        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                window_open = false;
                break;
            /* other cases go here */
        }
    }

    /* if any heap memory was allocated, free it here */
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(main_window);
    SDL_Quit();
    return 0;
}
