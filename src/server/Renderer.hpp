#pragma once

#include "IRenderer.hpp"

#define CLOSEST_DEFAULT_INDEX -1

class Renderer : public IRenderer {
public:
	Vec3 R_Trace( const Scene &scene, const Ray &ray, float tMin, float tMax );
	const IObject* R_FindClosestObject( const Scene &scene, const Ray &ray, float tMin, float tMax );
	Vec3 R_Miss();
// TraverseAccelerationStructure();
};

