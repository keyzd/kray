#pragma once

#include "IMaterial.hpp"

class MaterialNormalMap : public IMaterial {
public:
	MaterialNormalMap() {}

	virtual Vec3 Shade( const ShadeRecord& shadeRec ) const;

protected:
	virtual ~MaterialNormalMap() {}
};

inline Vec3 MaterialNormalMap::Shade( const ShadeRecord& shadeRec ) const {
	return normalize( shadeRec.normal );
}
