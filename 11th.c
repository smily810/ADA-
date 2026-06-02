// Design and implement C/C++ Program to sort a given set of n integer elements using Merge Sort method and compute its time complexity. 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define max 5000

int array[max];

void merge(int low, int mid, int high)
{
    int temp[max];
    int i = low;
    int j = mid + 1;
    int k = low;

    while((i <= mid) && (j <= high))
    {
        if(array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while(i <= mid)
        temp[k++] = array[i++];

    while(j <= high)
        temp[k++] = array[j++];

    for(i = low; i <= high; i++)
        array[i] = temp[i];
}

void merge_sort(int low, int high)
{
    int mid;

    if(low != high)
    {
        mid = (low + high) / 2;

        merge_sort(low, mid);
        merge_sort(mid + 1, high);

        merge(low, mid, high);
    }
}

void main()
{
    int i, n, no;
    double tm;
    clock_t start, end;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        no = rand() % n + 1;
        array[i] = no;
    }

    printf("Unsorted list is:\n");
    for(i = 0; i < n; i++)
        printf("%d ", array[i]);

    start = clock();

    merge_sort(0, n - 1);

    printf("\nSorted list is:\n");
    for(i = 0; i < n; i++)
        printf("%d ", array[i]);

    printf("\n");

    end = clock();

    tm = (double)(end - start);

    printf("%d = %lf Nano Seconds\n", n, tm);
    printf("\n");
}
