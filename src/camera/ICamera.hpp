#pragma once

#include "../Scene.hpp"
#include "../Framebuffer.hpp"
#include "../server/IRenderer.hpp"

class ICamera {
public:
	virtual void RenderScene( const Scene &scene, Framebuffer &fb, IRenderer &renderer ) = 0;
protected:
};
