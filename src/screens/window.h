#include <SDL2/SDL.h>

namespace N {
    class Window {
    public:
        SDL_Window* window;
        Window(const char* title);
        ~Window();
        SDL_Window* get();
    };    
}
