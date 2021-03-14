#pragma once

#include "../Scene.hpp"
#include "../Framebuffer.hpp"

class ICamera {
public:
	virtual void RenderScene( const Scene &scene, Framebuffer &fb ) = 0;
protected:
};
