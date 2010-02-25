#ifndef BLITZIMAGE_H
#define BLITZIMAGE_H

#include <string>
#include <boost/shared_ptr.hpp>
#include "image.h"

class BlitzImage;
typedef boost::shared_ptr<BlitzImage> BlitzImagePtr;
typedef boost::shared_ptr<const BlitzImage> BlitzImageConstPtr;


class BlitzImage :
	public Image
{
public:
   // Constructors
   BlitzImage();
   BlitzImage(const BlitzImage& image);
   BlitzImage(const std::string& filename);

   // Destructor
   virtual ~BlitzImage();

   // Accessors
   int getBlitzImage() const;

   // Operators
   BlitzImage& operator=(const BlitzImage& other);

   // Image interface
   int getWidth() const;
   int getHeight() const;

private:
   int m_image;
   int m_width;
   int m_height;

};

#endif //BLITZIMAGE_H