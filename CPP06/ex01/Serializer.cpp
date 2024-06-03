#include "includes/Serializer.hpp"

Serializer::Serializer() {
    std::cout << BOLD_WHITE << "Serializer" << RESET 
    << " default constructor called" << std::endl;
}

//It takes a pointer and converts it to the unsigned integer type uintptr_t.
//uintptr_t is an unsigned integer type in C/C++ that is capable of storing a pointer
uintptr_t Serializer::serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

//It takes an unsigned integer parameter and converts it to a pointer to Data
Data* Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data *>(raw);
}