#ifndef MAPBLOCKIMAGE_H
#define MAPBLOCKIMAGE_H

#include "Image.h"
#include <boost/shared_ptr.hpp>

class MapBlockImage;
typedef boost::shared_ptr<MapBlockImage> MapBlockImagePtr;
typedef boost::shared_ptr<const MapBlockImage> MapBlockImageConstPtr;

class MapBlockImage
{
public:
   // Constructors
   MapBlockImage(std::string filename, ImagePtr image);

   // Destructor
   virtual ~MapBlockImage();

   // Accessors
   std::string getFilename() const
   {
      return m_filename;
   }

   // Operators

   ImagePtr m_image;
private:
   //ImagePtr m_image;
   std::string m_filename;
};

#endif //MAPBLOCKIMAGE_H