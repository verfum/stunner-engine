#include "cBlitzComms.h"

#include "entity.h"
#include "blitzimage.h"

#include <math.h>
#include <stdio.h>
#include "BlitzRenderer.h"
#include "BlitzUserInterface.h"

#include "WorldPosition.h"

#include "Level.h"
#include "Ship.h"

//Write your game/application here
static const int cWindowWidth = 640;
static const int cWindowHeight = 512;
//static const double cWindowWidth = 320.0;
//static const double cWindowHeight = 256.0;

double gViewWidth = 320.0; //World units
double gViewHeight = 256.0; //World units

double gViewX = 160; // Center of view in world units
double gViewY = 128;

void ezRunApp()
{

   UserInterface* userInterface = new BlitzUserInterface();
 

   Renderer* renderer = new BlitzRenderer(View(WorldPosition(gViewX,gViewY), // Center of view in world coords
                                               ScreenPosition(0,0),    // Top-left of view in screen coords
                                               gViewWidth, gViewHeight,               // Dimensions of view in world units
                                               cWindowWidth, cWindowHeight));             // Dimensions of view in screen units



   ShipPtr heroShip(new Ship());
   Level level1(heroShip);

   ezGraphics(cWindowWidth,cWindowHeight);

   ImagePtr img = renderer->createImage("gfx\\paxton.jpg");

   //Level level1;
   level1.load(renderer, "..\\level1.xml");
   //level1.load(renderer, "..\\out.xml");
   //level1.save("..\\out.xml");
   //return;

   

//double scale = 8.0; // This is just a test - not supported at all!!

   //ezSetScale(scale, scale);
   //renderer->setScale(scale);
   while(!ezKeyHit(13) && !ezKeyHit(27)) // Enter or Escape
   {
      ezCls();

      if(ezKeyDown(65))
      {
         gViewY -= 0.2;
         renderer->setViewWorldPosition(WorldPosition(gViewX,gViewY));
      }
      else if(ezKeyDown(90))
      {
         gViewY += 0.2;
         renderer->setViewWorldPosition(WorldPosition(gViewX,gViewY));
      }
      else if(ezKeyDown(83))
      {
         gViewHeight *= 0.99;
         gViewWidth *= 0.99;
         renderer->setViewWorldHeight(gViewHeight);
         renderer->setViewWorldWidth(gViewWidth);

      }
      else if(ezKeyDown(88))//X
      {
         gViewHeight *= 1.01;
         gViewWidth *= 1.01;
         renderer->setViewWorldHeight(gViewHeight);
         renderer->setViewWorldWidth(gViewWidth);
      }

      //renderer->drawImage(img, ScreenPosition(20,20));
      //renderer->drawLine(ScreenPosition(20,20), ScreenPosition(40,40), Colour(128, 255, 0, 0));  
      level1.update(renderer, userInterface, 1000/30);
   // To prevent collision issues could update multi times before draw e.g...
   //level1.update(1000/10);
   //level1.update(1000/10);
   //level1.update(1000/10);
      level1.draw(renderer);

      //ezDrawImage(plyr, 100,100);



      int maysx = ezMouseX();
      int maysy = ezMouseY();
      char ayt[256];
      sprintf_s(ayt,"Mouse=%i %i", maysx, maysy);
            level1.mouse(ScreenPosition(maysx, maysy));
      ezDrawText(ayt, 0,0);
      ezFlip();
   }
}