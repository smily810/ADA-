//Design and implement C/C++ Program to sort a given set of n integer elements using Quick Sort method and compute its time complexity. 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int max = 5000;

static int partition(long int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high + 1;

    while(i <= j)
    {
        do
        {
            i++;
        } while(pivot >= arr[i] && i <= high);

        do
        {
            j--;
        } while(pivot < arr[j]);

        if(i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

static void qs(long int arr[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = partition(arr, low, high);

        qs(arr, low, mid - 1);
        qs(arr, mid + 1, high);
    }
}

void main()
{
    int n, i;
    long int a[5000], no;
    double tm;

    clock_t start, end;

    printf("\nEnter the number of elements:\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        no = rand() % n + 1;
        a[i] = no;
    }

    start = clock();
    qs(a, 0, n - 1);
    end = clock();

    tm = (double)(end - start);

    printf("%d = %lf Nano Seconds\n", n, tm);
}
