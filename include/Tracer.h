#ifndef TRACERAPPH
#define TRACERAPPH
#include "SDL_RenderApp.h"
#include "Eigen/Eigen"
#include "Ray.h"
class TracerApp : public SDL_RenderApp{
    public:
        TracerApp() {
            lower_f = Eigen :: Vector3f(-2.0, -1.0, -1.0);
            horizontal = Eigen :: Vector3f(4.0, 0.0, 0.0);
            vertical = Eigen :: Vector3f(0.0, 2.0, 0.0);
            origin = Eigen :: Vector3f(0.0, 0.0, 0.0);
            SDL_RenderApp :: Initialize();
        }
    private:
        Eigen :: Vector3f lower_f, horizontal, vertical, origin;
    protected:
        virtual bool onEvent(SDL_Event* evnt);
        virtual void onResize();
        virtual void onRender();
};
#endif