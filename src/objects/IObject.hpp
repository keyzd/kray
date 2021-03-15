#pragma once

#include <stdio.h>

#include "../math/Ray.hpp"
#include "../materials/IMaterial.hpp"
#include "../utils/List.hpp"

class CSGObject;

class IObject {
public:
	IObject() {}

	void Delete() {
		if( *material != 0 ) {
			(*material)->Delete();
			*material = 0;
		}
		delete this;
	}

	virtual bool Intersect( const Ray &ray, Vec3 &hitPoint, List<float> *hitT ) const = 0;
	virtual Vec3 GetNormatAt( const Vec3 &hitPoint ) const = 0;

	void SetMaterial( IMaterial*& a_material );
	const IMaterial& GetMaterial() const;

	void Union( IObject* obj, CSGObject* result );
	void Difference( IObject* obj, CSGObject* result );
	void Intersection( IObject* obj, CSGObject* result );

protected:
	virtual ~IObject() {}

	IMaterial** material;
};

