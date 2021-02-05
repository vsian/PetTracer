#ifndef RAYH
#define RAYH
#include "Eigen/Eigen"
namespace Ray {
    using namespace Eigen;
    class Ray {
        public:
            Ray() {}
            Ray(const Vector3f& a, const Vector3f& b) : A(a), B(b) {}
            Vector3f origin() const { return A; }
            Vector3f direction() const { return B; }
            Vector3f point_at_parameter(float t) {return A + t * B; }
            Vector3f A;
            Vector3f B;
    };
}
#endif