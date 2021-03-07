/*
 *	PpmImage exports Portable PixMap file (0-255 colors for each RGB channel)
 *	NOTE: color represents in 3d-vector with normalized components (0.0-1.0)
 */

#pragma once

#include <stdio.h>
#include <stdint.h>

#include "math/Vec3.hpp"

class PpmImage {
public:
	PpmImage( const uint32_t a_width, const uint32_t a_height, const char* ppmFilePath );
	~PpmImage();

	uint32_t GetWidth() const;
	uint32_t GetHeight() const;

	void SetPixel( Vec3 pixel, uint32_t x, uint32_t y );
	Vec3 GetPixel( uint32_t x, uint32_t y ) const;

	bool SetBuf( const uint32_t* a_buf, const uint32_t bufLen );

private:
	Vec3 *pixel_buf;
	FILE *file_ppm;
	uint32_t width, height;

	void WriteBufferToFile();
	void WritePixelToFile( Vec3 pixel );
};

inline uint32_t PpmImage::GetWidth() const {
	return width;
}

inline uint32_t PpmImage::GetHeight() const {
	return height;
}

