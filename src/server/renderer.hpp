#pragma once

#include "../Framebuffer.hpp"
#include "../math/Ray.hpp"
#include "../Scene.hpp"

#define CLOSEST_DEFAULT_INDEX -1

void R_UpdateFrame( const Scene &scene, Framebuffer &fb );

Vec3 R_Trace( const Scene &scene, const Ray &ray, float tMin, float tMax );

const IObject* R_FindClosestObject( const Scene &scene, const Ray &ray, float tMin, float tMax );

Vec3 R_Miss();

// TraverseAccelerationStructure();
