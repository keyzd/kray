#include <stdint.h>

#include <stdio.h>

#include "CSGObject.hpp"
#include "Sphere.hpp"

CSGObject::CSGObject() {
}

void CSGObject::Union( IObject* obj, CSGObject* result ) {
	result->toUnion.Push( obj );
}

void CSGObject::Difference( IObject* obj, CSGObject* result ) {
	result->toDifference.Push( obj );
}

void CSGObject::Intersection( IObject* obj, CSGObject* result ) {
	result->toIntersection.Push( obj );
}

bool CSGObject::Intersect( const Ray &ray, Vec3 &hitPoint, List<float> *hitT ) const {
	List<bool> hitTable( false );
	List<bool> insideTable( false );

	List<Pair<float, IObject*>> hits;
//	List<float> hits;

	Vec3 tmpHP;
	List<float> objHT;

	bool flag = false;

	if( diffPrimary->Intersect( ray, tmpHP, &objHT ) ) {
		for( uint32_t j = 0; j < objHT.Count(); j++ ) {
			Pair<float, IObject*> newPair;
			newPair.SetPair( objHT[ j ], diffPrimary );
			hits.Push( newPair );
		}
		objHT.Clear();
	}

	for( uint32_t i = 0; i < toDifference.Count(); i++ ) { // Each object in CSG object
		if( toDifference[ i ]->Intersect( ray, tmpHP, &objHT ) ) { // ...intersect
			flag = true;
			for( uint32_t j = 0; j < objHT.Count(); j++ ) { // ...and push all points into shared pull.
				Pair<float, IObject*> newPair;
				newPair.SetPair( objHT[ j ], toDifference[ i ] );
				hits.Push( newPair );
			}
			objHT.Clear();
		}
	}

	return flag;
}

Vec3 CSGObject::GetNormatAt( const Vec3 &hitPoint ) const {
	return Vec3( 0.0f );
}

void CSGObject::SortHitPoints( List<Pair<float, IObject*>> *hits ) const {
}
