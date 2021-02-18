#pragma once

#include "IMaterial.h"

class MaterialMatte : public IMaterial {
public:
	MaterialMatte() {}

	virtual Vec3 Shade( const ShadeRecord& shadeRec ) const;

protected:
	virtual ~MaterialMatte() {}

	Vec3 AmbientBRDF() const;
	Vec3 DiffuseBRDF() const;

	float kDiff;

};
