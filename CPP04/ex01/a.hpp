#ifndef A_H
#define A_H

class a {
public:
    a(); // Constructor
    a(const a& copy);//Copy constructor
    a& operator= (const a& copy); //Copy assignment constructor
    ~a(); // Destructor

private:
    // Add private members here
};

#endif // A_H
