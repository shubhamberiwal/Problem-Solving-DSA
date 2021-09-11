/*Search a key element in a given set of elements using the methods list below and determine the
time required. Repeat the experiment for different values of n and plot a graph of the time taken
to search a key in different positions versus n(n is the number of elements in the list). The
elements can be read from file or can be generated using the random number generator.*/

//BINARY SEARCH

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void delay(int number_of_seconds)
{
    int milli_seconds = 200 * number_of_seconds;

    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}

int binary(int item, int a[], int low, int high)
{
    int mid;
    mid = (low + high) / 2;

    delay(10);

    if (low > high)
        return 0;
    if (a[mid] == item)
        return mid + 1;
    else if (a[mid] > item)
        return binary(item, a, low, mid - 1);
    else
        return binary(item, a, mid + 1, high);
}

void sort(int a[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

int main()
{
    int a[10000], n, pos, item;
    clock_t start, end;
    double time;

    printf("Enter the array size: ");
    scanf("%d", &n);

    printf("Elements are:\n");
    for (int i = 0; i < n; i++)
    {
        a[i] = (int)rand() % 1000;
        printf("%d\t", a[i]);
    }

    sort(a, n);
    printf("\nSorted list:\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\nEnter the key element: ");
    scanf("%d", &item);
    start = clock();
    pos = binary(item, a, 0, n - 1);
    end = clock();

    if (pos == 0)
        printf("Item not found\n");
    else
        printf("Item found at the position %d\n", pos);

    time = (end - start) / CLK_TCK;
    printf("\nTime taken = %f\n", time);
}