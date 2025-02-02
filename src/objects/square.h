#ifndef SQUARE_H
#define SQUARE_H

#include <SDL2/SDL.h>

class Square : public SDL_Rect {
public:
    Square(int x, int y, const int w, const int h);
    void draw(SDL_Renderer* renderer);
    void left();
    void right();
    void up();
    void down();
};

#endif // SQUARE_H