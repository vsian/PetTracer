#ifndef CAMERAH
#define CAMERAH
#include "Ray.h"
#include <random>
class camera {
    public:
        camera() {
            lower_f = Eigen :: Vector3f(-2.0, -1.5, -1.0);
            horizontal = Eigen :: Vector3f(4.0, 0.0, 0.0);
            vertical = Eigen :: Vector3f(0.0, 3.0, 0.0);
            origin = Eigen :: Vector3f(0.0, 0.0, 0.0);
        }
        Eigen :: Vector3f lower_f, horizontal, vertical, origin;
        Ray :: Ray getRay(float u, float v);
};
#endif