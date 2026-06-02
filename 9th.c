//Design and implement C/C++ Program to sort a given set of n integer elements using Selection Sort method and compute its time complexity. 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(long int *a, long int *b)
{
    long int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionsort(long int arr[], long int n)
{
    long int i, j, midx;

    for(i = 0; i < n - 1; i++)
    {
        midx = i;

        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[midx])
                midx = j;
        }

        swap(&arr[midx], &arr[i]);
    }
}

void main()
{
    long int n = 1000;
    int it = 0;
    double tim1[10];

    printf("Input Size, Selection Sorting Time\n");

    while(it++ < 5)
    {
        long int a[n];

        for(int i = 0; i < n; i++)
        {
            long int no = rand() % n + 1;
            a[i] = no;
        }

        clock_t start, end;

        start = clock();
        selectionsort(a, n);
        end = clock();

        tim1[it] = (double)(end - start) / 1000;

        printf("%ld = %ld ms\n", n, (long int)tim1[it]);

        n += 1000;
    }
}
