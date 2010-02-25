#include "level.h"
#include "tinyxml.h"

#define PACE 5

Level::Level(ShipPtr heroShip)
:
m_heroShip(heroShip),
m_mousePos(0,0),
m_blockWorldWidth(0),
m_blockWorldHeight(0),
m_blocksX(0),
m_blocksY(0),
m_heroStartPosition(160.0, 256.0)
{
}

Level::~Level()
{

}

void
Level::update(Renderer* renderer, UserInterface* userInterface, double timePassed)
{
   //m_heroStartPosition.moveY(-PACE/timePassed);


   // Update view
   //renderer->setViewWorldPosition(m_heroStartPosition);

   // Set Hero Ship states
   // --------------------
   m_heroShip->setSteering(0.0);
   m_heroShip->setForwardMovement(0.0);

   if(userInterface->getKeyState(kLeft) == ksDown)
   {
      m_heroShip->setSteering(-1.0); // With analogue controllers this might be fractional
   }

   if(userInterface->getKeyState(kRight) == ksDown)
   {
      m_heroShip->setSteering(1.0); // With analogue controllers this might be fractional
   }

   if(userInterface->getKeyState(kUp) == ksDown)
   {
      m_heroShip->setForwardMovement(-1.0); // With analogue controllers this might be fractional
   }

   if(userInterface->getKeyState(kDown) == ksDown)
   {
      m_heroShip->setForwardMovement(1.0); // With analogue controllers this might be fractional
   }

   // Tell child objects to update themselves
   // ---------------------------------------
   m_heroShip->update(renderer, timePassed);
}

void
Level::draw(Renderer* renderer)
{
   // Draw map blocks
   for(int i=0; i < m_blocksX; i++)
   {
      for(int j=0; j < m_blocksY; j++)
      {
         int id = getMapBlockImageID(i, j);
         double worldX = m_blockWorldWidth * i;
         double worldY = m_blockWorldHeight * j;
         renderer->drawImage(m_images[id]->m_image, WorldPosition(worldX,worldY), m_blockWorldWidth, m_blockWorldHeight);
      }
   }
   // Hero ship
   // Has to be drawn here to get correct z-pos between level gfx
   if(m_heroShip)
      m_heroShip->draw(renderer);

   // Draw yellow square
   WorldPosition wrld = renderer->toWorld(m_mousePos);
   char ot[256];
   sprintf_s(ot,"wx=%f wy=%f", wrld.getX(), wrld.getY());
   renderer->drawText(ot, WorldPosition(60,60));
   if(wrld.getX() >= 0 &&
      wrld.getX() < 320 &&
      wrld.getY() >= 0 &&
      wrld.getY() < 256)
   {
      renderer->drawBox(WorldPosition(int(wrld.getX()/m_blockWorldWidth)*m_blockWorldWidth+(m_blockWorldWidth/2),int(wrld.getY()/m_blockWorldHeight)*m_blockWorldHeight+(m_blockWorldHeight/2)), WorldDimensions(m_blockWorldWidth,m_blockWorldHeight,0), Colour(255,255,255,0));
   }

}

void
Level::save(std::string levelFile)
{
   std::string mainComment;
   mainComment = " blockWorldWidth: width of blocks in world units \n";
   mainComment += "     blockWorldHeight: height of blocks in world units \n";
   mainComment += "     blocksX: width of level in blocks \n";
   mainComment += "     blocksY: height of level in blocks \n";
   mainComment += "     This implies level width is blockWorldWidth*blocksX \n";
   mainComment += "     height is blockWorldHeight*blocksY";

   TiXmlDocument doc;  
 	TiXmlDeclaration* decl = new TiXmlDeclaration( "1.0", "", "" );
   doc.LinkEndChild( decl );

   TiXmlComment * comment = new TiXmlComment();
   comment->SetValue(mainComment.c_str());  
	doc.LinkEndChild( comment );

   // Level
   TiXmlElement * level = new TiXmlElement( "level" );  
	doc.LinkEndChild( level );
   level->SetAttribute("name", "nemesis");
   level->SetDoubleAttribute("ver", 1.0);
   level->SetDoubleAttribute("blockWorldWidth", m_blockWorldWidth);
   level->SetDoubleAttribute("blockWorldHeight", m_blockWorldHeight);
   level->SetDoubleAttribute("blocksX", m_blocksX);
   level->SetDoubleAttribute("blocksY", m_blocksY);
   level->SetDoubleAttribute("heroStartX", m_heroStartPosition.getX());
   level->SetDoubleAttribute("heroStartY", m_heroStartPosition.getY());


   // Comment - Gaa
   TiXmlComment * comment2 = new TiXmlComment();
	comment2->SetValue(" Gaa " );  
	level->LinkEndChild( comment2 );

   // Map block images
   TiXmlElement* mapBlockImages = new TiXmlElement( "mapBlockImages" );  
	level->LinkEndChild( mapBlockImages );

   for(size_t i=0; i<m_images.size(); i++)
   {
      TiXmlElement* mapBlockImage;
      mapBlockImage = new TiXmlElement( "image" );   
	   mapBlockImages->LinkEndChild( mapBlockImage );
      mapBlockImage->SetAttribute("file", m_images[i]->getFilename().c_str());
   }

   // Map
   TiXmlElement* mapBlocks = new TiXmlElement( "mapBlocks" );  
	level->LinkEndChild( mapBlocks );

   for(size_t i=0; i<m_map.size(); i++)
   {
      TiXmlElement* block;
      block = new TiXmlElement( "block" );   
	   mapBlocks->LinkEndChild( block );
      block->SetAttribute("id", m_map[i]->getId());
   }

   doc.SaveFile(levelFile.c_str());
}

void
Level::load(Renderer* renderer, std::string levelFile)
{
   m_images.clear();
   m_map.clear();

   // Load level xml file
   TiXmlDocument doc(levelFile.c_str());
   bool loadOkay = doc.LoadFile();
   if(!loadOkay) return;

   TiXmlHandle hDoc(&doc);

   // Get level xml root
   TiXmlElement* pLevelNode = hDoc.FirstChild( "level" ).Element();

   // Level name
   // ----------
   // Get level name
   m_name = pLevelNode->Attribute("name");

   // Level version
   // -------------
   // Get level version (not needed for anythong yet)
   pLevelNode->QueryDoubleAttribute("ver", &m_version); 

   // Block world width
   // -----------------
   // Get width of map blocks
   pLevelNode->QueryDoubleAttribute("blockWorldWidth", &m_blockWorldWidth);

   // Block world height
   // ------------------
   // Get height of map blocks
   pLevelNode->QueryDoubleAttribute("blockWorldHeight", &m_blockWorldHeight);

   // Level width in blocks
   // ---------------------
   // Get width of level in map blocks
   pLevelNode->Attribute("blocksX", &m_blocksX);

   // Level height in blocks
   // ----------------------
   // Get height of level in map blocks
   pLevelNode->Attribute("blocksY", &m_blocksY);

   // Hero start X
   // ------------
   // Get X start position of hero in world units
   double heroStartWorldX, heroStartWorldY;
   pLevelNode->Attribute("heroStartX", &heroStartWorldX);

   // Hero start Y
   // ------------
   // Get Y start position of hero in world units
   pLevelNode->Attribute("heroStartY", &heroStartWorldY);
   m_heroShip->setPos(WorldPosition(heroStartWorldX, heroStartWorldY));

   // Level mapblock images
   // ---------------------
   // Get level handle for children
   TiXmlHandle hLevel(0);
   hLevel=TiXmlHandle(pLevelNode);

   // Get level mapblock filenames
   TiXmlElement* pImageNode=hLevel.FirstChild( "mapBlockImages" ).FirstChild().Element();
   for( pImageNode; pImageNode; pImageNode=pImageNode->NextSiblingElement())
	{
      // Get map block image filename
		const char *pImageFileName = pImageNode->Attribute("file");
      std::string filename(pImageFileName);

      // Create map block image
      MapBlockImagePtr mapBlockImage(
         new MapBlockImage(filename, renderer->createImage(filename)));
      
      // Store map block image
      m_images.push_back(mapBlockImage);
	}

   // Level mapblock array
   // --------------------
   TiXmlElement* pBlockNode=hLevel.FirstChild( "mapBlocks" ).FirstChild().Element();
   for( pBlockNode; pBlockNode; pBlockNode=pBlockNode->NextSiblingElement())
   {
      // Get map block image id
      int id;
      pBlockNode->QueryIntAttribute("id", &id);

      MapBlockPtr mapBlock(new MapBlock(id));
      m_map.push_back(mapBlock);
   }

   // Hero ship
   // Should only load if valid hero ship has not been passed in constructor
   // ---------
   int heroShipID;
   pLevelNode->Attribute("heroShipID", &heroShipID);

   TiXmlElement* pShipsNode = hLevel.FirstChild( "ships" ).FirstChild().Element();
   for( pShipsNode; pShipsNode; pShipsNode=pShipsNode->NextSiblingElement())
   {
      // Get ship id
      int id;
      pShipsNode->QueryIntAttribute("id", &id);

	  // Load hero ship if this one is it
	  if(id == heroShipID)
	  {
		  m_heroShip->load(renderer, pShipsNode);
	  }
   }
}

int 
Level::getMapBlockImageID(int x, int y) const
{
   int id = m_map[y*m_blocksX + x]->getId();
   return id;
}

void
Level::mouse(const ScreenPosition& pos)
{
   m_mousePos = pos;
}