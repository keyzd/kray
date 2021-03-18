#pragma once

#include "LMap.hpp"

class LMapTranslate : public LMap {
public:
	LMapTranslate() {}
	LMapTranslate( const Vec3 &delta );

private:
};
