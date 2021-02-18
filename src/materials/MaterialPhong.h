#pragma once

#include "IMaterial.h"

class MaterialPhong : public IMaterial {
public:
	MaterialPhong() {}

	virtual Vec3 Shade( const ShadeRecord& shadeRec ) const;

protected:
	virtual ~MaterialPhong() {}

	Vec3 AmbientBRDF() const;
	Vec3 DiffuseBRDF() const;
	Vec3 SpecularBRDF() const;

	float kDiff;
	float kSpec;

};