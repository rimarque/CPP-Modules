#include "includes/MutantStack.hpp"

/* bool empty() const: Checks whether the stack is empty.
size_type size() const: Returns the number of elements in the stack.
value_type &top(): Returns a reference to the top element in the stack.
const value_type &top() const: Returns a constant reference to the top element in the stack.
void push(const value_type &val): Pushes an element onto the stack.
void pop(): Removes the top element from the stack.
void swap(stack &other): Swaps the contents of this stack with another. */

int main() {
    MutantStack<int> mstack;

    // Test inherited member functions
    std::cout << CYAN << "--------Testing stack member functions:" << RESET << std::endl;
    
    std::cout << "Pushing elements onto the stack..." << std::endl;
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);

    std::cout << "Top element: " << mstack.top() << std::endl; // Should output 30
    mstack.pop();
    std::cout << "After pop, top element: " << mstack.top() << std::endl; // Should output 20

    std::cout << "Is stack empty? " << (mstack.empty() ? "Yes" : "No") << std::endl; // Should output No
    std::cout << "Stack size: " << mstack.size() << std::endl; // Should output 2

    // Test new iterator functions
    std::cout << CYAN << "\n--------Testing iterator functions with mstack:" << RESET << std::endl;

    std::cout << "Pushing more elements onto the stack..." << std::endl;
    mstack.push(40);
    mstack.push(50);

    std::cout << "Stack elements (using iterator): ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Stack elements (using const_iterator): ";
    for (MutantStack<int>::const_iterator cit = mstack.begin(); cit != mstack.end(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;

    std::cout << "Stack elements in reverse (using reverse_iterator): ";
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    std::cout << "Stack elements in reverse (using const_reverse_iterator): ";
    for (MutantStack<int>::const_reverse_iterator crit = mstack.rbegin(); crit != mstack.rend(); ++crit) {
        std::cout << *crit << " ";
    }
    std::cout << std::endl;

    // Test copy constructor and assignment operator
    std::cout << CYAN <<"\n---------Testing copy constructor and assignment operator:" << RESET << std::endl;
    
    MutantStack<int> copyStack(mstack);
    std::cout << "Copy stack elements: ";
    for (MutantStack<int>::iterator it = copyStack.begin(); it != copyStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    MutantStack<int> assignedStack;
    assignedStack = mstack;
    std::cout << "Assigned stack elements: ";
    for (MutantStack<int>::iterator it = assignedStack.begin(); it != assignedStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
