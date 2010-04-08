#include "BlitzImage.h"
#include "cBlitz.h"

BlitzImage::BlitzImage()
:
m_image(-1),
m_width(-1),
m_height(-1)
{
}

BlitzImage::BlitzImage(const BlitzImage& other)
{
   m_image = other.m_image;
   m_width = ezImageWidth(m_image);
   m_height = ezImageHeight(m_height);
}

BlitzImage::BlitzImage(const std::string& filename)
{
   m_image = ezLoadImage(const_cast<char*>(filename.c_str()));
   m_width = ezImageWidth(m_image);
   m_height = ezImageHeight(m_image);
}


BlitzImage::~BlitzImage()
{
   if(m_image != -1)
   {
      ezRelease(m_image);
      ezGCCollect();
   }
}

int
BlitzImage::getBlitzImage() const
{
   return m_image;
}

BlitzImage&
BlitzImage::operator=(const BlitzImage& other)
{
   m_image = other.m_image;

   return *this;
}

// Image interface
int
BlitzImage::getWidth() const
{
   return m_width;
}
int
BlitzImage::getHeight() const
{
   return m_height;
}