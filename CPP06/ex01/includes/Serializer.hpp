#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string.h>
# include <unistd.h>
# include <cstdlib>
# include <ctime>
# include <stdint.h>
# define RED "\033[31m"
# define GREEN "\033[32m"
# define PURPLE "\033[35m"
# define YELLOW "\033[33m"
# define WHITE "\033[37m"
# define CYAN "\033[36m"
# define BOLD_RED "\033[1;31m"
# define BOLD_GREEN "\033[1;32m"
# define BOLD_PURPLE "\033[1;35m"
# define BOLD_YELLOW "\033[1;33m"
# define BOLD_WHITE 	"\033[1;37m"
# define BOLD_CYAN "\033[1;36m"
# define RESET "\033[0m"

typedef struct Data{
    int data;
} Data;

//You must create a non-empty (it means it has data members) Data structure.

/* Use serialize() on the address of the Data object and pass its return value to
deserialize(). Then, ensure the return value of deserialize() compares equal to the
original pointer. */
class Serializer {
public:
    //It takes a pointer and converts it to the unsigned integer type uintptr_t.
    static uintptr_t serialize(Data* ptr);
    //It takes an unsigned integer parameter and converts it to a pointer to Data
    Data* deserialize(uintptr_t raw);

private:
    Serializer(); // Constructor
};

#endif // SERIALIZER_HPP
