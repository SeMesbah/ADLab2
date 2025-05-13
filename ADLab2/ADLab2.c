#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sorthing.h"
#define _CRT_SECURE_NO_WARNINGS

void copyArray(int source[], int dest[]) {
    for (int i = 0; i < MAX_SIZE; i++) {
        dest[i] = source[i];
    }
}

void printSortingResults(int results[][2], char* algorithmNames[], int numAlgorithms) {
    printf("\n------------------------------------------------------------\n");
    printf("| %-20s | %-12s | %-12s |\n", "Algorithm", "Comparisons", "Swaps");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < numAlgorithms; i++) {
        printf("| %-20s | %-12d | %-12s |\n",
            algorithmNames[i],
            results[i][0],
            (i == 2 || i == 3) ? "N/A" : "N/A"); // MergeSort variants don't use swaps
    }
    printf("------------------------------------------------------------\n");
}

/*
assignment 1
*/

void initArray(int k, int array[]) {

    for (int i = 0;i < MAX_SIZE;i++) {
        array[i] = i + 1;

    }
    if (k >= MAX_SIZE) {
        printf("Error: k (%d) cannot be greater than or equal to MAX_SIZE (%d).\n", k, MAX_SIZE);
        exit(EXIT_FAILURE); // Exit the program with failure status
    }
    srand(time(NULL));
    printf("Array before processing:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    for (int i = 0; i < k; i++) {
        int randomIndex = rand() % (MAX_SIZE - i);
        int chosenElement = array[randomIndex];


        for (int j = randomIndex; j < MAX_SIZE - 1 - i; j++) {
            array[j] = array[j + 1];
        }

        array[MAX_SIZE - 1 - i] = chosenElement;
    }

}

int main() {
    int originalArray[MAX_SIZE];
    int workingArray[MAX_SIZE];
    int k;

    printf("Enter the number of elements to shuffle: ");
    scanf_s("%d", &k);

    // Initialize and shuffle the original array
    initArray(k, originalArray);
    printf("\nShuffled array:\n");
    printArray(originalArray);

    // Create arrays to store results [comparisons, swaps]
    int results[5][2] = { {0} }; // For 5 sorting algorithms
    char* algorithmNames[] = {
        "Insertion Sort",
        "Selection Sort",
        "Merge Sort",
        "MergeSort Bottom-Up",
        "Quick Sort"
    };

    // Test each sorting algorithm
    // 1. Insertion Sort
    copyArray(originalArray, workingArray);
    resetCounters();
    insertionSort(workingArray);
    results[0][0] = comparisons;
    results[0][1] = swaps;

    // 2. Selection Sort
    copyArray(originalArray, workingArray);
    resetCounters();
    selectionSort(workingArray);
    results[1][0] = comparisons;
    results[1][1] = swaps;

    // 3. Merge Sort
    copyArray(originalArray, workingArray);
    resetCounters();
    mergesort(workingArray, 0, MAX_SIZE - 1);
    results[2][0] = comparisons;
    // No swaps count for merge sort

    // 4. Merge Sort Bottom-Up
    copyArray(originalArray, workingArray);
    resetCounters();
    mergesortBU(workingArray, MAX_SIZE);
    results[3][0] = comparisons;
    // No swaps count for bottom-up merge sort

    // 5. Quick Sort
    copyArray(originalArray, workingArray);
    resetCounters();
    quicksort(workingArray, 0, MAX_SIZE - 1);
    results[4][0] = comparisons;
    results[4][1] = swaps;

    // Print results table
    printSortingResults(results, algorithmNames, 5);

    return 0;
}