#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137, "Default target"){

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137, target){

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other){

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
	if (this != &other){
		AForm::operator=(other);
	}

	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){

}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (AForm::beExecuted(executor) == true){
		//Creates a file <target>_shrubbery in the working directory and writes ASCII trees inside it.
		std::ofstream newFile(AForm::getTarget() + "_shrubbery");
		newFile << "               ,@@@@@@@," << std::endl
				<< "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl
				<< "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl
				<< "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl
				<< "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl
				<< "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl
				<< "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl
				<< "       |o|        | |         | |" << std::endl
				<< "       |.|        | |         | |" << std::endl
				<< "jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_"
				<< std::endl;
		newFile.close();
	}
}
