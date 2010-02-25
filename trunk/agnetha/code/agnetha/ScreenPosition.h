#ifndef SCREENPOSITION_H
#define SCREENPOSITION_H

class ScreenPosition
{
public:
   // Constructors
   ScreenPosition(const ScreenPosition& position);
   ScreenPosition(double x, double y);

   // Destructor
   virtual ~ScreenPosition();

   // Accessors
   double getX() const;
   double getY() const;

   // Operators
   ScreenPosition& operator=(const ScreenPosition& other);

private:
   double m_x;
   double m_y;
};

#endif //SCREENPOSITION_H