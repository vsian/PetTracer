#include "Tracer.h"

const float INF = std::numeric_limits<float>::infinity();

Eigen :: Vector3f TracerApp :: color(const Ray :: Ray& r, hitable* wrld, int depth) {
    hit_record rec;
    if(wrld -> hit(r, 0.001, INF, rec)) {
        Ray :: Ray scattered;
        Eigen :: Vector3f attenuation;
        if(depth < 50 && rec.mat_ptr -> scatter(r, rec, attenuation, scattered)) {
            return coeffproduct(attenuation, color(scattered, wrld, depth + 1));
        }
        return Eigen :: Vector3f(0, 0, 0);
    }
    else {
        Eigen :: Vector3f unit_dir = r.direction().normalized();
        float t = 0.5 * (unit_dir.y() + 1.0);
        return (1.0 - t) * Eigen :: Vector3f(1.0, 1.0, 1.0) + t * Eigen :: Vector3f(0.5, 0.7, 1.0);
    }
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
    for (int j = height; j >= 0; --j) {
        int i = 0;
        for (; i < width; ++i) {
            float u = (float)(i + drand48()) / (float)width;
            float v = 1 - (float)(j + drand48()) / (float)height;
            Ray :: Ray r = cam.getRay(u, v);
            Eigen :: Vector3f col = color(r, world, 0);
            col = Eigen :: Vector3f( sqrt(col[0]), sqrt(col[1]), sqrt(col[2]) );
            //std :: cout << col << "\n";
            if(SDL_SetRenderDrawColor(renderer, (int)(col[0] * 255.0), (int)(col[1] * 255.0), (int)(col[2] * 255.0), 255) < 0) {
                std :: cout << "Set draw color error!\n";
            }
            if(SDL_RenderDrawPoint(renderer, i, j) < 0) {
                std :: cout << "Draw point error!\n";
            }
            //std :: cout << (int)(col[0] * 255.0) << " " << (int)(col[1] * 255.0) << " " << (int)(col[2] * 255.0) << "\n";
        }
    }
    SDL_RenderPresent(renderer);
}