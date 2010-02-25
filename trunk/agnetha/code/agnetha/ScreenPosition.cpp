#include "ScreenPosition.h"


ScreenPosition::ScreenPosition(double x, double y)
:
m_x(x),
m_y(y)
{
}


ScreenPosition::ScreenPosition(const ScreenPosition& other)
{
   m_x = other.m_x;
   m_y = other.m_y;
}

ScreenPosition::~ScreenPosition()
{
}


ScreenPosition&
ScreenPosition::operator=(const ScreenPosition& other)
{
   m_x = other.m_x;
   m_y = other.m_y;

   return *this;
}

double
ScreenPosition::getX() const
{
   return m_x;
}

double
ScreenPosition::getY() const
{
   return m_y;
}