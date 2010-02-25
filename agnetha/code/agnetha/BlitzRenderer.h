#ifndef BLITZRENDERER_H
#define BLITZRENDERER_H

// An 2D graphics renderer - an implementation of the abstract Renderer class
// Features can be drawn relative to a generic world, or relative to the
// screen viewport in pixels.
// Can be used for drawing everything in the game, e.g. bullets, player,
// gui, text, score.

// The idea is that you can create a renderer for, e.g. :
// PC full-screen 1600x1200 where one world unit is one pixel
// 200x200 pixel overview of the world in the bottom-left of a 800x600 PC screen
// 320x240 full-screen on a GP2X

#include "Renderer.h"

#include "BlitzImage.h"

// Forward declarations

class BlitzRenderer : public Renderer
{
public:
   // Constructors
   BlitzRenderer(const View& view);

   // Destructor
   virtual ~BlitzRenderer();

   // Convert screen to world coords for things like mouse cursor
   WorldPosition toWorld(const ScreenPosition& position) const;
   // Draw an image centered at the given world position
   // Mainly used for in-game action objects
   void drawImage(ImagePtr image, const WorldPosition& position);
   // Draw an image at the given world position
   // Anchored top left of image
   // Image is scaled to fit the given world width and height
   // Mainly used for in-game action objects
   void drawImage(ImagePtr image, const WorldPosition& position,
      double width, double height);
   // Draw an image centered at the given screen position relative to top-left of viewport
   // Mainly used for on-screen score, lives etc.
   void drawImage(ImagePtr image, const ScreenPosition& position);
   // Draws an image centered at a position given as a percentage of the width and height
   // of the screen view port. e.g. if the view port is 640x480 and the image is drawn at
   // 50.0,50.0, it will be drawn at 320,240.
   // Mainly used for gui arrangement, or to draw score at top middle of screen.
   void drawImage(ImagePtr image, const PercentageScreenPosition& position);

   ImagePtr createImage(const std::string& filename);

   void drawText(const std::string& text, const WorldPosition& position);

   // Draw a line from start to end in the given colour
   void drawLine(const WorldPosition& startPosition, const WorldPosition& endPosition, const Colour& colour);

   // Draw a line from start to end (in screen coords), in the given colour
   void drawLine(const ScreenPosition& startPosition, const ScreenPosition& endPosition, const Colour& colour);

   // Draw a box centered at the position with given dimensions
   void drawBox(const WorldPosition& center, const WorldDimensions& dimensions, const Colour& colour);
 
   // Accessors

   // Operators
   //BlitzRenderer& operator=(const BlitzRenderer& other);


private:

   // Set colour using blitz specific calls, e.g. needs ezSetAlpha
   void setColour(const Colour& colour);

};

#endif //BLITZRENDERER_H