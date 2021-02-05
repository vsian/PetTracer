#ifndef TRACERAPPH
#define TRACERAPPH
#include "SDL_RenderApp.h"
#include "Eigen/Eigen"
#include "Ray.h"
class TracerApp : public SDL_RenderApp{
    public:
        TracerApp() {}
        bool Initialize();
    private:
        Eigen :: Vector3f lower_f, horizontal, vertical, origin;
};
#endif