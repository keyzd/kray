#pragma once

#include "../math/Ray.h"
#include "../materials/IMaterial.h"

class IObject {
public:
	IObject() {}

	void Delete() {
		delete this;
	}

	virtual bool Intersect( const Ray &ray, Vec3 &intersectAt ) const = 0;
	virtual Vec3 GetNormatAt( const Vec3 &intersectAt ) const = 0;

	void SetMaterial( IMaterial* a_material );
	IMaterial* GetMaterial() const;

protected:
	virtual ~IObject() {}

	IMaterial* material;
};

inline void IObject::SetMaterial( IMaterial* a_material ) {
	material = a_material;
}

inline IMaterial* IObject::GetMaterial() const {
	return material;
}

