#ifndef BLITZUSERINTERFACE_H
#define BLITZUSERINTERFACE_H

#include "UserInterface.h"
#include <boost/shared_ptr.hpp>

class BlitzUserInterface;
typedef boost::shared_ptr<BlitzUserInterface> BlitzUserInterfacePtr;
typedef boost::shared_ptr<const BlitzUserInterface> BlitzUserInterfaceConstPtr;

class BlitzUserInterface :
	public UserInterface
{
public:
	BlitzUserInterface(void);
	virtual ~BlitzUserInterface(void);

	KeyState getKeyState(const Key& key);
};

#endif //BLITZUSERINTERFACE_H
