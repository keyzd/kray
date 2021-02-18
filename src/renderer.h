#pragma once

#include "Framebuffer.h"
#include "math/Ray.h"
#include "Scene.h"

void R_UpdateFrame( const Scene &scene, Framebuffer &fb );

Vec3 R_Trace( const Scene &scene, const Ray &ray, float tMin, float tMax );

const IObject* R_FindClosestObject( const Scene &scene, const Ray &ray, float tMin, float tMax );

Vec3 R_Miss();

// TraverseAccelerationStructure();
