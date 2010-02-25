#ifndef RENDERER_H
#define RENDERER_H

// An abstract 2D graphics renderer
// Features can be drawn relative to a generic world, or relative to the
// screen viewport in pixels.
// Can be used for drawing everything in the game, e.g. bullets, player,
// gui, text, score.

// The idea is that you can create a renderer for, e.g. :
// PC full-screen 1600x1200 where one world unit is one pixel
// 200x200 pixel overview of the world in the bottom-left of a 800x600 PC screen
// 320x240 full-screen on a GP2X

#include "WorldPosition.h"
#include "ScreenPosition.h"
#include "PercentageScreenPosition.h"

#include "Image.h"
#include "View.h"

#include <boost/shared_ptr.hpp>

// Forward declarations

class WorldDimensions
{
public:
   WorldDimensions(double width, double depth, double height)
      :
      m_width(width),
      m_depth(depth),
      m_height(height)
   {
   }

public:
   double getWidth() const {return m_width;}
   double getDepth() const {return m_depth;}
   double getHeight() const {return m_height;}

private:
   double m_width;
   double m_depth;
   double m_height;

};

class Colour
{
public:
   Colour(unsigned char alpha, unsigned char red, unsigned char green, unsigned char blue)
      :
      m_alpha(alpha),
      m_red(red),
      m_green(green),
      m_blue(blue)
   {
   }

   unsigned char alpha() const {return m_alpha;}
   unsigned char red() const {return m_red;}
   unsigned char green() const {return m_green;}
   unsigned char blue() const {return m_blue;}

private:
   unsigned char m_alpha;
   unsigned char m_red;
   unsigned char m_green;
   unsigned char m_blue;

};

class Renderer;
typedef boost::shared_ptr<Renderer> RendererPtr;
typedef boost::shared_ptr<const Renderer> RendererConstPtr;

class Renderer
{
public:
   // Constructors
   Renderer(const View& view);

   // Destructor
   virtual ~Renderer();

protected:
   // Protected as only concrete renderers will use this - or could make m_view protected
   const View& getView() const;

public:
   // Convert screen to world coords for things like mouse cursor
   virtual WorldPosition toWorld(const ScreenPosition& position) const = 0;
   void setViewWorldPosition(const WorldPosition& worldPosition);
   void setViewWorldWidth(double width);
   void setViewWorldHeight(double height);
   // Draw an image at the given world position
   // Anchored top left of image
   // Image is not scaled
   // Mainly used for in-game action objects
   virtual void drawImage(ImagePtr image, const WorldPosition& position) = 0;
   // Draw an image at the given world position
   // Anchored top left of image
   // Image is scaled to fit the given world width and height
   // Mainly used for in-game action objects
   virtual void drawImage(ImagePtr image, const WorldPosition& position,
      double width, double height) = 0;
   // Draw an image (anchored top-left of image) at the given screen position relative to top-left of viewport
   // Mainly used for on-screen score, lives etc.
   virtual void drawImage(ImagePtr image, const ScreenPosition& position) = 0;
   // Draws an image centered at a position given as a percentage of the width and height
   // of the screen view port. e.g. if the view port is 640x480 and the image is drawn at
   // 50.0,50.0, it will be drawn at 320,240.
   // Mainly used for gui arrangement, or to draw score at top middle of screen.
   virtual void drawImage(ImagePtr image, const PercentageScreenPosition& position) = 0;
 
   // As renderers can display images, they also need to know how to load them, as the loading
   // mechanism is specific to the graphics system
   virtual ImagePtr createImage(const std::string& filename) = 0;

   // Draw some text
   virtual void drawText(const std::string& text, const WorldPosition& position) = 0;

   // Draw a line from start to end (in world coords), in the given colour
   virtual void drawLine(const WorldPosition& startPosition, const WorldPosition& endPosition, const Colour& colour) = 0;

   // Draw a line from start to end (in screen coords), in the given colour
   virtual void drawLine(const ScreenPosition& startPosition, const ScreenPosition& endPosition, const Colour& colour) = 0;

   // Draw a box centered at the position with given dimensions
   virtual void drawBox(const WorldPosition& center, const WorldDimensions& dimensions, const Colour& colour) = 0;

   // Draws the extent of the view
   virtual void drawViewExtents();


   //virtual ScreenPosition toScreen(WorldPosition& worldPosition) = 0;

   // Accessors

   // Operators
   //Renderer& operator=(const Renderer& other);

protected:

private:

   
   View m_view;

};

#endif //RENDERER_H