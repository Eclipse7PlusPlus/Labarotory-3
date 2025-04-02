#include "header.h"
#include "functions.cpp"
#include <iostream>
#include <memory>

template <typename T>
void ProcessArray(int fillChoice, int32_t size) {
    T* array = nullptr;
    try {
        CreateArray(array, size);
        
        switch (fillChoice) {
            case 1:
                FillArray(array, size);
                break;
            case 2:
                FillArrayRandom(array, size);
                break;
            default:
                throw std::invalid_argument("Invalid filling method");
        }

        std::cout << "\nOriginal array: ";
        PrintArray(array, size);

        if constexpr (std::is_same_v<T, int32_t>) {
            std::cout << "Min absolute element: " << MinFabsElement(array, size) << std::endl;
            
            int32_t sum;
            if (SumBetweenZeros(array, size, sum)) {
                std::cout << "Sum between zeros: " << sum << std::endl;
            } else {
                std::cout << "No two zeros found" << std::endl;
            }
            
            EvenSortArray(array, size);
            std::cout << "After even-odd sort: ";
            PrintArray(array, size);
        }
        else {
            std::cout << "Count of unique elements: " << CountUniqueElements(array, size) << std::endl;
            
            double product = ProductBeforeMinAbs(array, size);
            std::cout << "Product before min absolute element: " << product << std::endl;
            
            RearrangeArray(array, size);
            std::cout << "After rearrangement (negatives, zeros, positives): ";
            PrintArray(array, size);
        }
    }
    catch (...) {
        DeleteArray(array);
        throw;
    }
    DeleteArray(array);
}

int main() {
    try {
        int32_t size;
        InputSize(size);

        // Выбор способа заполнения
        std::cout << "Select filling method:\n1 - Manual input\n2 - Random fill\n";
        int fillChoice;
        if (!(std::cin >> fillChoice) || (fillChoice != 1 && fillChoice != 2)) {
            throw std::invalid_argument("Invalid filling method choice");
        }

        // Выбор типа массива
        std::cout << "Select array type:\n1 - int32_t\n2 - double\n";
        int typeChoice;
        if (!(std::cin >> typeChoice) || (typeChoice != 1 && typeChoice != 2)) {
            throw std::invalid_argument("Invalid array type choice");
        }

        switch (typeChoice) {
            case 1:
                ProcessArray<int32_t>(fillChoice, size);
                break;
            case 2:
                ProcessArray<double>(fillChoice, size);
                break;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}