#ifndef WORLDPOSITION_H
#define WORLDPOSITION_H

class WorldPosition
{
public:
   // Constructors
   WorldPosition(const WorldPosition& position);
   WorldPosition(double x, double y);

   // Destructor
   virtual ~WorldPosition();

   // Accessors
   double getX() const;
   double getY() const;
   double distanceTo(const WorldPosition& b) const;
   void moveY(double amount);
   void moveX(double amount);

   // Operators
   WorldPosition& operator=(const WorldPosition& other);

private:
   double m_x;
   double m_y;
};

#endif //WORLDPOSITION_H