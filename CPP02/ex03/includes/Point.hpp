#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point{
    private:
        Fixed  const _x;
        Fixed  const _y;
    
    public:
        //Default Constructor //*FUNCIONA
        Point();
        //Copy Constructor
        Point(const Point& copy); //*FUNCIONA
        //Float Constructor
        Point(const float x, const float y); //*FUNCIONA
        //Copy assignment operator overload
        Point&          operator= (const Point& copy); //*FUNCIONA
        //returns the Fixed_x
        Fixed           getFixed_x( void ) const; //*FUNCIONA
        //returns the Fixed_y
        Fixed           getFixed_y( void ) const; //*FUNCIONA
        //sets the Fixed_x
        void            setFixed_x( Fixed const fixedN); //*FUNCIONA
        //sets the Fixed_y
        void            setFixed_y( Fixed const fixedN); //*FUNCIONA
        void            setFixed( Fixed const fixedX, Fixed const fixedY); //*FUNCIONA
        static Fixed    getTriangleArea(Point const a, Point const b, Point const c);
        //Destructor
        ~Point(); //*FUNCIONA
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif