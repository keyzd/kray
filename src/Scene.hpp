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

