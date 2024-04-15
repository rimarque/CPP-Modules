#include "includes/Dog.hpp"
#include "includes/WrongCat.hpp"



int main()
{
    std::string number;
    std::cout << "How many animals would you like to create?"
    << std::endl;
    std::cin >> number;
    int n = std::atoi(number.c_str());
    Animal *animals = new Animal[n];
    for(int i=0;i<n/2;i++){
        animals[i] = Cat();
    }
    for(int i=n/2;i<n;i++){
        animals[i] = Dog();
    }
    delete[] animals;
    return 0;
}