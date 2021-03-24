#pragma once

#include "../Framebuffer.hpp"
#include "../math/Ray.hpp"
#include "../Scene.hpp"

#include "../common.hpp"

class IRenderer {
public:
	virtual Vec3 R_Trace( const Scene &scene, const Ray &ray, float tMin, float tMax ) = 0;
};
