#pragma once

#include "IMaterial.hpp"

class MaterialPhong : public IMaterial {
public:
	MaterialPhong() {}
	virtual Vec3 Shade( const ShadeRecord& shadeRec ) const;

private:
	virtual ~MaterialPhong() {}

	Vec3 AmbientBRDF() const;
	Vec3 DiffuseBRDF() const;
	Vec3 SpecularBRDF() const;

	float kDiff;
	float kSpec;

};
