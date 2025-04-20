#include <iostream>
#include <cmath>

void displayMenu() {
    std::cout << "Scientific Calculator Menu:\n";
    std::cout << "1. Addition (+)\n";
    std::cout << "2. Subtraction (-)\n";
    std::cout << "3. Multiplication (*)\n";
    std::cout << "4. Division (/)\n";
    std::cout << "5. Power (x^y)\n";
    std::cout << "6. Square Root (√x)\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    int choice;
    double num1, num2;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: // Addition
                std::cout << "Enter two numbers: ";
                std::cin >> num1 >> num2;
                std::cout << "Result: " << num1 + num2 << std::endl;
                break;

            case 2: // Subtraction
                std::cout << "Enter two numbers: ";
                std::cin >> num1 >> num2;
                std::cout << "Result: " << num1 - num2 << std::endl;
                break;

            case 3: // Multiplication
                std::cout << "Enter two numbers: ";
                std::cin >> num1 >> num2;
                std::cout << "Result: " << num1 * num2 << std::endl;
                break;

            case 4: // Division
                std::cout << "Enter two numbers: ";
                std::cin >> num1 >> num2;
                if (num2 != 0) {
                    std::cout << "Result: " << num1 / num2 << std::endl;
                } else {
                    std::cout << "Error: Division by zero is not allowed.\n";
                }
                break;

            case 5: // Power
                std::cout << "Enter base and exponent: ";
                std::cin >> num1 >> num2;
                std::cout << "Result: " << pow(num1, num2) << std::endl;
                break;

            case 6: // Square Root
                std::cout << "Enter a number: ";
                std::cin >> num1;
                if (num1 >= 0) {
                    std::cout << "Result: " << sqrt(num1) << std::endl;
                } else {
                    std::cout << "Error: Square root of a negative number is not defined.\n";
                }
                break;

            case 7: // Exit
                std::cout << "Exiting the calculator. Goodbye!\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

        std::cout << std::endl;

    } while (choice != 7);

    return 0;
}