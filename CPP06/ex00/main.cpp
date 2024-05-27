#include "includes/ScalarConverter.hpp"

int main(int argv, char **argc)
{
  try{
    if(argv > 2 || argv == 1)
      throw MyException("Usage: ./ex00 data_to_convert");
    ScalarConverter::convert(argc[1]);
  }
  catch(const std::exception& e){
    std::cerr << e.what() << std::endl;
  }
}