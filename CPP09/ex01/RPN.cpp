#include "RPN.hpp"

RPN::RPN(){
    // std::cout << YELLOW << "RPN default constructor called." << RESET << std::endl;
}

RPN::RPN(const RPN& other){
    *this = other;
}

const RPN& RPN::operator=(const RPN& other){
    if (this != &other){
        this->_stack = other._stack;
    }
    return *this;
}

RPN::~RPN(){
    // std::cout << YELLOW << "RPN default destructor called." << RESET << std::endl;
}


bool RPN::isoperator(std::string token)
{
    if (token == "-" || token == "+" || token == "*" || token == "/")
        return true;
    return false;
}

void RPN::operationExecution(std::string token)
{
    unsigned int first = this->_stack.top();
    this->_stack.pop();
    unsigned int second = this->_stack.top();
    this->_stack.pop();
    unsigned int res;
    if (token == "+")
        res = first + second;
    else if (token == "-")
        res = second - first;
    else if (token == "*")
        res = second * first;
    else if (token == "/")
        res = first / second;
    this->_stack.push(res);
}

void RPN::execute(std::string input){
    std::istringstream iss(input);
    std::string token;
    while(iss >> token)
    {
        // std::cout << "TOKEN: " << token << std::endl; //temp
        if (token.length() == 1 && std::isdigit(static_cast<unsigned char>(token[0]))){
            // std::cout << token << " => is a digit." << std::endl; //temp
            unsigned int newElement = static_cast<unsigned int>(token[0]) - 48;
            this->_stack.push(newElement);
        }

        else if (isoperator(token)){
            // std::cout << token << " => is a operator." << std::endl; //temp
            operationExecution(token);
        }
        else
            throw std::runtime_error("Invalid input.");
    }
}

void RPN::outputResult(){
    std::cout << GREEN << this->_stack.top() << RESET << std::endl;
}