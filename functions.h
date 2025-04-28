#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <cstdint>

// Функции int32_t
void processIntArray();
int32_t countDistinctInt(int32_t* arr, int32_t n);
int32_t findMinAbsInt(int32_t* arr, int32_t n);
int32_t sumAfterLastZeroInt(int32_t* arr, int32_t n);
void rearrangeIntArray(int32_t* arr, int32_t n);

// Функции double
void processDoubleArray();
int32_t countDistinctDouble(double* arr, int32_t n);
double findMinAbsDouble(double* arr, int32_t n);
double productBeforeMinAbsDouble(double* arr, int32_t n);
void rearrangeDoubleArray(double* arr, int32_t n);

// Общие функции
void fillArrayManually(int32_t* arr, int32_t n);
void fillArrayRandomly(int32_t* arr, int32_t n);
void fillArrayManually(double* arr, int32_t n);
void fillArrayRandomly(double* arr, int32_t n);
void printArray(const int32_t* arr, int32_t n);
void printArray(const double* arr, int32_t n);

#endif
