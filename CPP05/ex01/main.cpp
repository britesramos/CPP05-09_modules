#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	try{
		Bureaucrat bob("Bob", 50);
		Form form1;
		Form form2("Very important Form2!", 100, 100);
		Form form3("Form3", 49, 100);
		std::cout << bob << std::endl;
		// std::cout << form1 << std::endl;
		// std::cout << form2 << std::endl;
		// std::cout << form3 << std::endl;
		
		bob.signForm(form1);
		bob.signForm(form2);
		bob.signForm(form3);
		bob.incrementGrade();
		bob.signForm(form3);

		// std::cout << form1 << std::endl;
		// std::cout << form2 << std::endl;
		// std::cout << form3 << std::endl;

		Bureaucrat jack("Jack", 1);
		jack.incrementGrade();
	}
	catch (std::exception &e){
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}