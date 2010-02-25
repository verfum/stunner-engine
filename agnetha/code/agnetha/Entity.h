#ifndef ENTITY_H
#define ENTITY_H

#include "ScreenPosition.h"
#include "WorldPosition.h"

class Renderer;

class Entity
{
protected:
   // Constructors
   Entity();

public:
   // Destructor
   virtual ~Entity();


   // Public interface
   // Draws the current state of this entity using the given abstract renderer.
   // This function does not update any state - that is done by calling the update function.
   virtual void draw(Renderer* renderer) = 0;

   // Update state (mainly position) as though this amount of time (in milliseconds) has past.
   // e.g. if 20 miliseconds (one frame) have past, move forward 2 world units.
   // All Entities, as they have a WorldPositon, can be drawn on the 'World'.
   // This will probably be called the same amount of times as draw, but like all good
   // engines, it's possible to continue to simulate the game between render frames.
   virtual void update(double timeElapsed/*, World* world*/) = 0;

   // Operators


protected:


};

#endif //ENTITY_H