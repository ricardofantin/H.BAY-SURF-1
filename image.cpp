/*
 * Speeded-Up Robust Features (SURF)
 * http://people.ee.ethz.ch/~surf
 *
 * Authors: Herbert Bay, Andreas Ess, Geert Willems
 * Windows port by Stefan Saur
 *
 * Copyright (2006): ETH Zurich, Switzerland
 * Katholieke Universiteit Leuven, Belgium
 * All rights reserved.
 *
 * For details, see the paper:
 * Herbert Bay,  Tinne Tuytelaars,  Luc Van Gool,
 *  "SURF: Speeded Up Robust Features"
 * Proceedings of the ninth European Conference on Computer Vision, May 2006
 *
 * Permission to use, copy, modify, and distribute this software and
 * its documentation for educational, research, and non-commercial
 * purposes, without fee and without a signed licensing agreement, is
 * hereby granted, provided that the above copyright notice and this
 * paragraph appear in all copies modifications, and distributions.
 *
 * Any commercial use or any redistribution of this software
 * requires a license from one of the above mentioned establishments.
 *
 * For further details, contact Andreas Ess (aess@vision.ee.ethz.ch).
 */

#include "image.h"
#include <stdlib.h>

namespace surf {
	
Image::Image(const int w, const int h){
	_height = h;
	_width = w;
	allocPixels(w, h);
	_ref = false;
}

//! Constructor from existing double array
Image::Image(double **pixels, int w, int h){
	_height = h;
	_width = w;
	_ref = true;
	_pixels = pixels;
}

//! constructor for integral image
//[TODO] doubleImSize not used, is to double width and height?
Image::Image(Image *im, bool doubleImSize){
	allocPixels(im->getHeight(), im->getWidth());
	double sum = 0;
	//double p[][im->getWidth()] = _pixels;
	for(int i = 0; i < im->getHeight(); i++){
		for(int j = 0; j < im->getWidth(); j++){
			sum += im->getPix(j, i);
			_pixels[i][j] = sum;
		}
	}
}

Image::~Image(){
	if(_ref == false)
		delete _pixels;
}

void Image::allocPixels(int w, int h){
	//_pixels = new double[h][w];
	_pixels = (double**)malloc(h*w*sizeof(double));
}

int Image::getWidth(){
	return _width;
}

int Image::getHeight(){
	return _height;
}

/*double** Image::getPixels(){
	return _pixels;
}*/

  /* Filters
   * Y-direction X-Direction XY-Direction
   * 001111100   000000000   000000000
   * 001111100   000000000   01110-1-0
   * 001111100   111-2-111   01110-1-0
   * 00-2--200   111-2-111   01110-1-0
   * 00-2--200   111-2-111   000000000
   * 00-2--200   111-2-111   0-1-01110
   * 001111100   111-2-111   0-1-01110
   * 001111100   000000000   0-1-01110
   * 001111100   000000000   000000000
   */
double Image::getHessian(int r, int c){
	double y = getRectangleSum(r-4, c-2, 3, 5) -2*getRectangleSum(r-1, c-2, 3, 5) + getRectangleSum(r+2, c-2, 3, 5);
	double x = getRectangleSum(r-2, c-4, 5, 3) -2*getRectangleSum(r-2, c-1, 5, 3) + getRectangleSum(r-2, c+2, 5, 3);
	double xy = getRectangleSum(r-3, c-3, 3, 3) + getRectangleSum(r+1, c+1, 3, 3) - getRectangleSum(r-3, c+1, 3, 3) - getRectangleSum(r+1, c-3, 3, 3);
	double det = x*y - 0.81*xy+xy;
	return det;
}

double Image::getRectangleSum(int r, int c, int height, int width){
	return _pixels[r-1][c-1] + _pixels[r-1+height][c-1+width] - _pixels[r-1+width][c-1] - _pixels[r-1][c-1+width];
}

}

