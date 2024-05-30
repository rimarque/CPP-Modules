#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "ScalarType.hpp"

//ONLY ONE ESTATIC METOD
class ScalarConverter {
public:
    static void convert(char *str);
    private:
        ScalarConverter(); // Constructor
};

#endif // SCALARCONVERTER_HPP