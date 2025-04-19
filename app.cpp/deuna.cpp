#include <iostream>
#include <limits>

void displayMenu() {
    std::cout << "\n===== Calculator Menu =====" << std::endl;
    std::cout << "1. Addition" << std::endl;
    std::cout << "2. Subtraction" << std::endl;
    std::cout << "3. Multiplication" << std::endl;
    std::cout << "4. Division" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << "Enter your choice: ";
}

double performOperation(int choice, double num1, double num2) {
    switch (choice) {
        case 1:
            return num1 + num2;
        case 2:
            return num1 - num2;
        case 3:
            return num1 * num2;
        case 4:
            if (num2 != 0) {
                return num1 / num2;
            } else {
                std::cerr << "Error: Division by zero is not allowed." << std::endl;
                return std::numeric_limits<double>::quiet_NaN();
            }
        default:
            std::cerr << "Invalid operation." << std::endl;
            return 0;
    }
}

int main() {
    int choice;
    double num1, num2, result;

    do {
        displayMenu();
        std::cin >> choice;

        if (choice == 5) {
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            break;
        }

        if (choice < 1 || choice > 5) {
            std::cerr << "Invalid choice. Please try again." << std::endl;
            continue;
        }

        std::cout << "Enter the first number: ";
        std::cin >> num1;

        std::cout << "Enter the second number: ";
        std::cin >> num2;

        result = performOperation(choice, num1, num2);

        if (choice != 4 || num2 != 0) {
            std::cout << "The result is: " << result << std::endl;
        }

    } while (choice != 5);

    return 0;
}