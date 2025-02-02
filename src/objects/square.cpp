#include "square.h"
#include <SDL2/SDL.h>
#include <iostream>

Square::Square(int x, int y, int w, int h) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

void Square::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 200, 200, 255);
    SDL_RenderFillRect(renderer, this);
}

void Square::left() {
    this->x -= 10;
}

void Square::right() {
    this->x += 10;
}

void Square::up() {
    this->y -= 10;
}

void Square::down() {
    this->y += 10;
}