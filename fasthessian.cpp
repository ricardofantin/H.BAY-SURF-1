#include "fasthessian.h"

using namespace surf;

//! Destructor
FastHessian::~FastHessian();

//! Constructor with parameters
FastHessian::FastHessian(Image *im, std::vector< Ipoint >& ip, double thres = 0.2, bool doub = false, 
                short int initMasksize = 9, short int samplingStep = 2,
                short int octaves = 4){
	_Iimage = im;
	_ipts = ip;
	_width = im->getWidth();
	_height = im->getHeight();
	_threshold = thres;
	_doubled = doub;
	/* if mask is 9x9 then the lobe size is 3
	 * 000000000
	 * 01110---0 -\
	 * 01110---0  | We have here "mini masks" of size 3
	 * 01110---0 -/
	 * 000000000
	 * 0---01110
	 * 0---01110
	 * 0---01110
	 * 000000000
	 */
	_initLobe = initMasksize/3; //(initMasksize - 3)/2;
}

//! Pass the integral image
void FastHessian::setIimage( Image *iim ){
	_Iimage = iim;
}

//! Detect the interest Points, write into ipts
void FastHessian::getInterestPoints(){
	//first determine the border size to apply the 2D-filter
	int border = _initLobe + 1;
	for(int r = border + 1; r < _height - border; r++){
		for(int c = border + 1; c < _width - border; c++){
			//need get 3 values horizontal vertical and diagonal
			//int v = _Iimage.getPix(c, r);
			double hessian = _Iimage.getHessian(r, c);
			if (hessian > _threshold){
				Ipoint ip();
				ip.allocIvec(3);
				ip.ivec[0] = 0;
				ip.ivec[1] = 0;
				ip.ivec[2] = 0;
				_ipts.push_back(ip);
			}
		}
	}
}

    //! Create a new ipoint at location (x, y),  at a certain scale 
    //! and corner response strength
    void makeIpoint(double x, double y, double scale, double strength=0);

//  protected:
//! Allocate scale layers for one octave
void allocateOctave();

//! Fast non-maximum-suppression
void FastHessian::findMaximum(int *borders, int o, int octave){

}

void FastHessian::interpFeature(int s, int row, int col, Image *map,
                       int o, int octave, int movesRemain,
                       int *borders){
	
}

int FastHessian::fitQuadrat(int s, int r, int c, double &res){

}

