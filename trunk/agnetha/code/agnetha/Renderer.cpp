#include "Renderer.h"

Renderer::Renderer(const View& view)
:
m_view(view)
{
}


Renderer::~Renderer()
{
}

void 
Renderer::setViewWorldPosition(const WorldPosition& worldPosition)
{
   m_view.setWorldPosition(worldPosition);
}

void Renderer::setViewWorldWidth(double width)
{
   m_view.setWorldWidth(width);
}
void Renderer::setViewWorldHeight(double height)
{
   m_view.setWorldHeight(height);
}

const View&
Renderer::getView() const
{
   return m_view;
}

void
Renderer::drawViewExtents()
{
   ScreenPosition topLeft = m_view.getScreenPosition();
   ScreenPosition topRight(topLeft.getX() + m_view.getScreenWidth(), topLeft.getY());
   ScreenPosition bottomRight(topLeft.getX() + m_view.getScreenWidth(), topLeft.getY() + m_view.getScreenHeight());
   ScreenPosition bottomLeft(topLeft.getX(), topLeft.getY() + m_view.getScreenHeight());

   drawLine(topLeft, topRight, Colour(255, 128, 128, 128));
   drawLine(topRight, bottomRight, Colour(255, 128, 128, 128));
   drawLine(bottomLeft, bottomRight, Colour(255, 128, 128, 128));
   drawLine(bottomLeft, topLeft, Colour(255, 128, 128, 128));
}


/*Renderer&
Renderer::operator=(const Renderer& other)
{
   return *this;
}*/
