#ifndef MATERIALH
#define MATERIALH
#include "Ray.h"
#include "Ray_compute.h"
struct hit_record;

class material {
    public:
        virtual bool scatter(const Ray :: Ray& r_in, const hit_record& rec, Eigen :: Vector3f& attenuation, Ray :: Ray& scattered) const = 0;
};

class lambertian : public material {
    public:
        Eigen :: Vector3f albedo;
        lambertian(const Eigen :: Vector3f& alb) : albedo(alb) {}
        lambertian(float A, float B, float C) : albedo(Eigen :: Vector3f(A, B, C)) {}
        virtual bool scatter(const Ray :: Ray& r_in, const hit_record& rec, Eigen :: Vector3f& attenuation, Ray :: Ray& scattered) const {
            Eigen :: Vector3f target = rec.p + rec.normal + random_in_unit_shpere();
            scattered = Ray :: Ray(rec.p, target - rec.p);
            attenuation = albedo;
            return true;
        }
};

class metal : public material {
    public:
        Eigen :: Vector3f albedo;
        float fuzz;
        metal(const Eigen :: Vector3f& alb, float f) : albedo(alb) ,fuzz(f < 1 ? f : 1){}
        metal(float A, float B, float C, float f) : albedo(Eigen :: Vector3f(A, B, C)) ,fuzz(f < 1 ? f : 1){}
        virtual bool scatter(const Ray :: Ray& r_in, const hit_record& rec, Eigen :: Vector3f& attenuation, Ray :: Ray& scattered) const {
            Eigen :: Vector3f reflected = reflect(r_in.direction().normalized(), rec.normal);
            scattered = Ray :: Ray(rec.p, reflected + fuzz * random_in_unit_shpere());
            attenuation = albedo;
            return (scattered.direction().dot(rec.normal) > 0);
        }
};

#endif