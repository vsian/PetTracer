#include "Tracer.h"

Eigen :: Vector3f color(const Ray :: Ray& r) {
    Eigen :: Vector3f unit_dir = r.direction().normalized();
    float t = 0.5 * (unit_dir.y() + 1.0);
    return (1.0 - t) * Eigen :: Vector3f(1.0, 1.0, 1.0) + t * Eigen :: Vector3f(0.5, 0.7, 1.0);
}

bool TracerApp :: onEvent(SDL_Event* evnt) {
    switch (evnt -> type)
    {
    case SDL_QUIT:
        return false;
    default:
        return true;
    }
}

void TracerApp :: onResize() {

}

void TracerApp :: onRender() {
    for (int j = height - 1; j >= 0; --j) {
        int i = 0;
        for (; i < width; ++i) {
            float u = (float)i / (float)width;
            float v = (float)j / (float)height;
            Ray :: Ray r(origin, lower_f + u * horizontal + v * vertical);
            Eigen :: Vector3f col = color(r);
            SDL_SetRenderDrawColor(SDL_RenderApp :: renderer, int(col[0] * 255.99), int(col[1] * 255.99), int(col[2] * 255.99), 255);
        }
        SDL_RenderDrawPoint(SDL_RenderApp :: renderer, i, j);
    }
    SDL_RenderPresent(renderer);
}