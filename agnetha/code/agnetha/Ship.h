#ifndef SHIP_H
#define SHIP_H

#include <vector>
#include <map>
#include "Renderer.h"
#include "Image.h"
#include <boost/shared_ptr.hpp>
#include "tinyxml.h"

class Ship;
typedef boost::shared_ptr<Ship> ShipPtr;
typedef boost::shared_ptr<const Ship> ShipConstPtr;

enum ShipAnimationState
{
   sasCentre,
   sasLeft,
   sasRight,
   sasUp,
   sasDown
};

class Ship
{
public:
   // Constructors
   Ship();

   // Destructor
   virtual ~Ship();

   // Accessors

   // Operators

   // Draw all things
   void draw(Renderer* renderer);
   // Update things given the time passed in milliseconds
   // Renderer is needed to move view over hero
   void update(Renderer* renderer, double timePassed);

   // Renderer is needed to load the images
   void load(Renderer* renderer, TiXmlElement* pShip);

   //void save(std::string levelFile);

   // Control Interface
   // -----------------
   // These must be updated regularly, i.e. as often as 'update' is called.
   // Left/right state of 'steering wheel'. e.g. -1.0 left, 1.0 right, 0.0 forward
   void setSteering(double amount);
   // Positive for forward, negative for breaking/reverse.
   void setForwardMovement(double amount);

   // Potential base class members functions
   void setPos(const WorldPosition& pos);

   // ! This needs to use its current Weapon to create a Bullet
   // The Weapon will contain the images and pass the image pointers
   // to the Bullet, along with other params and initial position
   // (based on this Ship's (T)urret position. Should Turret be
   // a class, with relative position to current Ship?
   // Bullet fire();

   // We need this.
   // ! What happens if this is changed and bullets that have
   // images created from the previous weapon still exist?
   // Does blitz have an image garbage collection, does it
   // recognise that the same URL used in LoadImage is being
   // used again and therefore not load again?
   // void setWeapon(Weapon weapon);

protected:
	// Loads the animation frames
	void loadAnimationArray(Renderer* renderer, TiXmlElement* parentNode,  const std::string& name,
      std::vector<ImagePtr> &images, int &animSpeed);

private:
   // Methods
   // -------

   // Members
   // -------
   double m_version;
   // Width in world units
   double m_width;
   // Height in world units
   double m_height;
   // Name of ship - mainly to identify ship in xml file
   std::string m_name;
   // Image used
   std::vector<ImagePtr> m_centreImages;
   std::vector<ImagePtr> m_leftImages;
   std::vector<ImagePtr> m_rightImages;
   std::vector<ImagePtr>* m_pCurrentAnimImages;
   int m_centreAnimSpeed;
   int m_leftAnimSpeed;
   int m_rightAnimSpeed;
   int m_currentAnimSpeed;

   // Animation
   // ---------
   // This lot should surely be encapsulated in a library if not a base class?
   double m_animationTimeSinceLastFrame;
   int m_animationFrame;
   ShipAnimationState m_animationState;

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

   // Up down/left right
   double m_steering;
   double m_forwardMovement;

};

#endif //SHIP_H