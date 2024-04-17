#include "includes/Dog.hpp"
#include "includes/WrongCat.hpp"



int main()
{
    std::string number;
    std::string cat = "cat";
    std::cout << "How many animals would you like to create?"
    << std::endl;
    std::cin >> number;
    int n = std::atoi(number.c_str());
    Animal *animals[n];
    for(int i=0;i<n/2;i++){
        animals[i] = new Cat();
    }
    for(int i=n/2;i<n;i++){
        animals[i] = new Dog();
    }
    // Perform deep copy using copy constructor 
    //and copy assignment operator
    Animal *copiedAnimals[n];
    for (int i = 0; i < n; i++) {
        if(*animals[i] == cat)
            copiedAnimals[i] = new Cat();
        else
            copiedAnimals[i] = new Dog();
    }
    // Use animals and their copies
    for (int i = 0; i < n; ++i) {
        std::cout << "Animal " << i << ":" << std::endl;
        animals[i]->makeSound();
        animals[i]->display();
        std::cout << "Copied Animal " << i << ":" << std::endl;
        copiedAnimals[i]->makeSound();
        //copiedAnimals[i]->display();
    }
    // Cleanup - delete all animals
    for (int i = 0; i < n; i++) {
        delete animals[i];
        delete copiedAnimals[i];
    }
    return 0;
}