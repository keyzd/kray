#pragma once

#include "LMap.hpp"

class LMapScale : public LMap {
public:
	LMapScale() {}
	LMapScale( float x, float y, float z );
	LMapScale( float t );
private:
};
