#include "BlitzRenderer.h"
#include "BlitzImage.h"
#include "Entity.h"
#include "cBlitz.h"

BlitzRenderer::BlitzRenderer(const View& view)
:
Renderer(view)
{
}

BlitzRenderer::~BlitzRenderer()
{
}

void
BlitzRenderer::drawImage(ImagePtr image, const WorldPosition& position)
{
   WorldPosition tempPos(position.getX(), position.getY());
   drawImage(image, getView().toScreen(tempPos));
}


void
BlitzRenderer::drawImage(ImagePtr image, const WorldPosition& position,
   double width, double height)
{
   double screenWidth = getView().getScreenWidth(width);
   double screenHeight = getView().getScreenHeight(height);

   double scaleWidth = screenWidth/double(image->getWidth());
   double scaleHeight = screenHeight/double(image->getHeight());

   ezSetScale(float(scaleWidth), float(scaleHeight));

   WorldPosition tempPos(position.getX(), position.getY());
   drawImage(image, getView().toScreen(tempPos));
   
   ezSetScale(1, 1);
}

void
BlitzRenderer::drawImage(ImagePtr image, const ScreenPosition& position)
{
	BlitzImagePtr blitzImage = boost::dynamic_pointer_cast<BlitzImage, Image>(image);
	if(blitzImage)
		ezDrawImage(blitzImage->getBlitzImage(), static_cast<float>(position.getX()), static_cast<float>(position.getY()));
}

void
BlitzRenderer::drawImage(ImagePtr image, const PercentageScreenPosition& position)
{
}

ImagePtr
BlitzRenderer::createImage(const std::string& filename)
{
   ImagePtr img(new BlitzImage(filename));
   return img;
}

void
BlitzRenderer::drawText(const std::string& text, const WorldPosition& position)
{
   ezDrawText(const_cast<char*>(text.c_str()), static_cast<float>(position.getX()), static_cast<float>(position.getY()));
}

void
BlitzRenderer::drawLine(const WorldPosition& startPosition, const WorldPosition& endPosition, const Colour& colour)
{
   drawLine(getView().toScreen(startPosition), getView().toScreen(endPosition), colour);
}

void
BlitzRenderer::drawLine(const ScreenPosition& startPosition, const ScreenPosition& endPosition, const Colour& colour)
{
   setColour(colour);
   ezDrawLine(static_cast<float>(startPosition.getX()),
              static_cast<float>(startPosition.getY()),
              static_cast<float>(endPosition.getX()),
              static_cast<float>(endPosition.getY()));
   setColour(Colour(255,255,255,255));
}

void
BlitzRenderer::drawBox(const WorldPosition& center, const WorldDimensions& dimensions, const Colour& colour)
{
   double x = center.getX();
   double y = center.getY();

   drawLine(WorldPosition(x-dimensions.getWidth()/2, y-dimensions.getDepth()/2),
                      WorldPosition(x-dimensions.getWidth()/2, y+dimensions.getDepth()/2), colour);

   drawLine(WorldPosition(x-dimensions.getWidth()/2, y+dimensions.getDepth()/2),
                      WorldPosition(x+dimensions.getWidth()/2, y+dimensions.getDepth()/2), colour);

   drawLine(WorldPosition(x+dimensions.getWidth()/2, y+dimensions.getDepth()/2),
                      WorldPosition(x+dimensions.getWidth()/2, y-dimensions.getDepth()/2), colour);

   drawLine(WorldPosition(x+dimensions.getWidth()/2, y-dimensions.getDepth()/2),
                      WorldPosition(x-dimensions.getWidth()/2, y-dimensions.getDepth()/2), colour);
}

void
BlitzRenderer::setColour(const Colour& colour)
{
   ezSetBlend(ALPHABLEND);
   ezSetAlpha(static_cast<float>(colour.alpha())/255);
   ezSetColor(colour.red(), colour.green(), colour.blue());
}

// Convert screen to world coords for things like mouse cursor
WorldPosition
BlitzRenderer::toWorld(const ScreenPosition& position) const
{
   return getView().toWorld(position);
}

/*BlitzRenderer&
BlitzRenderer::operator=(const BlitzRenderer& other)
{
   return *this;
}*/
