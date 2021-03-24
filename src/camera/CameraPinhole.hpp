#pragma once

#include "ICamera.hpp"

class CameraPinhole : public ICamera {
public:
	virtual void RenderScene( const Scene &scene, Framebuffer &fb, IRenderer &renderer );
private:
};
