#pragma once

#include <stdint.h>

class Framebuffer {
public:
	Framebuffer(uint32_t a_width, uint32_t a_height);
	~Framebuffer();

	uint32_t GetWidth() const;
	uint32_t GetHeight() const;

	void SetPixel( uint32_t pixel, uint32_t x, uint32_t y );
	uint32_t GetPixel( uint32_t x, uint32_t y ) const;

	uint32_t* buf;
	uint32_t width, height;
};

inline uint32_t Framebuffer::GetWidth() const {
	return width;
}

inline uint32_t Framebuffer::GetHeight() const {
	return height;
}
