#ifndef VIEW_H
#define VIEW_H

#include "WorldPosition.h"
#include "ScreenPosition.h"

#include <string>

// Forward declarations

class View
{
public:
   // Enums
   enum ViewMode
   {
      vmInGame,
      vmWorld
   };

public:
   // Constructors
   View(const WorldPosition& worldPosition,   // Center of view as a world position
        const ScreenPosition& screenPosition, // Top-left of view as a screen position
        double worldWidth, double worldHeight,
        int screenWidth, int screenHeight);

   // Convert from world to screen position using this view
   ScreenPosition toScreen(const WorldPosition& position) const;

   // Convert screen to world coords for things like mouse cursor
   WorldPosition toWorld(const ScreenPosition& position) const;



   //View(const View& view);

   const ScreenPosition& getScreenPosition() const
   {
      return m_screenPosition;
   }

   // Gets view width in screen units
   int getScreenWidth() const
   {
      return m_screenWidth;
   }

   // Gets view height in screen units
   int getScreenHeight() const
   {
      return m_screenHeight;
   }

   // Gets given world width in screen units
   double getScreenWidth(double width) const
   {
      return (m_screenWidth/m_worldWidth)*width;
   }

   // Gets given world height in screen units
   double getScreenHeight(double height) const
   {
      return (m_screenHeight/m_worldHeight)*height;
   }

   void setWorldPosition(const WorldPosition& worldPosition)
   {
      m_worldPosition = worldPosition;
   }

   void setWorldWidth(double width)
   {
      m_worldWidth = width;
   }

   void setWorldHeight(double height)
   {
      m_worldHeight = height;
   }
 
   // Destructor
   virtual ~View();

protected:
   // Operators
   View& operator=(const View& other);

private:

   /*   // Width and height of screen viewport in pixels
   void setScreenViewSize(int width, int height);
   // Position on screen to display view, e.g. 0,0 would be top left of screen/window
   void setScreenPosition(const ScreenPosition& topLeft);
   // The resolution to display the game on the screen.
   // 1 would be one world unit per pixel. 1 wupp would be typical.
   void setWorldUnitsPerPixel(double wupp);
   // The center point in world coords being viewed.
   // The viewable dimentions are screenViewSize * wupp, i.e. if wupp is large
   // you can see more of the game on screen at the loss of pixel resolution.
   void setWorldPosition(const WorldPosition& center);
   // View mode for rendering.
   // Could be:
   // vsInGame - images are drawn full size
   // vsWorldView - for overview of whole level, images might be drawn half-size to fit in screen viewport
   // Drawers can use drawStyle enum, or wupp to decide the size of image drawing
   void setViewMode(const ViewMode& style);
*/

   // Returns top left of view as a world position
   WorldPosition topLeft() const;

   int m_screenWidth;
   int m_screenHeight;
   double m_worldWidth; // Amount of world width visible
   double m_worldHeight; // Amount of world height visible
   WorldPosition m_worldPosition; // World position of view as given by the center of the view
   ScreenPosition m_screenPosition; // Position of (top left of) view relative to top left of screen.
   ViewMode m_style;

};

#endif //VIEW_H