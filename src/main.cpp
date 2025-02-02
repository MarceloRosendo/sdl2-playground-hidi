#include <SDL2/SDL.h>
#include <iostream>
#include "screens/window.h"
#include "objects/square.h"

using namespace N;

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError();
        return 1;
    }
    Window window("SDL Window");
    SDL_Renderer* renderer = SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED); 
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    
    bool run = true;

    int x = 0;
    int y = 0;

    Square square(x, y, 50, 50);

    square.draw(renderer);

    SDL_RenderPresent(renderer);

    SDL_Delay(1000);

    while(run) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                run = false;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym)
                {
                    case SDLK_LEFT:
                        square.left();
                        std::cout << "Left" << std::endl;
                        break;
                    case SDLK_RIGHT:
                        square.right();
                        std::cout << "Right" << std::endl;
                        break;
                    case SDLK_UP:
                        std::cout << "Up" << std::endl;
                        square.up();
                        break;
                    case SDLK_DOWN:
                        std::cout << "Down" << std::endl;
                        square.down();
                        break;
                    case SDLK_ESCAPE:
                        run = false;
                        break;
                }
                square.draw(renderer);   
                SDL_RenderClear(renderer);
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                SDL_RenderFillRect(renderer, &square);
            }
            SDL_RenderPresent(renderer);
        }
    }

    SDL_Quit();

    return 0;
}