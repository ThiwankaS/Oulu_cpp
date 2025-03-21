#include "RGBA/png.h"
#include "RGBA/rgbapixel.h"

#include <string>
#include <cmath>

void rotate(const std::string & inputFile, const std::string & outputFile) {
	PNG pic(inputFile);
	PNG rotatedPic(pic.height(), pic.width());
	for (size_t x = 0; x < pic.width(); ++x) {
		for (size_t y = 0; y < pic.height(); ++y) {
			rotatedPic(y, rotatedPic.height()- x - 1) = pic(x, y);
		}
	}
	rotatedPic.writeToFile(outputFile);
}

PNG myArt(unsigned int width, unsigned int height) {
	PNG png(width, height);
	for(size_t x = 0; x < png.width(); ++x) {
		for(size_t y = 0; y < png.height(); ++y) {
			png(x, y).red = (x * 128) / width;
			png(x, y).green = (x * 255) / height;
			png(x, y).blue = (x * 32) / width;
			png(x, y).alpha = 64;
		}
	}

	return png;
}
