#ifndef HITABLEH
#define HITABLEH
#include "Ray.h"
struct hit_record {
    float t;
    Eigen :: Vector3f p, normal;
};
class hitable {
    public:
        virtual bool hit(const Ray :: Ray& r, float tmin, float tmax, hit_record& rec) const = 0;
};
#endif