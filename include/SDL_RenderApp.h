#ifndef SDLRENDERAPPH
#define SDLRENDERAPPH
#include <iostream>
#include "SDL2/SDL.h"
class SDL_RenderApp {
    protected:
        bool rendered = false;
        unsigned int width = 800, height = 600;
        SDL_Window *window;
        SDL_Renderer *renderer;
        bool quit = false;
        SDL_Event event;
        virtual bool onEvent(SDL_Event* evnt) = 0;
        virtual void onResize() = 0;
        virtual void onRender() = 0;
    public:
        SDL_RenderApp() {}
        virtual bool Initialize();
        void Run();
        ~SDL_RenderApp() {
            SDL_DestroyWindow(window);
            SDL_DestroyRenderer(renderer);
        }
};
#endif