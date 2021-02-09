#include "Hitable_list.h"
bool hitable_list :: hit(const Ray :: Ray& r, float tmin, float tmax, hit_record& rec) const {
    hit_record rc;
    bool hit_anything = false;
    float closest_so_far = tmax;
    for(int i = 0; i < list_size; ++i) {
        if(list[i] -> hit(r, tmin, closest_so_far, rc)) {
            hit_anything = true;
            closest_so_far = rc.t;
            rec = rc;
        }
    }
    return hit_anything;
}