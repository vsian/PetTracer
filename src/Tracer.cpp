#include "Tracer.h"
bool TracerApp :: Initialize() {
    lower_f = Eigen :: Vector3f(-2.0, -1.5, -1.0);
    horizontal = Eigen :: Vector3f(4.0, 0.0, 0.0);
    vertical = Eigen :: Vector3f(0.0, 3.0, 0.0);
    origin = Eigen :: Vector3f(0.0, 0.0, 0.0);
    return SDL_RenderApp :: Initialize();
}
