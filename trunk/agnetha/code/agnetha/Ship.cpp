#include "ship.h"

Ship::Ship()
:
m_width(0),
m_height(0),
m_pos(0,0),
m_steering(0),
m_forwardMovement(0),
m_animationTimeSinceLastFrame(0),
m_animationFrame(0),
m_animationState(sasCentre),
m_centreAnimSpeed(1000)
{
}

Ship::~Ship()
{

}

void
Ship::update(Renderer* renderer, double timePassed)
{
   // Very simple - should apply gradual acceleration?
   m_pos.moveX(m_steering);
   m_pos.moveY(m_forwardMovement);

   m_animationTimeSinceLastFrame += timePassed;
}

void
Ship::draw(Renderer* renderer)
{
	WorldPosition pos(m_pos.getX()+m_imageOffsetX, m_pos.getY()+m_imageOffsetY);

   if(m_animationState == sasCentre)
   {
      // Progress frame if necessary
      if(m_animationTimeSinceLastFrame >= m_centreAnimSpeed)
      {
         m_animationFrame++;
         m_animationTimeSinceLastFrame = 0;
      }

      // Wrap back to frame 0
      if(m_animationFrame >= int(m_centreImages.size()))
         m_animationFrame = 0;

      renderer->drawImage(m_centreImages[m_animationFrame], pos, m_imageWidth, m_imageHeight);
   }
}

void
Ship::load(Renderer* renderer, TiXmlElement* pShip)
{
   TiXmlHandle hShip(0);
   hShip=TiXmlHandle(pShip);

   TiXmlElement* pGraphicsNode=hShip.FirstChild( "graphics" ).Element();

   // Get image filenames
   TiXmlHandle hGraphics(0);
   hGraphics=TiXmlHandle(pGraphicsNode);

   TiXmlElement* pCentreNode=hGraphics.FirstChild( "centre" ).FirstChild().Element();

   // Image FPS
   TiXmlElement* poo = pGraphicsNode=hShip.FirstChild( "graphics" ).FirstChild().Element();
   poo->Attribute("animSpeed", &m_centreAnimSpeed);

   for( pCentreNode; pCentreNode; pCentreNode=pCentreNode->NextSiblingElement())
   {
      // Get image filename
      const char *pImageFileName = pCentreNode->Attribute("file");
      std::string filename(pImageFileName);

      // Create image
      ImagePtr image(renderer->createImage(filename));
      
      // Store image
      m_centreImages.push_back(image);
   }

   // Image position in world units
   // -----------------------------
   pShip->Attribute("imageWidth", &m_imageWidth);
   pShip->Attribute("imageHeight", &m_imageHeight);
   pShip->Attribute("imageOffsetX", &m_imageOffsetX);
   pShip->Attribute("imageOffsetY", &m_imageOffsetY);
}

void
Ship::setPos(const WorldPosition& pos)
{
	m_pos = pos;
}

void
Ship::setSteering(double amount)
{
   m_steering = amount;
}

// Positive for forward, negative for breaking/reverse.
void
Ship::setForwardMovement(double amount)
{
   m_forwardMovement = amount;
}