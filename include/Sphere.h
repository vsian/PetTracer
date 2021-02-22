#ifndef SPHEREH
#define SPHEREH
#include "Hitable.h"
class sphere : public hitable{
    public:
        sphere(){}
        sphere(Eigen :: Vector3f cen, float r, material* mp) : center(cen), radius(r), mat_ptr(mp) {}
        material* mat_ptr;
        Eigen :: Vector3f center;
        float radius;
        virtual bool hit(const Ray :: Ray& r, float tmin, float tmax, hit_record& rec) const;
};
#endif