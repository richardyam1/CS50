/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    
    int start = 0;
    int end = n - 1;
    
    while (end >= start)
    {
        
        int middle = (start + end)/2;
        
        if (values[middle] == value)
        {
            return true;
        }
        
        else if (values[middle] > value)
        {
            end = middle - 1;
        }
        
        else if (values[middle] < value)
        {
            start = middle + 1;
        }
        
    }
    return false;    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    
    // TODO: implement an O(n^2) sorting algorithm
    for (int i = 1; i < n-1; i++)
    {
        int to_sort = values[i];
        int j = i;
        //Goes through sorted portion from right to left
        while (j > 0 && values[j - 1] > to_sort)
        {
            values[j] = values[j-1];
            j = j-1;
        } 
        
        //Inserts element into sorted list
        values[j] = to_sort;
        
    }
    
   
    
}