#include "fasthessian.h"

using namespace surf;

//! Destructor
FastHessian::~FastHessian();

//! Constructor with parameters
FastHessian::FastHessian(Image *im, std::vector< Ipoint >& ip, double thres = 0.2, bool doub = false, 
                short int initMasksize = 9, short int samplingStep = 2,
                short int octaves = 4){

}

//! Pass the integral image
void FastHessian::setIimage( Image *iim ){
	_Iimage = iim;
}

    //! Detect the interest Points, write into ipts
    void getInterestPoints();

    //! Create a new ipoint at location (x, y),  at a certain scale 
    //! and corner response strength
    void makeIpoint(double x, double y, double scale, double strength=0);

  protected:
    //! Allocate scale layers for one octave
    void allocateOctave();

    //! Fast non-maximum-suppression
    void findMaximum(int *borders, int o, int octave);
    void interpFeature(int s, int row, int col, Image *map,
                       int o, int octave, int movesRemain,
                       int *borders);
    int fitQuadrat(int s, int r, int c, double &res);

  private:
    //! Integral image
    Image *_Iimage;

    //! Octaves
    Image **_scaleLevel;

    //! Vector of variables
    int _vas[9];

    //! Threshold for interest point detection
    double _threshold;

    //! Indicates whether the image size was doubled or not
    //! default is false
    bool _doubled;

    //! Reference to vector of interest points passed from outside
    std::vector< Ipoint >& _ipts;

    //! Initial lobe size for the second derivative in one direction
    //! default is 3
    short int _initLobe;

    //! Number scales
    short int _maxScales;

    //! Number octaves
    short int _maxOctaves;

    //! The sampling step
    short int _sampling;

    //! Integral image dimensions
    int _width;
    int _height;

    //! Result of fitting quadratic
    double _offset[3];
};

}

#endif // FASTHESSIAN_H
