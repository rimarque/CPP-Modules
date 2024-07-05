#include "includes/RPN.hpp"

MyException::MyException(const std::string& msg): _msg(msg) {}

const char* MyException::what() const throw(){
    return _msg.c_str();
}

MyException::~MyException() throw() {}

RPN::RPN() {
    std::cout << BOLD_WHITE << "RPN" << RESET 
    << " default constructor called" << std::endl;
}

// Copy constructor
RPN::RPN(const RPN& copy) {
    _stack = copy._stack;
    std::cout << BOLD_WHITE << "RPN" << RESET 
    << " copy constructor called" << std::endl;
}

// Copy assignment operator overload
RPN& RPN::operator= (const RPN& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    _stack = copy._stack;
    std::cout << BOLD_WHITE << "RPN" << RESET 
    << " copy assignment operator overload" << std::endl;
    return *this;
}

/* bool empty() const: Checks whether the stack is empty.
size_type size() const: Returns the number of elements in the stack.
value_type &top(): Returns a reference to the top element in the stack.
const value_type &top() const: Returns a constant reference to the top element in the stack.
void push(const value_type &val): Pushes an element onto the stack.
void pop(): Removes the top element from the stack.
void swap(stack &other): Swaps the contents of this stack with another. */

//Your program must be able to handle operations with these tokens: "+,43 -,45 /,47 *,42"

float math_op(float first_op, float second_op, int op){
    switch (op) {
        case 43:
            return first_op + second_op;
        case 45:
            return first_op - second_op;
        case 42:
            return first_op * second_op;
        case 47:
            if (second_op != 0)
                return first_op / second_op;
            else
                return 0;
        default:
            return 0;
    }
}

//invalid, sem operador para a quatidade de numeros
float RPN::calculate(std::queue<int> q){
    //The first two elements must be numbers
    if(q.front() < 10){
        _stack.push(q.front());
        q.pop();
    }
    else
        throw MyException("Invalid expression 1");
    if(q.front() < 10){
        _stack.push(q.front());
        q.pop();
    }
    else
        throw MyException("Invalid expression 2");;
    if(q.empty())
        throw MyException("Invalid expression 3");
    float result;
    while(!q.empty()){
        //When we find an operator in front of the queue we do the math
        if(q.front() > 10){
            float second_operand = _stack.top();
            _stack.pop();
            //There is only 1 operand, so no math_op is possible =>  4 5 + -
            if(_stack.empty())
                throw MyException("Invalid expression 4");
            result = math_op(_stack.top(), second_operand, q.front());
            _stack.pop();
            if(!_stack.empty())
                _stack.push(result);
        }
        //If it's a number we add it to the stack
        else
            _stack.push(q.front());
        q.pop();
    }
    //In case there are still numbers in the stack => 1 7 3 5 + * 
    if(!_stack.empty())
        throw MyException("Invalid expression 5");
    return result;
}

RPN::~RPN() {
    std::cout << BOLD_WHITE << "RPN" << RESET 
    << " destructor called" << std::endl;
}
