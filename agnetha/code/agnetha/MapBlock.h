#ifndef MAPBLOCK_H
#define MAPBLOCK_H

#include "MapBlockImage.h"
#include <boost/shared_ptr.hpp>

class MapBlock;
typedef boost::shared_ptr<MapBlock> MapBlockPtr;
typedef boost::shared_ptr<const MapBlock> MapBlockConstPtr;

class MapBlock
{
public:
   // Constructors
   MapBlock(int imageId);

   // Destructor
   virtual ~MapBlock();

   // Accessors
   int getId() const;

   // Operators

   MapBlockImagePtr m_mapBlockImage;
private:
   int m_imageId;

};

#endif //MAPBLOCK_H