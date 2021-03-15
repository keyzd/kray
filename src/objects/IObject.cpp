#include "IObject.hpp"
#include "CSGObject.hpp"

void IObject::SetMaterial( IMaterial*& a_material ) {
	material = &a_material;
}

const IMaterial& IObject::GetMaterial() const {
	return **material;
}

void IObject::Union( IObject* obj, CSGObject* result ) {
	result->toUnion.Push( obj );
}

void IObject::Difference( IObject* obj, CSGObject* result ) {
	result->toDifference.Push( obj );
	result->diffPrimary = this;
}

void IObject::Intersection( IObject* obj, CSGObject* result ) {
	result->toIntersection.Push( obj );
}

