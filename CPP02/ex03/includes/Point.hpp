#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point{
    private:
        Fixed const _x;
        Fixed const _y;
    
    public:
        //Default Constructor
        Point();
        //Copy Constructor
        Point::Point(const Point& copy);
        //Copy assignment operator overload
        Point& Point::operator= (const Point& copy);
        //Destructor
        ~Point();
};

#endif