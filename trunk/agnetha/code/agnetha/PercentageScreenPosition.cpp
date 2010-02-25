#include "PercentageScreenPosition.h"


PercentageScreenPosition::PercentageScreenPosition(double x, double y)
:
m_x(x),
m_y(y)
{
}


PercentageScreenPosition::PercentageScreenPosition(const PercentageScreenPosition& other)
{
   m_x = other.m_x;
   m_y = other.m_y;
}

PercentageScreenPosition::~PercentageScreenPosition()
{
}


PercentageScreenPosition&
PercentageScreenPosition::operator=(const PercentageScreenPosition& other)
{
   m_x = other.m_x;
   m_y = other.m_y;

   return *this;
}

double
PercentageScreenPosition::getX() const
{
   return m_x;
}

double
PercentageScreenPosition::getY() const
{
   return m_y;
}