#include "MapBlock.h"

MapBlock::MapBlock(int imageId)
:
m_imageId(imageId)
{
}

MapBlock::~MapBlock()
{

}

int
MapBlock::getId() const
{
   return m_imageId;
}
