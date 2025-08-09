#pragma once

#include <stack>
#include <iostream>
#include <string>
#include <sstream>

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define PINK "\033[35m"
#define YELLOW "\033[33m"
#define RED "\033[31m"

class RPN
{
    private:
        std::stack<unsigned int> _stack;

    public:
        RPN();
        RPN(const RPN& other);
        const RPN& operator=(const RPN& other);
        ~RPN();

        void execute(std::string input);
        bool isoperator(std::string token);
        void operationExecution(std::string token);
        void outputResult();

        std::stack<std::string> getStack();

};