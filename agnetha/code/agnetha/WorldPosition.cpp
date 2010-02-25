#include "WorldPosition.h"
#include "math.h"


WorldPosition::WorldPosition(double x, double y)
:
m_x(x),
m_y(y)
{
}


WorldPosition::WorldPosition(const WorldPosition& other)
{
   m_x = other.m_x;
   m_y = other.m_y;
}

WorldPosition::~WorldPosition()
{
}


WorldPosition&
WorldPosition::operator=(const WorldPosition& other)
{
   m_x = other.m_x;
   m_y = other.m_y;

   return *this;
}

double
WorldPosition::distanceTo(const WorldPosition& b) const
{
   double xDist = (getX() - b.getX());
   double yDist = (getY() - b.getY());
   double dist = sqrt((xDist*xDist) + (yDist*yDist));
   return dist;
}

double
WorldPosition::getX() const
{
   return m_x;
}

double
WorldPosition::getY() const
{
   return m_y;
}

void
WorldPosition::moveY(double amount)
{
   m_y += amount;
}

void
WorldPosition::moveX(double amount)
{
   m_x += amount;
}