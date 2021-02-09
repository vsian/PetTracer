#ifndef TRACERAPPH
#define TRACERAPPH
#include "SDL_RenderApp.h"
#include "Sphere.h"
#include "Hitable_list.h"
#include "Camera.h"
#include "Drand48.h"
class TracerApp : public SDL_RenderApp{
    public:
        TracerApp() {
            list[0] = new sphere(Eigen :: Vector3f(0, 0, -1), 0.5);
            list[1] = new sphere(Eigen :: Vector3f(0, -100.5, -1), 100);
            world = new hitable_list(list, 2);
            SDL_RenderApp :: Initialize();
        }
        hitable *list[2];
        hitable *world;
    private:
        Eigen :: Vector3f color(const Ray :: Ray& r, hitable* wrld);
        Eigen :: Vector3f random_in_unit_shpere();
        camera cam;
    protected:
        virtual bool onEvent(SDL_Event* evnt);
        virtual void onResize();
        virtual void onRender();
};
#endif