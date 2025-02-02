#include "window.h"
#include <SDL2/SDL.h>

using namespace N;


Window::Window(const char* title) {
    window = SDL_CreateWindow(title, 0, 0, 800, 600,
                                          SDL_WINDOW_SHOWN);
}

Window::~Window() {
    SDL_DestroyWindow(window);
}

SDL_Window* Window::get() {
    return window;
}