#include "fasthessian.h"

using namespace surf;

//! Destructor
FastHessian::~FastHessian(){};

//! Constructor with parameters
FastHessian::FastHessian(Image *im, std::vector<Ipoint> ip, double thres, bool doub, 
                short int initMasksize, short int samplingStep,
                short int octaves){
	_ipts = ip;
	_Iimage = im;
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
			Ipoint ip;
			ip.allocIvec(12);
			calculateIpoint(r, c, &ip);
			//need get 3 values horizontal vertical and diagonal
			//int v = _Iimage.getPix(c, r);
			//double hessian = _Iimage.getHessian(r, c);
/*			if (hessian > _threshold){
				Ipoint ip();
				ip.allocIvec(3);
				ip.ivec[0] = 0;
				ip.ivec[1] = 0;
				ip.ivec[2] = 0;
				_ipts.push_back(ip);
			}*/
		}
	}
}

void FastHessian::calculateIpoint(int r, int c, Ipoint *ip){
	Image *i = _Iimage;
	double x, y, xy;
	x = i->getRectangleSum(r-2, c-4, 5, 3) -2*i->getRectangleSum(r-2, c-1, 5, 3) + i->getRectangleSum(r-2, c+2, 5, 3);
	y = i->getRectangleSum(r-4, c-2, 3, 5) -2*i->getRectangleSum(r-1, c-2, 3, 5) + i->getRectangleSum(r+2, c-2, 3, 5);
	xy = i->getRectangleSum(r-3, c-3, 3, 3) + i->getRectangleSum(r+1, c+1, 3, 3) - i->getRectangleSum(r-3, c+1, 3, 3) - i->getRectangleSum(r+1, c-3, 3, 3);
	ip->ivec[0] = x;
	ip->ivec[1] = y;
	ip->ivec[2] = xy;
	x = i->getRectangleSum(r-4, c-7, 9, 5) -2*i->getRectangleSum(r-4, c-2, 9, 5) + i->getRectangleSum(r-4, c+3, 9, 5);
	y = i->getRectangleSum(r-7, c-4, 5, 9) -2*i->getRectangleSum(r-2, c-4, 5, 9) + i->getRectangleSum(r+3, c-4, 5, 9);
	xy = i->getRectangleSum(r-6, c-6, 6, 6) + i->getRectangleSum(r+1, c+1, 6, 6) - i->getRectangleSum(r-6, c+1, 6, 6) - i->getRectangleSum(r+1, c-6, 6, 6);
	ip->ivec[3] = x;
	ip->ivec[4] = y;
	ip->ivec[5] = xy;
	x = i->getRectangleSum(r-6, c-10, 13, 7) -2*i->getRectangleSum(r-6, c-3, 7, 13) + i->getRectangleSum(r-6, c+4, 7, 13);
	y = i->getRectangleSum(r-10, c-6, 7, 13) -2*i->getRectangleSum(r-3, c-6, 7, 13) + i->getRectangleSum(r+4, c-6, 7, 13);
	xy = i->getRectangleSum(r-9, c-9, 9, 9) + i->getRectangleSum(r+1, c+1, 9, 9) - i->getRectangleSum(r-9, c+1, 9, 9) - i->getRectangleSum(r+1, c-9, 9, 9);
	ip->ivec[6] = x;
	ip->ivec[7] = y;
	ip->ivec[8] = xy;
	x = i->getRectangleSum(r-8, c-13, 17, 9) -2*i->getRectangleSum(r-8, c-4, 17, 9) + i->getRectangleSum(r-8, c+5, 17, 9);
	y = i->getRectangleSum(r-13, c-8, 9, 17) -2*i->getRectangleSum(r-4, c-8, 9, 17) + i->getRectangleSum(r+5, c-8, 9, 17);
	xy = i->getRectangleSum(r-12, c-12, 12, 12) + i->getRectangleSum(r+1, c+1, 12, 12) - i->getRectangleSum(r-12, c+1, 12, 12) - i->getRectangleSum(r+1, c-12, 12, 12);
	ip->ivec[9] = x;
	ip->ivec[10] = y;
	ip->ivec[11] = xy;
}

    //! Create a new ipoint at location (x, y),  at a certain scale 
    //! and corner response strength
    void makeIpoint(double x, double y, double scale, double strength);

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

