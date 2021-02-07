#pragma once

#include "math/Ray.h"

class IObject {
public:
	IObject() {}

	void Delete() {
		delete this;
	}

	virtual bool Intersect( const Ray &ray, Vec3 &intersectAt ) const = 0;
	virtual Vec3 GetNormatAt( const Vec3 &intersectAt ) const = 0;

private:
	virtual ~IObject() {}
};
