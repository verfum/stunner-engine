#ifndef IMAGE_H
#define IMAGE_H

//#include "god.h"
#include <string>
#include <boost/shared_ptr.hpp>

class Image;
typedef boost::shared_ptr<Image> ImagePtr;
typedef boost::shared_ptr<const Image> ImageConstPtr;

class Image
{
public:
   // Constructors
   Image();
   Image(const Image& image);

   // Width and height in pixels
   virtual int getWidth() const = 0;
   virtual int getHeight() const = 0;

   // Destructor
   virtual ~Image();

   // Operators
   Image& operator=(const Image& other);

private:
   //int m_image;

};

#endif //IMAGE_H