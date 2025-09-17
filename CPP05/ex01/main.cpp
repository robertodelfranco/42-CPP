#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "\n---- Creating Forms ----\n" << std::endl;
    
    // Testando construtores normais
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
    
    // Testando exceções de grade muito alto/baixo
    try {
        Form invalidForm1("Invalid High", 0, 10);  // Grade too high
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    try {
        Form invalidForm2("Invalid Low", 151, 10);  // Grade too low
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n---- Testing Invalid Forms ----\n" << std::endl;
    
    try {
        Form contractFormTooLow("Contract", 151, 50); // Invalid grade to sign
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try {
        Form contractFormTooHigh("Contract", 0, 50); // Invalid grade to sign
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n---- Testing Bureaucrats with Forms ----\n" << std::endl;
    
    // Criando alguns burocratas com diferentes níveis
    Bureaucrat boss("Director", 1);      // Highest rank
    Bureaucrat manager("Manager", 40);   // Mid rank
    Bureaucrat intern("Intern", 150);    // Lowest rank
    
    std::cout << boss << std::endl;
    std::cout << manager << std::endl;
    std::cout << intern << std::endl;

    // Formulário que requer grade 100 para assinar
    Form contractForm("Contract", 100, 50);
    std::cout << contractForm << std::endl;
    
    std::cout << "\n---- Testing Form Signing ----\n" << std::endl;
    
    // Todos devem conseguir assinar
    boss.signForm(contractForm);
    
    // Criar um novo formulário já que o anterior já foi assinado
    Form contractForm2("Contract 2", 100, 50);
    
    // Gerente também deve conseguir assinar (grade 40 < 100)
    manager.signForm(contractForm2);
    
    // Criar um novo formulário mais restrito
    Form topSecretForm("Top Secret", 20, 10);
    
    // Intern não deveria conseguir assinar (grade 150 > 20)
    intern.signForm(topSecretForm);
    
    // Manager deve conseguir assinar
    manager.signForm(topSecretForm);
    
    // Tentar assinar um documento já assinado
    boss.signForm(topSecretForm);

    boss.signForm(topSecretForm); // Tentativa de assinar novamente

    manager.signForm(contractForm); // Tentativa de assinar novamente
    
    std::cout << "\n---- End of Tests ----\n" << std::endl;
    
    return 0;
}