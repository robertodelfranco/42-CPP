#include "Bureaucrat.hpp"

int main() {
    Bureaucrat b1;
    std::cout << b1 << std::endl;

    Bureaucrat b2("Alice", 42);
    std::cout << b2 << std::endl;

    Bureaucrat b3(b2);
    std::cout << b3 << std::endl;

    Bureaucrat b4;
    b4 = b2;
    std::cout << b4 << std::endl;

    std::cout << std::endl;
    std::cout << "---- Testing Exceptions ----" << std::endl;
    std::cout << std::endl;
    
    try {
        Bureaucrat b5("Bob", 0);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    try {
        Bureaucrat b6("Charlie", 151);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    
    try {
        b2.incrementGrade();
        std::cout << b2 << std::endl;
        for (int i = 0; i < 42; ++i) {
            b2.incrementGrade();
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    try {
        b4.decrementGrade();
        std::cout << b4 << std::endl;
        for (int i = 0; i < 110; ++i) {
            b4.decrementGrade();
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    
    return 0;
}
