#include "Sphere.h"
bool sphere :: hit(const Ray :: Ray& r, float tmin, float tmax, hit_record& rec) const {
    Eigen :: Vector3f oc = r.origin() - center;
    float a = r.direction().dot(r.direction());
    float b = 2.0 * r.direction().dot(oc);
    float c = oc.dot(oc) - radius * radius;
    float discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        float sol_part_1 = (sqrt(discriminant)) / (2.0 * a);
        float sol_part_2 = -b / (2.0 * a);
        float sol = sol_part_2 - sol_part_1;
        if(sol < tmax && sol > tmin) {
            rec.t = sol;
            rec.p = r.point_at_parameter(sol);
            rec.normal = (rec.p - center) / radius;
            return true;
        }
        sol = sol_part_2 + sol_part_1;
        if(sol < tmax && sol > tmin) {
            rec.t = sol;
            rec.p = r.point_at_parameter(sol);
            rec.normal = (rec.p - center) / radius;
            return true;
        }
    }
    return false;
}