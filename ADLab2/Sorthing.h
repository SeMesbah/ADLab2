#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20
#define TRUE 1
#define FALSE 0

int comparisons;
int swaps;

void printArray(int array[]);
int isSorted(int array[]);
int compare(int i, int j);
void swap(int array[], int i, int j);
void resetCounters();
void printCounters(const char* algorithmName);

void insertionSort(int array[]);
void selectionSort(int array[]);

void initArray(int k, int array[]);
int minimum(int x, int y);

void merge(int array[], int l, int m, int r);
void mergesort(int array[], int l, int r);

void mergesortBU(int array[], int arraySize);
void mergeBU(int array[], int l, int m, int r);

void quicksort(int array[], int l, int r);
int partition(int array[], int l, int r);

// Helper functions
int getInt();
void copyArray(int source[], int dest[]);
void printSortingResults(int results[][2], char* algorithmNames[], int numAlgorithms);