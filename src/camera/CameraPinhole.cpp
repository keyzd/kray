#include "CameraPinhole.hpp"
#include "../server/renderer.hpp"

#include "../common.hpp"

void CameraPinhole::RenderScene( const Scene &scene, Framebuffer &fb ) {
	float ar = float( fb.GetWidth() ) / float( fb.GetHeight() );
	float w = fb.GetWidth();
	float h = fb.GetHeight();

	for( uint32_t y = 0; y < h; y++ ) {
		for( uint32_t x = 0; x < w; x++ ) {
			float u = float( x*2.0f ) / w - 1.0f;
			float v = float( y*2.0f ) / h - 1.0f;
			u *= ar;
			v *= -1.0f;
			Ray ray( Vec3( 0.0f ), normalize( Vec3( u, v, 1.0f ) ) );
			Vec3 color = R_Trace( scene, ray, 0.0f, INFINITY );

			uint8_t r = color.r * 255.0f;
			uint8_t g = color.g * 255.0f;
			uint8_t b = color.b * 255.0f;
			fb.SetPixel( PACK_COLOR( r, g, b ), x, y );
		}
	}
}
