#include "Tracer.h"

const float INF = std::numeric_limits<float>::infinity();

Eigen :: Vector3f TracerApp :: random_in_unit_shpere() {
    Eigen :: Vector3f p;
    do {
        p = Eigen :: Vector3f(drand48(), drand48(), drand48()) - Eigen :: Vector3f(1, 1, 1);
    }while((p[0] * p[0] + p[1] * p[1] + p[2] * p[2]) >= 1.0);
    return p;
}

Eigen :: Vector3f TracerApp :: color(const Ray :: Ray& r, hitable* wrld) {
    hit_record rec;
    if(wrld -> hit(r, 0.001, INF, rec)) {
        Eigen :: Vector3f target = rec.p + rec.normal + random_in_unit_shpere();
        return 0.5 * color( Ray :: Ray(rec.p, target - rec.p), wrld);
    }
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
    for (int j = height; j >= 0; --j) {
        int i = 0;
        for (; i < width; ++i) {
            float u = (float)(i) / (float)width;
            float v = 1 - (float)(j) / (float)height;
            Ray :: Ray r = cam.getRay(u, v);
            Eigen :: Vector3f col = color(r, world);
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