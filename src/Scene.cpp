#include "Scene.hpp"

void Scene::SetObject( IObject* object ) {
	objects.Push( object );
}

uint32_t Scene::CountObjects() const {
	return objects.Count();
}

const IObject* Scene::GetObjectPtr( uint32_t i ) const {
	return objects[i];
}

Scene::~Scene() {
	for( uint32_t i = 0; i < objects.Count(); i++ ) {
		objects[i]->Delete();
	}
}
