#include "Camera.h"
Ray :: Ray camera :: getRay(float u, float v) {
    return Ray :: Ray(origin, lower_f + u * horizontal + v * vertical);
}