#include "includes/Brain.hpp"

Brain::Brain() {
    std::string random_ideas = "A";
    // Initialize _ideas array with 100 random ideas
    int j=0, i=0;
    while (j < 100) {
        _ideas[j] = random_ideas;
        if(i == 25)
            random_ideas[0] += 6;
        if(i > 50){
            random_ideas[0] = 'A';
            i = -1;
        }
        else
            random_ideas[0]++;
        j++;
        i++;
    }
    std::cout << BOLD_WHITE << "Brain" << RESET
    << " default constructor called" << std::endl;
}

// Copy constructor
Brain::Brain(const Brain& copy) {
     // Perform deep copy of the _ideas array
    for (int i = 0; i < 100; ++i) {
        this->_ideas[i] = copy._ideas[i];
    }
    std::cout << BOLD_WHITE << "Brain" << RESET 
    << " copy constructor called" << std::endl;
}

// Copy assignment operator overload
Brain& Brain::operator= (const Brain& copy) {
    // Self-assignment check
    if(this == &copy)
        return(*this);
    for (int i = 0; i < 100; ++i) {
            this->_ideas[i] = copy._ideas[i];
    }
    std::cout << BOLD_WHITE << "Brain" << RESET 
    << " copy assignment operator overload" << std::endl;
    return (*this);
}

void    Brain::displayIdeas() const
{
    std::cout << "Display ideas: ";
    for (int i = 0; i < 100; i++) {
        std::cout << _ideas[i];
    }
    std::cout << std::endl;
    return ;
}

void    Brain::setIdeas(std::string ideas)
{
    static int i = 0; 
    std::cout << "Calling setIdeas...\n";
    _ideas[i] = ideas;
}

Brain::~Brain() {
    std::cout << BOLD_WHITE << "Brain" << RESET 
    << " destructor called" << std::endl;
}