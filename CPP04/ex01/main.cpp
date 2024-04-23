#include "includes/Dog.hpp"
#include "includes/WrongCat.hpp"

int main()
{
    std::string number;
    std::cout << "How many animals would you like to create?"
    << std::endl;
    std::cin >> number;
    int n = std::atoi(number.c_str());
    if (n < 0 || n > 10 || n % 2 != 0){
        std::cout << "Error: pick an even number between 2 and 10" << std::endl;
        exit(1);
    }
    if (n > 0)
    {
        std::cout << std::endl << GREEN << "-----Creating Array of\033[0m Animals:" << std::endl;
        Animal *animals[n];
        for(int i=0;i<n/2;i++){
            animals[i] = new Cat();
        }
        for(int i=n/2;i<n;i++){
            animals[i] = new Dog();
        }
        std::cout << std::endl << CYAN << "------DISPLAY ANIMAL ARRAY: "
        << RESET << std::endl;
        for (int i = 0; i < n; ++i) {
            std::cout << "Animal " << i + 1 << ":" << std::endl;
            animals[i]->makeSound();
            animals[i]->display();
            std::cout << std::endl;
        }
        std::cout << std::endl << RED << "------Deleting Array of\033[0m Animals:" << std::endl;
        for (int i = 0; i < n; i++) {
            delete animals[i];
        }
    }
    else
         std::cout << std::endl << RED <<"No array of animals has been created"
         << RESET << ", lest test our deep copys now!";
    std::cout << std::endl;
    std::cout << std::endl << GREEN << "-----Creating New\033[0m Cat:" << std::endl;
    Cat *cat = new Cat();
    cat->setBrain("I'm the original cat. Copy me!");
    std::cout << std::endl << GREEN << "-----Copying a New\033[0m Cat from the original to deepcpy1 (copy constructor):" << std::endl;
    Animal *deepcpy1 = new Cat(*cat);
    std::cout << std::endl << GREEN << "-----Creating New\033[0m Cat (deepcpy2):" << std::endl;
    Cat *deepcpy2 = new Cat();
    std::cout << std::endl << GREEN << "-----Copying \033[0m Cat from the original to deepcpy2 (copy assigment op):" << std::endl;
    *deepcpy2 = *cat;
    std::cout << std::endl << CYAN << "------DISPLAY CAT: "
    << RESET << std::endl;
    cat->makeSound();
    cat->display();
    std::cout << std::endl << CYAN << "------DISPLAY DEEPCOPY (copy constructor): "
    << RESET << std::endl;
    std::cout << deepcpy1->getType() << std::endl;
    deepcpy1->makeSound();
    deepcpy1->display();
    std::cout << std::endl << CYAN << "------DISPLAY DEEPCOPY (copy assigment op): "
    << RESET << std::endl;
    deepcpy2->makeSound();
    deepcpy2->display();
    std::cout << std::endl;
    std::cout << std::endl << RED << "------Deleting \033[0m Cat original:" << std::endl;
    delete cat;
    std::cout << std::endl << RED << "------Deleting \033[0m Cat copy (copy constructor):" << std::endl;
    delete deepcpy1;
    std::cout << std::endl << RED << "------Deleting \033[0m Cat copy (copy assigment op):" << std::endl;
    delete deepcpy2;

    std::cout << std::endl << GREEN << "-----Creating New\033[0m Dog:" << std::endl;
    Dog *dog = new Dog();
    dog->setBrain("I'm the original Dog. Copy me!");
    std::cout << std::endl << GREEN << "-----Copying a New\033[0m Dog from the original to deepcpy3 (copy constructor):" << std::endl;
    Animal *deepcpy3 = new Dog(*dog);
    std::cout << std::endl << GREEN << "-----Creating New\033[0m Dog (deepcpy2):" << std::endl;
    Dog *deepcpy4 = new Dog();
    std::cout << std::endl << GREEN << "-----Copying \033[0m Dog from the original to deepcpy4 (copy assigment op):" << std::endl;
    *deepcpy4 = *dog;
    std::cout << std::endl << CYAN << "------DISPLAY DOG: "
    << RESET << std::endl;
    dog->makeSound();
    dog->display();
    std::cout << std::endl << CYAN << "------DISPLAY DEEPCOPY (copy constructor): "
    << RESET << std::endl;
    deepcpy3->makeSound();
    deepcpy3->display();
    std::cout << std::endl << CYAN << "------DISPLAY DEEPCOPY (copy assigment op): "
    << RESET << std::endl;
    deepcpy4->makeSound();
    deepcpy4->display();
    std::cout << std::endl;
    std::cout << std::endl << RED << "------Deleting \033[0m Dog original:" << std::endl;
    delete dog;
    std::cout << std::endl << RED << "------Deleting \033[0m Dog copy (copy constructor):" << std::endl;
    delete deepcpy3;
    std::cout << std::endl << RED << "------Deleting \033[0m Dog copy (copy assigment op):" << std::endl;
    delete deepcpy4;
    return 0;
}