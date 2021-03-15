/*
 * Constructive solid geomentry object
 */

#pragma once

#include "../utils/List.hpp"
#include "../utils/Pair.hpp"
#include "../math/Vec3.hpp"
#include "../math/Ray.hpp"
#include "IObject.hpp"

class CSGObject : public IObject {
public:
	CSGObject();

	virtual bool Intersect( const Ray &ray, Vec3 &hitPoint, List<float> *hitT ) const;
	virtual Vec3 GetNormatAt( const Vec3 &hitPoint ) const;
	
	void Union( IObject* obj, CSGObject* result );
	void Difference( IObject* obj, CSGObject* result );
	void Intersection( IObject* obj, CSGObject* result );

	List<IObject*> toUnion;
	List<IObject*> toDifference;
	List<IObject*> toIntersection;

	IObject* diffPrimary;

private:
	virtual ~CSGObject() {}

	void SortHitPoints( List<Pair<float, IObject*>> *hits ) const;

};
