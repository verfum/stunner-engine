#ifndef BULLET_H
#define BULLET_H

#include <vector>
#include <map>
#include "Renderer.h"
#include "Image.h"
#include <boost/shared_ptr.hpp>
#include "tinyxml.h"

class Bullet;
typedef boost::shared_ptr<Bullet> BulletPtr;
typedef boost::shared_ptr<const Bullet> BulletConstPtr;

enum BulletAnimationState
{
   basFire,
   basTravel,
   basHit
};

class Bullet
{
public:
   // Constructors
   Bullet(double version, double width, double height, double damage,
          std::vector<ImagePtr>* fireImages, int fireAnimSpeed,
          std::vector<ImagePtr>* travelImages, int travelAnimSpeed,
          std::vector<ImagePtr>* hitImages, int hitAnimSpeed);

   // Destructor
   virtual ~Bullet();

   // Accessors

   // Operators

   // Draw all things
   void draw(Renderer* renderer);
   // Update things given the time passed in milliseconds
   void update(Renderer* renderer, double timePassed);
   // Renderer is needed to load the images
   // void load(Renderer* renderer, TiXmlElement* pShip);
   // void save(std::string levelFile);

   // Potential base class members functions
   void setPos(const WorldPosition& pos);

//protected:
	// Loads the animation frames
	//void loadAnimationArray(Renderer* renderer, TiXmlElement* parentNode,  const std::string& name,
     // std::vector<ImagePtr> &images, int &animSpeed);

private:
   // Specific
   // --------
   double m_damage;

   // Methods
   // -------

   // Members
   // -------
   double m_version;
   // Width in world units
   double m_width;
   // Height in world units
   double m_height;

   // Image used
   std::vector<ImagePtr>* m_fireImages;
   std::vector<ImagePtr>* m_travelImages;
   std::vector<ImagePtr>* m_hitImages;
   std::vector<ImagePtr>* m_pCurrentAnimImages;
   int m_fireAnimSpeed;
   int m_travelAnimSpeed;
   int m_hitAnimSpeed;
   int m_currentAnimSpeed;

   // Animation
   // ---------
   // This lot should surely be encapsulated in a library if not a base class?
   double m_animationTimeSinceLastFrame;
   int m_animationFrame;
   BulletAnimationState m_animationState;

   // Potential base class members - world x,y coords
   WorldPosition m_pos;

   //double collisionWidth;
   //double collisionHeight;
   //double collisionOffsetX;
   //double collisionOffsetY;
   double m_imageWidth;
   double m_imageHeight;
   double m_imageOffsetX;
   double m_imageOffsetY;
};

#endif //BULLET_H