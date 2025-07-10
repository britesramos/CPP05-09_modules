#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	try{
		Bureaucrat bob("Bob", 50);
		Form form1;
		Form form2("Very important form2!", 100, 100);
		std::cout << "Bob grade: " << bob.getGrade() << std::endl;
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		
		bob.signForm(form1, bob);
		bob.signForm(form2, bob);

		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
	}
	catch (std::exception &e){
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
}