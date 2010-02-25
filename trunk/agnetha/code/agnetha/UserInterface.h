#ifndef USERINTERFACE_H
#define USERINTERFACE_H

// An abstract user interface state interface

#include <boost/shared_ptr.hpp>

// Forward declarations

enum Key
{
   kUp,
   kDown,
   kLeft,
   kRight,
   kFire
};

enum KeyState
{
	ksUp,
	ksDown,
	ksUnknownKeyState,
	ksUnknownKey
};


class UserInterface;
typedef boost::shared_ptr<UserInterface> UserInterfacePtr;
typedef boost::shared_ptr<const UserInterface> UserInterfaceConstPtr;

class UserInterface
{
public:
   // Constructors
   UserInterface();

   // Destructor
   virtual ~UserInterface();

public:
   virtual KeyState getKeyState(const Key& key) = 0;

   // Accessors

   // Operators

protected:

private:


};

#endif //USERINTERFACE_H
