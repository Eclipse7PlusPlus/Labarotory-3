#ifndef HEADER_H
#define HEADER_H

#include <stdexcept>
#include <cstdint>

void InputSize(int32_t& size);

// Для int32_t
void CreateArray(int32_t*& array, int32_t size);
void FillArray(int32_t* array, int32_t size);
void FillArrayRandom(int32_t* array, int32_t size);
int32_t MinFabsElement(int32_t* array, int32_t size);
bool SumBetweenZeros(int32_t* arr, int32_t size, int32_t& result);
void EvenSortArray(int32_t* array, int32_t size);
void PrintArray(int32_t* array, int32_t size);
void DeleteArray(int32_t*& array);

// Для double
void CreateArray(double*& array, int32_t size);
void FillArray(double* array, int32_t size);
void FillArrayRandom(double* array, int32_t size);
int32_t CountUniqueElements(double* array, int32_t size);
double ProductBeforeMinAbs(double* array, int32_t size);
void RearrangeArray(double* array, int32_t size);
void PrintArray(double* array, int32_t size);
void DeleteArray(double*& array);

#endif