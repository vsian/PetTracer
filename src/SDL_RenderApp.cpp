#include"SDL_RenderApp.h"
bool SDL_RenderApp :: Initialize() {
    window = SDL_CreateWindow("demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if(window == NULL) {
        std :: cout << "window creation failed!\n";
        quit = true;
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL) {
        std :: cout << "renderer creation failed!\n";
        quit = true;
        return false;
    }
}
void SDL_RenderApp :: Run() {
    while(!quit) {
        while(!SDL_PollEvent(&event)) {
            if(!onEvent(&event)) {
                quit = true;
                break;
            }
        }
        if(quit) {
            onRender();
            SDL_RenderPresent(renderer);
        }
    }
    SDL_Quit();
}