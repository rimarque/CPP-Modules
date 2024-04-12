#ifndef B_H
#define B_H

class b {
public:
    b(); // Constructor
    b(const b& copy);//Copy constructor
    b& operator= (const b& copy); //Copy assignment constructor
    ~b(); // Destructor

private:
    // Add private members here
};

#endif // B_H
