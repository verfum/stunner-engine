#include "view.h"

View::View(const WorldPosition& worldPosition,
           const ScreenPosition& screenPosition,
           double worldWidth, double worldHeight,
           int screenWidth, int screenHeight)
:
m_worldPosition(worldPosition),
m_screenPosition(screenPosition),
m_worldWidth(worldWidth),
m_worldHeight(worldHeight),
m_screenWidth(screenWidth),
m_screenHeight(screenHeight)
{

}

ScreenPosition
View::toScreen(const WorldPosition& position) const
{
   //if(m_screenWidth <= 0 || m_screenWidth <= 0)
   //   return ScreenPosition(-111111, -111111); // TODO Should ASSERT

   double dX = position.getX() - topLeft().getX();
   double dY = position.getY() - topLeft().getY();

   double screenX = m_screenPosition.getX() + (m_screenWidth/m_worldWidth) * dX;
   double screenY = m_screenPosition.getY() + (m_screenHeight/m_worldHeight) * dY;

   return ScreenPosition(screenX, screenY);
}

WorldPosition
View::toWorld(const ScreenPosition& position) const
{
   double topLeftX = topLeft().getX();
   double topLeftY = topLeft().getY();
   double scnX = position.getX();
   double scnY = position.getY();

   double wldX = topLeftX +
      ((m_worldWidth / m_screenWidth) * scnX);

   double wldY = topLeftY +
      ((m_worldHeight / m_screenHeight) * scnY);

   return WorldPosition(wldX, wldY);
}

//View::View(const View& other)
//{
//}

View::~View()
{
}


View&
View::operator=(const View& other)
{
   return *this;
}

WorldPosition
View::topLeft() const
{
   return WorldPosition(m_worldPosition.getX() - (m_worldWidth/2), m_worldPosition.getY() - (m_worldHeight/2));
}
