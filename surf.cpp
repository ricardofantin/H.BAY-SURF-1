#include "surf.h"

using namespace surf;

//! Constructor
Surf::Surf(){

}

//! Constructor with parameters
//[TODO] usurf and insi not used yet, what they are?
//[TODO] I suspect insi is the number of octaves...
//Taken from main.cpp
// Initialise the SURF descriptor
//  Surf des(&iimage, /* pointer to integral image */  
//           doubleImageSize, /* double image size flag */ 
//           upright, /* rotation invariance or upright */
//           extended, /* use the extended descriptor */
//           indexSize /* square size of the descriptor window (default 4x4)*/);
Surf::Surf(Image *im, bool dbl, bool usurf, 
         bool ext, int insi){
	_iimage = im;
	_doubleImage = dbl;
	_extended = ext;
}

//! Destructor
Surf::~Surf(){
	//free(
}

//! Get length of the descriptor vector
int Surf::getVectLength(){
	return _VecLength;
}

//! set Ipoint for which a descriptor has to be computed
void Surf::setIpoint(Ipoint *ipt){
	_current = ipt;
}

//! Assign reproducible orientaion
void Surf::assignOrientation(){
	//[TODO]
}

//! Compute the robust features
void Surf::makeDescriptor(){
	//use the ipoint
}

/*  protected:
    //! Create the vector 
    void createVector(double scale, 
                      double row, double col);

    //! Create the vector 
    void createUprightVector(double scale,
                             double row, double col);

    //! Add sample to the vector
    void AddSample(int r, int c, double rpos, 
                   double cpos, double rx, double cx, int step);

    //! Add upright sample to the vector
    void AddUprightSample(int r, int c, double rpos,
                          double cpos, double rx, double cx, int step);

    //! Place sample to index in vector
    void PlaceInIndex(double mag1, int ori1,
                      double mag2, int ori2, double rx, double cx);

    //! Normalise descriptor vector for illumination invariance for
    //! Lambertian surfaces
    void normalise();

    //! Create Lookup tables 
    void createLookups();

  private:
    Image *_iimage;
    Ipoint *_current;
    double ***_index;
    bool _doubleImage;
    bool _upright;
    bool _extended;
    int _VecLength;
    int _IndexSize;
    double _MagFactor;
    int _OriSize;
    int _width, _height;

    double _sine, _cose;
    double **_Pixels;

    double _lookup1[83], _lookup2[40];
};

}*/

