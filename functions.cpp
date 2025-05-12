
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

// ================ Общие функции ================

void fillArrayManually(int32_t* arr, int32_t n) {
    for (int32_t i = 0; i < n; i++) {
        std::cout << "Enter element " << i << ": ";
        std::cin >> arr[i];
    }
}

void fillArrayRandomly(int32_t* arr, int32_t n) {
    std::srand(std::time(nullptr));
    for (int32_t i = 0; i < n; i++) {
        arr[i] = std::rand() % 100 - 50; 
    }
}

void fillArrayManually(double* arr, int32_t n) {
    for (int32_t i = 0; i < n; i++) {
        std::cout << "Enter element " << i << ": ";
        std::cin >> arr[i];
    }
}

void fillArrayRandomly(double* arr, int32_t n) {
    std::srand(std::time(nullptr));
    for (int32_t i = 0; i < n; i++) {
        arr[i] = (std::rand() % 200 - 100) / 2.0; 
    }
}

void printArray(const int32_t* arr, int32_t n) {
    for (int32_t i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void printArray(const double* arr, int32_t n) {
    for (int32_t i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// ================ Функции для int32_t ================

int32_t countDistinctInt(int32_t* arr, int32_t size) {
    int32_t count = 0;
    for (int32_t i = 0; i < size; i++) {
        bool isUnique = true;
        for (int32_t j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) 
        count++;
    }
    return count;
}

int32_t findMinAbsInt(int32_t* arr, int32_t n) {
    int32_t min = std::abs(arr[0]);
    for (int32_t i = 1; i < n; i++) {
        int32_t abs_val = std::abs(arr[i]);
        if (abs_val < min) 
        min = abs_val;
    }
    return min;
}

int32_t sumAfterLastZeroInt(int32_t* arr, int32_t n) {
    int32_t last_zero_index = -1;
    for (int32_t i = 0; i < n; i++) {
        if (arr[i] == 0) last_zero_index = i;
    }
    
    if (last_zero_index == -1 || last_zero_index == n - 1) {
        return 0;
    }
    
    int32_t sum = 0;
    for (int32_t i = last_zero_index + 1; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

void rearrangeIntArray(int32_t* arr, int32_t size) {
    int32_t* temp = new int32_t[size];
    int32_t index {};
    
    
    for (int32_t i = 0; i < size; i += 2) {
        temp[index++] = arr[i];
    }
    
   
    for (int32_t i = 1; i < size; i += 2) {
        temp[index++] = arr[i];
    }
    
    
    for (int32_t i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
    
    delete[] temp;
}

void processIntArray() {
    int32_t n;
    std::cout << "Enter array size: ";
    std::cin >> n;

    int32_t* arr = new int32_t[n];

    int32_t choice;
    std::cout << "1. Fill manually\n2. Fill randomly\n";
    std::cin >> choice;

    switch(choice) {
        case 1: fillArrayManually(arr, n); break;
        case 2: fillArrayRandomly(arr, n); break;
        default: 
            std::cout << "Invalid choice\n";
            delete[] arr;
            return;
    }

    std::cout << "Array: ";
    printArray(arr, n);

    std::cout << "1. Min absolute value: " << findMinAbsInt(arr, n) << "\n";
    std::cout << "2. Sum after last zero: " << sumAfterLastZeroInt(arr, n) << "\n";

    rearrangeIntArray(arr, n);
    std::cout << "Rearranged array: ";
    printArray(arr, n);

    delete[] arr;
}

// ================ Функции для double ================

int32_t countDistinctDouble(double* arr, int32_t n) {
    int32_t count = 0;
    for (int32_t i = 0; i < n; i++) {
        bool isUnique = true;
        for (int32_t j = 0; j < i; j++) {
            if (std::abs(arr[i] - arr[j]) < 1e-9) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) count++;
    }
    return count;
}

double findMinAbsDouble(double* arr, int32_t n) {
    double min = std::abs(arr[0]);
    for (int32_t i = 1; i < n; i++) {
        double abs_val = std::abs(arr[i]);
        if (abs_val < min) min = abs_val;
    }
    return min;
}

double productBeforeMinAbsDouble(double* arr, int32_t n) {
    int32_t min_index = 0;
    double min_abs = std::abs(arr[0]);
    
    for (int32_t i = 1; i < n; i++) {
        double abs_val = std::abs(arr[i]);
        if (abs_val < min_abs) {
            min_abs = abs_val;
            min_index = i;
        }
    }
    
    if (min_index == 0) 
    return 0;
    
    double product = 1.0;
    for (int32_t i = 0; i < min_index; i++) {
        product *= arr[i];
    }
    return product;
}

void rearrangeDoubleArray(double* arr, int32_t n) {
    double* temp = new double[n];
    int32_t index = 0;
    
    
    for (int32_t i = 0; i < n; i++) {
        if (arr[i] < 0) temp[index++] = arr[i];
    }
    
    
    for (int32_t i = 0; i < n; i++) {
        if (arr[i] == 0) temp[index++] = arr[i];
    }
    
    
    for (int32_t i = 0; i < n; i++) {
        if (arr[i] > 0) temp[index++] = arr[i];
    }
    
    
    for (int32_t i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
    
    delete[] temp;
}

void processDoubleArray() {
    int32_t n;
    std::cout << "Enter array size: ";
    std::cin >> n;

    double* arr = new double[n];

    int32_t choice;
    std::cout << "1. Fill manually\n2. Fill randomly\n";
    std::cin >> choice;

    switch(choice) {
        case 1: fillArrayManually(arr, n); break;
        case 2: fillArrayRandomly(arr, n); break;
        default: 
            std::cout << "Invalid choice\n";
            delete[] arr;
            return;
    }

    std::cout << "Array: ";
    printArray(arr, n);

    std::cout << "1. Number of distinct elements: " << countDistinctDouble(arr, n) << "\n";
    std::cout << "2. Product before min absolute value: " << productBeforeMinAbsDouble(arr, n) << "\n";

    rearrangeDoubleArray(arr, n);
    std::cout << "Rearranged array: ";
    printArray(arr, n);

    delete[] arr;
}
