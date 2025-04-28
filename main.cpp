#include <iostream>
#include "functions.cpp"


int main() {
    int32_t dataTypeChoice;
    std::cout << "Choose array type:\n1. int32_t\n2. double\n";
    std::cin >> dataTypeChoice;

    switch(dataTypeChoice) {
        case 1:
            processIntArray();
            break;
        case 2:
            processDoubleArray();
            break;
        default:
            std::cout << "Invalid choice\n";
            return;
    }

    return 0;
}
