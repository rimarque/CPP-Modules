#include "includes/RPN.hpp"

MyException::MyException(const std::string& msg): _msg(msg) {}

const char* MyException::what() const throw(){
    return _msg.c_str();
}

MyException::~MyException() throw() {}

RPN::RPN() {}

// Copy constructor
RPN::RPN(const RPN& copy) {
    _stack = copy._stack;
}

// Copy assignment operator overload
RPN& RPN::operator= (const RPN& copy) {
    // Self-assignment check
    if (this == &copy)
        return *this;
    _stack = copy._stack;
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

// Print the stack
void shows(std::stack<float> st)
{
    std::stack<float> s = st;
    while (!s.empty()) {
        std::cout << s.top() << " "; 
        s.pop();
    }
    std::cout << '\n';
}

// Print the queue
void showq(std::queue<int> gq)
{
    std::queue<int> g = gq;
    while (!g.empty()) {
        std::cout << g.front() << " "; 
        g.pop();
    }
    std::cout << '\n';
}

float RPN::calculate(std::queue<int> q){
    //The first two elements must be numbers
    for(int i = 0; i < 2; ++i){
        if(q.front() < 10){
            _stack.push(q.front());
            q.pop();
        }
        else
            throw MyException("Invalid expression");
    }
    if(q.empty())
        throw MyException("Invalid expression");
    
    float result;
    while(!q.empty()){
        //When we find an operator in front of the queue we do the math
        if(q.front() > 10){
            float second_operand = _stack.top();
            _stack.pop();
            //There is only 1 operand, so no math_op is possible =>  4 5 + - (to many operators for the operands)
            if(_stack.empty())
                throw MyException("Invalid expression");
            result = math_op(_stack.top(), second_operand, q.front());
            _stack.pop();
            _stack.push(result);
        }
        //If it's a number we add it to the stack
        else
            _stack.push(q.front());
        q.pop();
    }
    //In case there are numbers other then the last result in the stack => 1 7 3  + * (to many operands for the operators)
    if(_stack.size() > 1)
        throw MyException("Invalid expression");
    return result;
}

RPN::~RPN() {}
