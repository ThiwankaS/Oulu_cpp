/**
 * Copyright 2024 University of Oulu
 * Authors:
 *   Elmeri Uotila <roope.uotila@oulu.fi>
 * @modified in Spring 2025 by Anna LaValle and Elmeri Uotila
 */

#include "canvas.h"
#include <iostream>

Canvas::Canvas() = default;

// Just delete the list, the individual layers are handled by main
Canvas::~Canvas() = default;

// Add an layer at the end of the list
void Canvas::Add(size_t x, size_t y, const Vector2& pos, const Vector2& scale, const RGBAPixel& col, const std::string& name)
{
	// TODO instead of a single layer, have a list
	// Replace the code here
        //layers = new PNGLayer(x,y,pos,scale,col,name);
		layers.push_back(std::make_unique<PNGLayer>(x,y,pos,scale,col,name));
}

// Get the latest layer added to the canvas
// Return as pointer to allow editing or drawing on it
PNGLayer & Canvas::GetTopLayer() {
	// TODO instead of a single layer,
	// Return the latest/top layer from the list
	return *layers.back();
}

// Get a layer by its name
// Return by reference to allow editing or drawing on it
PNGLayer& Canvas::GetByName(const std::string& name){
	// TODO instead of a single layer,
	// Return the layer with matching name
	// Report an error if it doesn't exist
	for(auto &layer : layers)
	{
		if(layer->getName() == name)
			return *layer;
	}
	throw std::runtime_error("Layer not found");
}

// Find and remove layer by name
// If layer is not found, do nothing
void Canvas::Remove(const std::string& name)
{
	// TODO instead of a single layer, should work for a list
	// This removes the frame for the logo in the collage
	// Your code here
	for(auto layer = layers.begin(); layer != layers.end(); ++layer) {
		if((*layer)->getName() == name) {
			layers.erase(layer);
			return;
		}
	}
}

// Find given layers from list and swap their positions
// Swap only if both layers are found
void Canvas::Swap(const std::string& name1, const std::string& name2)
{
	// TODO needed for collage so the frames can be drawn before images
	// Your code here
	auto l1 = layers.end(), l2 = layers.end();
	for(auto layer = layers.begin(); layer != layers.end(); ++layer) {
		if ((*layer)->getName() == name1) { l1 = layer; }
		if ((*layer)->getName() == name2) { l2 = layer; }
	}
	if(l1 != layers.end() && l2 != layers.end()) {
		std::iter_swap(l1, l2);
	}
}

// Draws all layers in the list in order
// Blends the pixels colors of the layers with their layer color
// Draws the layers in their given position and scales them accordingly
// Blends drawn layers based on alpha channel (transparency)
void Canvas::draw(PNG& canvas) const
{
	for(const auto& ptr : layers) {
		//update this line
		PNGLayer& layer = *ptr;

		for(size_t x=0, xmax = layer.width(); x<xmax; x++){
			for(size_t y=0, ymax = layer.height(); y<ymax; y++){
				// This gets the pixel color blended with layer color
				// Check pnglayer.cpp
				RGBAPixel coli = layer.getBlendedPixel(x,y);
				Vector2 sc = layer.getScale();

				// TODO You should uncomment the below line and use in the section below
				Vector2 pos = layer.getPosition();

				// A loop is needed in case it must be scaled up, or we end up with gaps
				for(int xs=0; xs < std::abs((int)(sc.x()-0.001))+1; xs++){
					for(int ys=0; ys < std::abs((int)(sc.y()-0.001))+1; ys++){
						// Determine the position on the canvas based on
						// layer position, scale, pixel position and adjacent pixel selection
						// TODO right now it just loops the pixels of the layer
						// x1, y1 should be coordinates of the canvas to draw to
						// So we should add layer position and adjacent pixel selection xs, ys
						// Multiply x and y by layer scale

						// Modify the two lines below
						//int x1 = x;
						int x1 = static_cast<int>(x * sc.x() + pos.x());
						//int y1 = y;
						int y1 = static_cast<int>(y * sc.y() + pos.y());
						x1 = x1 + xs;
						y1 = y1 + ys;

						// Check that it's within bounds
						if(x1 >= 0 && x1 < (int)canvas.width() && y1 >= 0 && y1 < (int)canvas.height()) {
							// Current color of the canvas
							RGBAPixel& colc = canvas(x1,y1);
							double alpha = coli.alpha / 255.0;

							// TODO Blend based on alpha.
							// Multiply layer color with alpha, canvas color with 255-alpha
							// Add them and divide by 255
							// In other words 255 = replace old pixel with new. 0 = don't draw.
							// 1-254 = partly new pixel, partly old

							// Modify the three lines below
							colc.red = static_cast<u_int8_t>(coli.red * alpha + colc.red * (1 - alpha));
							colc.green = static_cast<u_int8_t>(coli.green * alpha + colc.green* (1 - alpha));
							colc.blue = static_cast<u_int8_t>(coli.blue * alpha + colc.blue * (1 - alpha));

							// We can keep the canvas opaque, no reason to change it
							colc.alpha = 255;
						}
					}
				}
			}
		}
	}
}
