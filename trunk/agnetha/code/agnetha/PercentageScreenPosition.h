#ifndef PERCENTAGESCREENPOSITION_H
#define PERCENTAGESCREENPOSITION_H

class PercentageScreenPosition
{
public:
   // Constructors
   PercentageScreenPosition(const PercentageScreenPosition& position);
   PercentageScreenPosition(double x, double y);

   // Destructor
   virtual ~PercentageScreenPosition();

   // Accessors
   double getX() const;
   double getY() const;

   // Operators
   PercentageScreenPosition& operator=(const PercentageScreenPosition& other);

private:
   double m_x;
   double m_y;
};

#endif //PERCENTAGESCREENPOSITION_H