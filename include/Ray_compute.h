#ifndef RAYCOMPUTEH
#define RAYCOMPUTEH
#include "Drand48.h"
#include "Eigen/Eigen"
Eigen :: Vector3f random_in_unit_shpere();
Eigen :: Vector3f reflect(const Eigen :: Vector3f& r_in, const Eigen :: Vector3f& norm);
Eigen :: Vector3f coeffproduct(const Eigen :: Vector3f& lhs, const Eigen :: Vector3f& rhs);
#endif