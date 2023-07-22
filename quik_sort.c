#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
 * This is a function to sort an
 * 'array' of 'n' elements using
 * QuickSort algorithm.
 */
void quickSort(int ,int);
/*
 * The main function that implements
 * QuickSort()
 */
int main()
{
int n, i, a[10000], t; //n is the size of  the  input  list
clock_t start, end; //for calculating time
printf("Enter the number of elements: ");
scanf("%d", &n);
//printf("Enter the elements:\n");
for (i = 0; i < n; ++i)
scanf("%d", &a[n]);
start = clock();
quickSort(0, n - 1);
end = clock();
t = (double)(end - start) / CLOCKS_PER_SEC; //in seconds
printf("\nTime taken by QuickSort(): %lf\n", t);
return 0;
}
/*  The following function implements  QuickSort()  */
void quickSort(int low, int high)
{
int pivot, i, j;
 /* pi is partitioning index, arr[p] is now  at  right place */
if (low < high)
{
pivot = partition(low, high); // pi is now at right place
quickSort(low, pivot - 1);  // sort elements before pivot
quickSort(pivot + 1, high); // sort elements after pivot
}
}
