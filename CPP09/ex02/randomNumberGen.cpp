# include <iostream>
# include <cstdlib>
# include <bits/stdc++.h>

bool    hasNonNumericChar(std::string str)
{
  for (std::string::const_iterator i = str.begin(); i != str.end(); ++i) {
        if (!std::isdigit(*i))
            return true;
  }
  return false;
}

bool isPosInt(std::string str){
    if(str.empty() || (hasNonNumericChar(str) == true))
        return false;
    long number = atol(str.c_str());
    if(number < 1 || number > INT_MAX)
        return false;
    return true;
}

int main(int argc, char **argv){
    if(argc != 2){
        std::cerr << "Wrong number of arguments\n" << std::endl;
        return 1;
    }
    if(isPosInt(argv[1]) == false){
        std::cout << "Not a positive interger" << std::endl;
        return 2;
    }
    int number = atoi(argv[1]);
    if (number > 3000){
        std::cout << "No numbers above 3000 allowed" << std::endl;
        return 3;
    }
    for(int i = 0; i < number; ++i){
        std::cout << 1 + std::rand() % 5000 << " ";
    }
    std::cout << std::endl;
}