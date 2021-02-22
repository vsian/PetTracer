#include "Ray_compute.h"
Eigen :: Vector3f random_in_unit_shpere() {
    Eigen :: Vector3f p;
    do {
        p = Eigen :: Vector3f(drand48(), drand48(), drand48()) - Eigen :: Vector3f(1, 1, 1);
    }while((p[0] * p[0] + p[1] * p[1] + p[2] * p[2]) >= 1.0);
    return p;
}

Eigen :: Vector3f reflect(const Eigen :: Vector3f& r_in, const Eigen :: Vector3f& norm) {
    return r_in - 2 * r_in.dot(norm) * norm;
}

Eigen :: Vector3f coeffproduct(const Eigen :: Vector3f& lhs, const Eigen :: Vector3f& rhs) {
    return Eigen :: Vector3f(lhs.x() * rhs.x(), lhs.y() * rhs.y(), lhs.z() * rhs.z());
}