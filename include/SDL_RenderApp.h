#ifndef SDLRENDERAPPH
#define SDLRENDERAPPH
#include <iostream>
#include "SDL2/SDL.h"
class SDL_RenderApp {
    protected:
        unsigned int width = 800, height = 600;
        SDL_Window *window;
        SDL_Renderer *renderer;
        bool quit = false;
        SDL_Event event;
    public:
        SDL_RenderApp() {}
        bool Initialize();
        void Run();
        virtual bool onResize();
        virtual bool onEvent(SDL_Event* evnt);
        virtual bool onRender();
        ~SDL_RenderApp() {
            SDL_DestroyWindow(window);
            SDL_DestroyRenderer(renderer);
        }
};
#endif