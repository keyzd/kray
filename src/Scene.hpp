#pragma once

#include <stdint.h>

#include "utils/List.hpp"
#include "objects/IObject.hpp"

class Scene {
public:

	void SetObject( IObject* object );
	const IObject* GetObjectPtr( uint32_t i ) const;

	uint32_t CountObjects() const;

	~Scene();

private:
	List<IObject*> objects;
};

inline void Scene::SetObject( IObject* object ) {
	objects.Push( object );
}

inline uint32_t Scene::CountObjects() const {
	return objects.Count();
}

inline const IObject* Scene::GetObjectPtr( uint32_t i ) const {
	return objects[ i ];
}

inline Scene::~Scene() {
	for( uint32_t i = 0; i < objects.Count(); i++ ) {
		objects[ i ]->Delete();
	}
}
