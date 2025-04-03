#include "header.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include <cmath>

void InputSize(int32_t& size) {
    std::cout << "Input size: ";
    if (!(std::cin >> size) || size <= 0) {
        throw std::invalid_argument("Size must be a positive integer");
    }
}

// Функции для int32_t
void CreateArray(int32_t*& array, int32_t size) {
    if (size <= 0) {
        throw std::invalid_argument("Size must be positive");
    }
    array = new int32_t[size]();
}

void FillArray(int32_t* array, int32_t size) {
    if (!array || size <= 0) {
        throw std::invalid_argument("Invalid array or size");
    }
    
    for (int32_t i = 0; i < size; ++i) {
        std::cout << "Enter element " << i+1 << ": ";
        if (!(std::cin >> array[i])) {
            throw std::invalid_argument("Invalid input for array element");
        }
    }
}

void FillArrayRandom(int32_t* array, int32_t size) {
    if (!array || size <= 0) {
        throw std::invalid_argument("Array is nullptr or size is invalid");
    }
    
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int32_t> dis(-50, 50);
    
    for (int32_t i = 0; i < size; ++i) {
        array[i] = dis(gen);
    }
}

int32_t MinFabsElement(const int32_t* array, int32_t size) {
    if (!array || size <= 0) {
        throw std::invalid_argument("Invalid array");
    }
    
    int32_t minIndex = 0;
    for (int32_t i = 1; i < size; ++i) {
        if (std::abs(array[i]) < std::abs(array[minIndex])) {
            minIndex = i;
        }
    }
    return array[minIndex];
}

bool SumBetweenZeros(const int32_t* arr, int32_t size, int32_t& result) {
    result = 0;
    if (!arr || size <= 0) {
        throw std::invalid_argument("Invalid array");
    }
    
    int firstZero = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            firstZero = i;
            break;
        }
    }
    
    if (firstZero == -1) return false;
    
    int lastZero = -1;
    for (int i = size - 1; i > firstZero; i--) {
        if (arr[i] == 0) {
            lastZero = i;
            break;
        }
    }

    if (lastZero == -1) return false;

    for (int i = firstZero + 1; i < lastZero; i++) {
        result += arr[i];
    }
    return true;
}

void EvenSortArray(int32_t* array, int32_t size) {
    if (!array || size <= 1) return;
    
    int32_t* temp = new int32_t[size];
    int evenIndex = 0;
    int oddIndex = (size % 2 == 0) ? size/2 : size/2 + 1;

    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) { 
            temp[evenIndex++] = array[i];
        } else {
            temp[oddIndex++] = array[i];
        }
    }

    std::copy(temp, temp + size, array);
    delete[] temp;
}

void PrintArray(const int32_t* array, int32_t size) {
    if (!array || size <= 0) {
        throw std::invalid_argument("Array is nullptr or size is invalid");
    }
    
    std::cout << "Array: ";
    for (int32_t i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void DeleteArray(int32_t*& array) {
    delete[] array;
    array = nullptr;
}

// Функции для double
void CreateArray(double*& array, int32_t size) {
    if (size <= 0) {
        throw std::invalid_argument("Size must be positive");
    }
    array = new double[size]();
}

void FillArray(double* array, int32_t size) {
    if (!array || size <= 0) {
        throw std::invalid_argument("Invalid array or size");
    }
    
    for (int32_t i = 0; i < size; ++i) {
        std::cout << "Enter element " << i+1 << ": ";
        if (!(std::cin >> array[i])) {
            throw std::invalid_argument("Invalid input for array element");
        }
    }
}

void FillArrayRandom(double* array, int32_t size) {
    if (!array || size <= 0) {
        throw std::invalid_argument("Array is nullptr or size is invalid");
    }
    
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(-10.0, 10.0);
    
    for (int32_t i = 0; i < size; ++i) {
        array[i] = dis(gen);
    }
}

int32_t CountUniqueElements(const int32_t* array, int32_t size) {
    if (!array || size <= 0) {
        throw std::invalid_argument("Invalid array");
    }

    int32_t uniqueCount = 0;

    for (int32_t i = 0; i < size; ++i) {
        bool isUnique = true;
        for (int32_t j = 0; j < i; ++j) {
            if (array[i] == array[j]) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            uniqueCount++;
        }
    }

    return uniqueCount;
}

double ProductBeforeMinAbs(const double* array, int32_t size) {
    if (!array || size <= 0) {
        throw std::invalid_argument("Invalid array");
    }
    
    int32_t minIndex = 0;
    for (int32_t i = 1; i < size; ++i) {
        if (std::abs(array[i]) < std::abs(array[minIndex])) {
            minIndex = i;
        }
    }
    
    if (minIndex == 0) return 0.0;
    
    double product = 1.0;
    for (int32_t i = 0; i < minIndex; ++i) {
        product *= array[i];
    }
    return product;
}

void RearrangeArray(double* array, int32_t size) {
    if (!array || size <= 1) {
        throw std::invalid_argument("Invalid array");
    }
    
    double* temp = new double[size];
    int32_t negCount = 0;
    int32_t zeroCount = 0;
    int32_t posCount = 0;
    
    // Сначала подсчитываем количество каждого типа элементов
    for (int32_t i = 0; i < size; ++i) {
        if (array[i] < 0) negCount++;
        else if (array[i] == 0) zeroCount++;
        else posCount++;
    }
    
    // Устанавливаем границы для каждого раздела
    int32_t negIndex = 0;
    int32_t zeroIndex = negCount;
    int32_t posIndex = negCount + zeroCount;
    
    // Распределяем элементы по соответствующим разделам
    for (int32_t i = 0; i < size; ++i) {
        if (array[i] < 0) {
            temp[negIndex++] = array[i];
        }
        else if (array[i] == 0) {
            temp[zeroIndex++] = array[i];
        }
        else {
            temp[posIndex++] = array[i];
        }
    }
    
    std::copy(temp, temp + size, array);
    delete[] temp;
}

void PrintArray(const double* array, int32_t size) {
    if (!array || size <= 0) {
        throw std::invalid_argument("Array is nullptr or size is invalid");
    }
    
    std::cout << "Array: ";
    for (int32_t i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void DeleteArray(double*& array) {
    delete[] array;
    array = nullptr;
}