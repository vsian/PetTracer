#ifndef HITABLELISTH
#define HITABLELISTH

#include "Hitable.h"
class hitable_list : public hitable{
    public:
        hitable_list() {}
        hitable_list(hitable **l, int n) : list(l), list_size(n) {}
        virtual bool hit(const Ray :: Ray& r, float tmin, float tmax, hit_record& rec) const;
        hitable **list;
        int list_size;
};
#endif