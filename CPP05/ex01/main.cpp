#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "\n---- Creating Forms ----\n" << std::endl;
    
    Form defaultForm;
    std::cout << defaultForm << std::endl;
    
    Form taxForm("Tax Declaration", 50, 25);
    std::cout << taxForm << std::endl;
    
    Form copyForm(taxForm);
    std::cout << copyForm << std::endl;
    
    Form assignedForm;
    assignedForm = taxForm;
    std::cout << assignedForm << std::endl;
    
    std::cout << "\n---- Testing Form Exceptions ----\n" << std::endl;
    
    try {
        Form invalidForm1("Invalid High", 0, 10);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    try {
        Form invalidForm2("Invalid Low", 151, 10);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n---- Testing Invalid Forms ----\n" << std::endl;
    
    try {
        Form contractFormTooLow("Contract", 151, 50);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try {
        Form contractFormTooHigh("Contract", 0, 50);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n---- Testing Bureaucrats with Forms ----\n" << std::endl;
    
    Bureaucrat boss("Director", 1);
    Bureaucrat manager("Manager", 40);
    Bureaucrat intern("Intern", 150);
    
    std::cout << boss << std::endl;
    std::cout << manager << std::endl;
    std::cout << intern << std::endl;

    Form contractForm("Contract", 100, 50);
    std::cout << contractForm << std::endl;
    
    std::cout << "\n---- Testing Form Signing ----\n" << std::endl;
    
    boss.signForm(contractForm);
    
    Form contractForm2("Contract 2", 100, 50);
    
    manager.signForm(contractForm2);
    
    Form topSecretForm("Top Secret", 20, 10);
    
    intern.signForm(topSecretForm);
    
    manager.signForm(topSecretForm);
    
    boss.signForm(topSecretForm);

    boss.signForm(topSecretForm);

    manager.signForm(contractForm);
    
    std::cout << "\n---- End of Tests ----\n" << std::endl;
    
    return 0;
}