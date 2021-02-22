#ifndef HITABLEH
#define HITABLEH
#include "Ray.h"
#include "Drand48.h"

Eigen :: Vector3f random_in_unit_shpere();

Eigen :: Vector3f reflect(const Eigen :: Vector3f& r_in, const Eigen :: Vector3f& norm);

class material;

struct hit_record {
    float t;
    Eigen :: Vector3f p, normal;
    material* mat_ptr;
};

class hitable {
    public:
        virtual bool hit(const Ray :: Ray& r, float tmin, float tmax, hit_record& rec) const = 0;
};
#endif