#include "BlitzUserInterface.h"
#include "cBlitz.h"

BlitzUserInterface::BlitzUserInterface(void)
{
}

BlitzUserInterface::~BlitzUserInterface(void)
{
}

KeyState
BlitzUserInterface::getKeyState(const Key& key)
{
   KeyState ret = ksUp;

	switch(key)
	{
	   case kLeft:
	   {
         if(ezKeyDown(37))
            ret = ksDown;
         break;
	   }
      case kRight:
	   {
         if(ezKeyDown(39))
            ret = ksDown;
         break;
	   }
      case kUp:
	   {
         if(ezKeyDown(38))
            ret = ksDown;
         break;
	   }
      case kDown:
	   {
         if(ezKeyDown(40))
            ret = ksDown;
         break;
	   }
         

	/*	
   kUp,
   kDown,
   kLeft,
   kRight,
   kFire*/
	}
	return ret;
}
