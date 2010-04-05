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
m_centreAnimSpeed(1000),
m_leftAnimSpeed(1000),
m_rightAnimSpeed(1000),
m_pCurrentAnimImages(0)
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
   // Calculate world position of top left of ship anim frames
   WorldPosition pos(m_pos.getX()+m_imageOffsetX, m_pos.getY()+m_imageOffsetY);

   // Calculate animation state
   ShipAnimationState animationState;
   if(m_steering < 0)
   {
      animationState = sasLeft;
      m_pCurrentAnimImages = &m_leftImages;
      m_currentAnimSpeed = m_leftAnimSpeed;
   }
   if(m_steering == 0)
   {
      animationState = sasCentre;
      m_pCurrentAnimImages = &m_centreImages;
      m_currentAnimSpeed = m_centreAnimSpeed;
   }
   if(m_steering > 0)
   {
      animationState = sasRight;
      m_pCurrentAnimImages = &m_rightImages;
      m_currentAnimSpeed = m_rightAnimSpeed;
   }

   // Reset animation loop params if anim set changes
   if(animationState != m_animationState)
   {
      m_animationState = animationState;
      m_animationFrame = 0;
      m_animationTimeSinceLastFrame = 0;
   }

   // Progress frame?
   if(m_animationTimeSinceLastFrame >= m_currentAnimSpeed)
   {
      m_animationFrame++;
      m_animationTimeSinceLastFrame = 0;
   }

   // Wrap back to frame 0?
   if(m_animationFrame >= int(m_pCurrentAnimImages->size()))
      m_animationFrame = 0;

   // Do we have any frames to draw?
   if(int(m_pCurrentAnimImages->size()) > 0)
      renderer->drawImage((*m_pCurrentAnimImages)[m_animationFrame], pos, m_imageWidth, m_imageHeight);
}

void
Ship::load(Renderer* renderer, TiXmlElement* pShip)
{
   TiXmlHandle hShip(0);
   hShip=TiXmlHandle(pShip);

   TiXmlElement* pGraphicsNode=hShip.FirstChild( "graphics" ).Element();

   // Get 'centre' anim frames
   loadAnimationArray(renderer, pGraphicsNode, "centre", m_centreImages, m_centreAnimSpeed);
   loadAnimationArray(renderer, pGraphicsNode, "left", m_leftImages, m_leftAnimSpeed);
   loadAnimationArray(renderer, pGraphicsNode, "right", m_rightImages, m_rightAnimSpeed);

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

void
Ship::loadAnimationArray(Renderer* renderer, TiXmlElement* parentNode, const std::string& name, std::vector<ImagePtr> &images, int &animSpeed)
{
   // Get image filenames
   TiXmlHandle hGraphics(0);
   hGraphics=TiXmlHandle(parentNode);

   // Get anim speed
   hGraphics.FirstChild(name.c_str()).Element()->Attribute("animSpeed", &animSpeed);

   // Get images
   TiXmlElement* pCentreNode=hGraphics.FirstChild( name.c_str() ).FirstChild().Element();

   for( pCentreNode; pCentreNode; pCentreNode=pCentreNode->NextSiblingElement())
   {
      // Get image filename
      const char *pImageFileName = pCentreNode->Attribute("file");
      std::string filename(pImageFileName);

      // Create image
      ImagePtr image(renderer->createImage(filename));
      
      // Store image
      images.push_back(image);
   }
}