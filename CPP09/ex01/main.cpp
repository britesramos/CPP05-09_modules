#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        try{
            RPN rpn;
            rpn.execute(argv[1]);
            rpn.outputResult();
        }catch(std::exception &e){
            std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
        };
    }
    else
        std::cout << RED << "Wrong amount of arguments. [Please provide an Reverse Polish Notation expression surrounded by quotation marks.]" << RESET << std::endl; 
    //Program must take an inverted Polish mathematical expression as an argument.
    //The numbers passed as arguments will always be less than 10. (The calculation itself but also the result do not take into account this rule.)
    //Process expression and output the correct result on the std output.
    //If an error occurs during the execution of the program an error message should be displayed on the standard error.
    //Your program must be able to handle operations with these tokens: "+ - / *".
    return 0;
}