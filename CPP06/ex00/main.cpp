#include "includes/ScalarConverter.hpp"

int main(int argc, char **argv)
{
  try{
    if(argc > 2 || argc == 1)
      throw MyException("Usage: ./ex00 data_to_convert");
    ScalarConverter::convert(argv[1]);
  }
  catch(const std::exception& e){
    std::cerr << e.what() << std::endl;
  }
}