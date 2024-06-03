#include "includes/C.hpp"

Base::~Base() {
/*     std::cout << BOLD_WHITE << "Base" << RESET 
    << " destructor called" << std::endl; */
}

Base    *CreateA() {
    return new A();
}

Base    *CreateB() {
    return new B();
}

Base    *CreateC() {
    return new C();
}

/* It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
to use anything you like for the random choice implementation. */
Base *generate(void){
    std::srand((unsigned int)(std::time(0)));
    Base    *(*create[])() = {&CreateA, &CreateB, &CreateC};
    Base    *pointer;
    int     i = rand() % 3;
    pointer = (*create[i])();
    return pointer;
}

/* It prints the actual type of the object pointed to by p: "A", "B" or "C". */
void identify(Base* p){
    if(dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if(dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if(dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cerr << "ups! Some other type\n";
    std::cout << "Pointer identifyer called!\n";
}

/* It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
inside this function is forbidden. */
//Como as referencias nao podem ser nulas, usamos a excecao que e feita quanto o casting falha
void identify(Base& p){
    try{
        A test = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    }
    catch(std::exception& e){
        (void)e;
    }
    try{
        B test = dynamic_cast<B &>(p);
        (void)p;
        std::cout << "B" << std::endl;
    }
    catch(std::exception& e){
        (void)e;
    }
    try{
        C test = dynamic_cast<C &>(p);
        (void)p;
        std::cout << "C" << std::endl;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << "Reference identifyer called!\n";
}