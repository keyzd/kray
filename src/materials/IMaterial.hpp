#pragma once

#include "../math/Vec3.hpp"
#include "ShadeRecord.hpp"

class IMaterial {
public:
	IMaterial() {}

	virtual Vec3 Shade( const ShadeRecord& shadeRec ) const = 0;

protected:
	virtual ~IMaterial() {}
};
