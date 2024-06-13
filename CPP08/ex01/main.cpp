#include "includes/Span.hpp"

int main(){
    unsigned int maxN = 10000;
    srand(time(NULL));
    std::cout << GREEN << "------Creating span test1, with " << maxN 
    << " elements with random values\n" << RESET;
    Span test1(maxN);
    std::cout << CYAN << "------Testing addNumber until maxN\n" << RESET;
    for (size_t i = 0; i < maxN; i++)
    {
        test1.addNumber(rand());
    }
    std::cout << CYAN << "------Testing addNumber after maxN\n" << RESET;
    try{
        test1.addNumber(rand());
    }
    catch(std::exception& e){
        std::cerr << RED << e.what() << RESET <<  std::endl;
    }
    std::cout << CYAN << "------Testing copy constructor\n" << RESET;
    Span copyTest(test1);
    for (size_t i = 0; i < maxN; i++){
        if(test1.getVec()[i] != copyTest.getVec()[i])
            std::cout << RED << "Failure! " << test1.getVec()[i] <<
            " != " << copyTest.getVec()[i]<< RESET;
    }
    std::cout << CYAN << "------Testing copy assigment op\n" << RESET;
    Span copyOpTest;
    copyOpTest = copyTest;
    for (size_t i = 0; i < maxN; i++){
        if(test1.getVec()[i] != copyOpTest.getVec()[i])
            std::cout << RED << "Failure! " << test1.getVec()[i] <<
            " != " << copyOpTest.getVec()[i]<< RESET;
    }
    std::cout << GREEN << "------Creating span test2, with " << maxN 
    << " elements ranging from 1 to " << maxN - 1 << "\n" << RESET;
    Span test2(maxN);
    for (size_t i = 0; i < maxN; i++)
    {
        test2.addNumber(i);
    }
    std::cout << CYAN << "------Testing shortestSpan\n" << RESET;
    unsigned int span = test2.shortestSpan();
    if(span == 1)
        std::cout << GREEN << "Success!\n" << RESET;
    else
        std::cout << RED << "Failure! Span = " << span << "\n" << RESET;
    std::cout << CYAN << "------Testing longestSpan\n" << RESET;
    span = test2.longestSpan();
    if(span == (maxN - 1))
        std::cout << GREEN << "Success!\n" << RESET;
    else
        std::cout << RED << "Failure! Span = " << span << "\n" << RESET;
    maxN = 5;
    std::cout << GREEN << "------Creating span test3, with a maximum of " << maxN << " elements allowed\n" << RESET;
    Span test3(maxN);
    std::cout << CYAN << "------Adding numbers to test3, using a range of iterators\n" << RESET;
    int moreNumbersArray[] = {1, 4, 13};
    //The std::vector<int> moreNumbers is constructed using the array by specifying the range [begin, end].
    std::vector<int> moreNumbers(moreNumbersArray, moreNumbersArray + ARRAY_SIZE(moreNumbersArray));
    test3.addNumber(moreNumbers.begin(), moreNumbers.end());
    printContainer(test3.getVec());
    std::cout << CYAN << "------Testing shortestSpan\n" << RESET;
    span = test3.shortestSpan();
    if(span == 3)
        std::cout << GREEN << "Success!\n" << RESET;
    else
        std::cout << RED << "Failure! Span = " << span << "\n" << RESET;
    std::cout << CYAN << "------Testing longestSpan\n" << RESET;
    span = test3.longestSpan();
    if(span == (12))
        std::cout << GREEN << "Success!\n" << RESET;
    else
        std::cout << RED << "Failure! Span = " << span << "\n" << RESET;
    std::cout << CYAN << "------Testing addNumber (range of iterators) after maxN\n" << RESET;
    try{
        test3.addNumber(moreNumbers.begin(), moreNumbers.end());
    }
    catch(std::exception& e){
        std::cerr << RED << e.what() << RESET <<  std::endl;
    }
    Span test4(maxN);
    std::cout << CYAN << "------Testing shortestSpan with no numbers\n" << RESET;
    try
    {
        test4.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET <<  std::endl;
    }
    std::cout << CYAN << "------Testing longestSpan with 1 number\n" << RESET;
    test4.addNumber(rand());
    try
    {
        test4.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET <<  std::endl;
    }
}