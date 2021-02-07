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
            //std :: cout << col << "\n";
            if(SDL_SetRenderDrawColor(renderer, (int)(col[0] * 255.0), (int)(col[1] * 255.0), (int)(col[2] * 255.0), 255) < 0) {
                std :: cout << "Set draw color error!\n";
            }
        }
        if(SDL_RenderDrawPoint(renderer, i, j) < 0) {
            std :: cout << "Draw point error!\n";
        }
    }
    SDL_RenderPresent(renderer);
}