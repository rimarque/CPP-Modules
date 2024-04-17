#include "includes/Dog.hpp"
#include "includes/WrongCat.hpp"

/* int main()
{
    std::string number;
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
    std::cout << std::endl << CYAN << "DISPLAY ANIMAL ARRAY: "
    << RESET << std::endl;
    // Use animals and their copies
    for (int i = 0; i < n; ++i) {
        std::cout << "Animal " << i + 1 << ":" << std::endl;
        animals[i]->makeSound();
        animals[i]->display();
        std::cout << std::endl;
    }
    // Cleanup - delete all animals
    for (int i = 0; i < n; i++) {
        delete animals[i];
    }
    std::cout << std::endl;
    // Perform deep copy using copy constructor 
    Cat *cat = new Cat();
    Animal *deepcpy = new Cat(*cat);
    std::cout << std::endl << CYAN << "DISPLAY CAT: "
    << RESET << std::endl;
    cat->makeSound();
    cat->display();
    std::cout << std::endl << CYAN << "DISPLAY DEEPCOPY: "
    << RESET << std::endl;
    deepcpy->makeSound();
    deepcpy->display();
    std::cout << std::endl;
    delete cat;
    delete deepcpy;
    return 0;
} */

int main()
{
	//Animal	test;
	
	std::cout << "\n\033[32m------Creating \033[33mNew\033[0m Cat:" << std::endl;
	const Cat* originalA = new Cat();
	std::cout << "\n\033[32m------Copying a \033[33mNew\033[0m Cat from the original:" << std::endl;
	const Cat* copyA = new Cat(*originalA);
	std::cout << "\n\033[32m------Creating \033[33mNew\033[0m Dog:" << std::endl;
	const Dog* doggy = new Dog();
	{
		std::cout << "\n\033[32m------Copying a \033[33mNew \033[34mDog from the original on a specific scope:\033[0m" << std::endl;
		const Dog* temporary = new Dog(*doggy);
		std::cout << "\n\033[32m------Example of type: \033[0m" << temporary->getType() << std::endl;
		std::cout << "\n\033[32m------\033[31mDeleting \033[0m Dog temporary:" << std::endl;
		delete temporary;
		std::cout << "\n\033[32m------\033[34m//End of scope//\033[0m" << std::endl;
		std::cout << std::endl;
	}
	originalA->makeSound();
	copyA->makeSound();
	doggy->makeSound();
	std::cout << "\n\033[32m------\033[31mDeleting \033[0m Cat copy:" << std::endl;
	delete copyA;
	std::cout << "\n\033[32m------\033[31mDeleting \033[0m Cat original:" << std::endl;
	delete originalA;
	std::cout << "\n\033[32m------\033[31mDeleting \033[0m Dog original:" << std::endl;
	delete doggy;
}