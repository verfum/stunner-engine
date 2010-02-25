#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <map>
#include "Renderer.h"
#include "UserInterface.h"
#include "MapBlockImage.h"
#include "MapBlock.h"
#include "ship.h"

class Level
{
public:
   // Constructors
   Level(ShipPtr heroShip);

   // Destructor
   virtual ~Level();

   // Accessors

   // Operators
   //Level& operator=(const Level& other);
   // Draw all things
   void draw(Renderer* renderer);
   // Update things given the time passed in milliseconds
   // Renderer is needed to move view over hero, user interface to access key states
   void update(Renderer* renderer, UserInterface* userInterface, double timePassed);

   // Renderer is needed to load the images
   void load(Renderer* renderer, std::string levelFile);

   void save(std::string levelFile);

   // Tells the level (eventually anything via base) where mouse is
   // in screen units. will need to convert to screen coords if necessary
   void mouse(const ScreenPosition &pos);

private:
   // Methods
   // -------
   // Get the m_images index of the mapblock at x,y
   int getMapBlockImageID(int x, int y) const;

   ScreenPosition m_mousePos;


   // Members
   // -------
   double m_version;
   // World width of level (320)
   //double m_worldWidth;
   // World height of level (400x8 etc)
   //double m_worldHeight;
   // Number of blocks in width (40)
   int m_blocksX;
   // Number of blocks in height (400 etc)
   int m_blocksY;
   // Width of a block in world units
   double m_blockWorldWidth;
   // Height of a block in world units
   double m_blockWorldHeight;
   // Name of level - mainly to identify level in xml file
   std::string m_name;
   // Start position of hero in world units
   // Hence view starts here in level
   WorldPosition m_heroStartPosition;
   // Images used in maps
   std::vector<MapBlockImagePtr> m_images;
   // Top most scrolling map
   std::vector<MapBlockPtr> m_map;

   ShipPtr m_heroShip;

};

#endif //IMAGE_H