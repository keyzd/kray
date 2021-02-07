#include "Framebuffer.h"

Framebuffer::Framebuffer(uint32_t a_width, uint32_t a_height) {
	width = a_width;
	height = a_height;
	buf = new uint32_t[width * height];
}

Framebuffer::~Framebuffer() {
	delete [] buf;
}

void Framebuffer::SetPixel( uint32_t pixel, uint32_t x, uint32_t y ) {
	buf[x + y * width] = pixel;
}

uint32_t Framebuffer::GetPixel( uint32_t x, uint32_t y ) const {
	return buf[x + y * width];
}
