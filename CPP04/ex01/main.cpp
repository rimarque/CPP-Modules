#include "includes/Dog.hpp"
#include "includes/WrongCat.hpp"

int main()
{
    std::string number;
    std::cout << "How many animals would you like to create?"
    << std::endl;
    std::cin >> number;
    int n = std::atoi(number.c_str());
    if (n <= 1 || n > 10 || n % 2 != 0){
        std::cout << "Error: pick an even number between 2 and 10" << std::endl;
        exit(1);
    }
    std::cout << CYAN <<"------Creating Array of\033[0m Animals:" << std::endl;
    Animal *animals[n];
    for(int i=0;i<n/2;i++){
        animals[i] = new Cat();
    }
    for(int i=n/2;i<n;i++){
        animals[i] = new Dog();
    }
    std::cout << std::endl << CYAN << "------DISPLAY ANIMAL ARRAY: "
    << RESET << std::endl;
    // Use animals and their copies
    for (int i = 0; i < n; ++i) {
        std::cout << "Animal " << i + 1 << ":" << std::endl;
        animals[i]->makeSound();
        animals[i]->display();
        std::cout << std::endl;
    }
    std::cout << "\n\033[32m------Deleting Array of\033[0m Animals:" << std::endl;
    for (int i = 0; i < n; i++) {
        delete animals[i];
    }
    std::cout << std::endl;
    std::cout << "\n\033[32m------Creating New\033[0m Cat:" << std::endl;
    Cat *cat = new Cat();
    std::cout << "\n\033[32m------Copying a New\033[0m Cat from the original to deepcpy1 (copy constructor):" << std::endl;
    Animal *deepcpy1 = new Cat(*cat);
    std::cout << "\n\033[32m------Creating New\033[0m Cat (deepcpy2):" << std::endl;
    Cat *deepcpy2 = new Cat();
    std::cout << "\n\033[32m------Copying \033[0m Cat from the original to deepcpy2 (copy assigment op):" << std::endl;
    *deepcpy2 = *cat;
    std::cout << std::endl << CYAN << "------DISPLAY CAT: "
    << RESET << std::endl;
    cat->makeSound();
    cat->display();
    std::cout << std::endl << CYAN << "------DISPLAY DEEPCOPY (copy constructor): "
    << RESET << std::endl;
    deepcpy1->makeSound();
    deepcpy1->display();
    std::cout << std::endl << CYAN << "------DISPLAY DEEPCOPY (copy assigment op): "
    << RESET << std::endl;
    deepcpy2->makeSound();
    deepcpy2->display();
    std::cout << std::endl;
    std::cout << "\n\033[32m------Deleting \033[0m Cat original:" << std::endl;
    delete cat;
    std::cout << "\n\033[32m------Deleting \033[0m Cat copy (copy constructor):" << std::endl;
    delete deepcpy1;
    std::cout << "\n\033[32m------Deleting \033[0m Cat copy (copy assigment op):" << std::endl;
    delete deepcpy2;
    return 0;
}