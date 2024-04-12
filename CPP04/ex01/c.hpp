#ifndef C_H
#define C_H

class c {
public:
    c(); // Constructor
    c(const c& copy);//Copy constructor
    c& operator= (const c& copy); //Copy assignment constructor
    ~c(); // Destructor

private:
    // Add private members here
};

#endif // C_H
