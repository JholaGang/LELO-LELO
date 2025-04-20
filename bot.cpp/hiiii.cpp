#include <iostream>
#include <string>

int main() {
    std::string name;

    // Ask for the user's name
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    // Print a greeting message
    std::cout << "Hello, " << name << "! Welcome to C++ programming." << std::endl;

    return 0;
}