#include "includes/C.hpp"
#include "includes/Base.hpp"

int    identify_ptr_ABC_test(){
    Base *ptrToRandomClass = generate();
    std::cout << CYAN << "--------Identify ptr test (ptr to A, B or C): \n" << RESET
    "Expected result: A, B or C \n" << "Actual result: ";
    identify(ptrToRandomClass);
    std::cout << std::endl << "<---------------------------------------------->\n\n";
    delete ptrToRandomClass;
    return 0;
}

int    identify_ptr_base_test(){
    Base *ptrToRandomClass = new Base;
    std::cout << CYAN << "--------Identify ptr test (ptr to base): \n" << RESET
    "Expected result: ups! Some other type\n" << "Actual result: ";
    identify(ptrToRandomClass);
    std::cout << std::endl << "<---------------------------------------------->\n\n";
    delete ptrToRandomClass;
    return 0;
}

int    identify_reference_ABC_test(){
    Base *ptrToRandomClass = generate();
    std::cout << CYAN << "--------Identify reference test (ptr to A, B or C): \n" << RESET
    "Expected result: A, B or C \n" << "Actual result: ";
    identify(*ptrToRandomClass);
    std::cout << std::endl << "<---------------------------------------------->\n\n";
    delete ptrToRandomClass;
    return 0;
}

int    identify_reference_base_test(){
    Base *ptrToRandomClass = new Base;
    std::cout << CYAN << "--------Identify reference test (ptr to base): \n" << RESET
    "Expected result: std::bad_cast\n" << "Actual result: ";
    identify(*ptrToRandomClass);
    std::cout << std::endl << "<---------------------------------------------->\n\n";
    delete ptrToRandomClass;
    return 0;
}

int main(){
    int (*tests[])() = {&identify_ptr_ABC_test, &identify_ptr_base_test, 
                            &identify_reference_ABC_test, &identify_reference_base_test};
    int number_of_tests = ARRAY_SIZE(tests);
    for(int i = 0; i < number_of_tests; i++){
        tests[i]();
    }
}