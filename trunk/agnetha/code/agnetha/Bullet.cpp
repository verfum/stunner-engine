#include "bullet.h"

Bullet::Bullet(double version, double width, double height, double damage, 
          std::vector<ImagePtr>* fireImages, int fireAnimSpeed,
          std::vector<ImagePtr>* travelImages, int travelAnimSpeed,
          std::vector<ImagePtr>* hitImages, int hitAnimSpeed)
:
m_width(width),
m_height(height),
m_damage(damage),
m_pos(0,0),
m_animationTimeSinceLastFrame(0),
m_animationFrame(0),
m_animationState(basTravel),
m_fireAnimSpeed(fireAnimSpeed),
m_travelAnimSpeed(travelAnimSpeed),
m_hitAnimSpeed(hitAnimSpeed),
m_pCurrentAnimImages(0),
m_fireImages(fireImages),
m_travelImages(travelImages),
m_hitImages(hitImages)
{
}

Bullet::~Bullet()
{

}

void
Bullet::update(Renderer* renderer, double timePassed)
{
   // Very simple - should apply gradual acceleration?
   //m_pos.moveX(m_steering);
   //m_pos.moveY(m_forwardMovement);

   m_animationTimeSinceLastFrame += timePassed;
}

void
Bullet::draw(Renderer* renderer)
{
   // Calculate world position of top left of ship anim frames
   /*WorldPosition pos(m_pos.getX()+m_imageOffsetX, m_pos.getY()+m_imageOffsetY);

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
*/
}


void
Bullet::setPos(const WorldPosition& pos)
{
	m_pos = pos;
}