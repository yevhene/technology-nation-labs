/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

void swap(int values[], int i, int j);
int findMinIndex(int values[], int fromIndex, int toIndex);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int fromIndex = 0;
    int toIndex = n - 1;

    while (toIndex != fromIndex)
    {
        int index = (fromIndex + toIndex) / 2;

        if (values[index] > value)
        {
            toIndex = index - 1;
        }
        else if (values[index] < value)
        {
            fromIndex = index + 1;
        }
        else
        {
            return true;
        }
    }
    
    return (value == values[fromIndex]);
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for (int i = 0; i < n; i++)
    {
        swap(values, i, findMinIndex(values, i, n - 1));
    }

    return;
}

void swap(int values[], int i, int j)
{
    int temp = values[i];
    values[i] = values[j];
    values[j] = temp;
}

int findMinIndex(int values[], int fromIndex, int toIndex)
{
    int minIndex = fromIndex;

    for (int i = fromIndex + 1; i <= toIndex; i++)
    {
        if (values[i] < values[minIndex])
        {
            minIndex = i;
        }
    }
    
    return minIndex;
}
