#pragma once

#include "../math/Ray.hpp"

class Scene;

struct ShadeRecord {
	Vec3 hitPoint;
	Vec3 normal;
	Ray ray;
	int depth;
	const Scene& scene;

	ShadeRecord( const Scene& a_scene );
	ShadeRecord( const ShadeRecord& sr );
};

inline ShadeRecord::ShadeRecord( const Scene& a_scene ) :
	hitPoint(), normal(), ray(), depth( 0 ), scene(a_scene)
{}

inline ShadeRecord::ShadeRecord( const ShadeRecord& sr ) :
	hitPoint( sr.hitPoint ), normal( sr.normal ), ray( sr.ray ), depth( sr.depth ), scene( sr.scene )
{}
