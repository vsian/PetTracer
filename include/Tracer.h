#ifndef TRACERAPPH
#define TRACERAPPH
#include "SDL_RenderApp.h"
#include "Sphere.h"
#include "Hitable_list.h"
#include "Camera.h"
#include "Drand48.h"
#include "Material.h"
#include "Ray_compute.h"
class TracerApp : public SDL_RenderApp{
    public:
        TracerApp() {
            list[0] = new sphere(Eigen :: Vector3f(0, 0, -1), 0.5, new lambertian(0.8, 0.3, 0.3));
            list[1] = new sphere(Eigen :: Vector3f(0, -100.5, -1), 100, new lambertian(0.8, 0.8, 0.0));
            list[2] = new sphere(Eigen :: Vector3f(1, 0, -1), 0.5, new metal(0.8, 0.6, 0.2, 0.0));
            list[3] = new sphere(Eigen :: Vector3f(-1, 0, -1), 0.5, new metal(0.8, 0.8, 0.8, 1.0));
            world = new hitable_list(list, 4);
            SDL_RenderApp :: Initialize();
        }
        hitable *list[4];
        hitable *world;
    private:
        Eigen :: Vector3f color(const Ray :: Ray& r, hitable* wrld, int depth);
        
        camera cam;
    protected:
        virtual bool onEvent(SDL_Event* evnt);
        virtual void onResize();
        virtual void onRender();
};
#endif