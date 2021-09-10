/*

Search a key element in a given set of elements using the methods list below and determine the
time required. Repeat the experiment for different values of n and plot a graph of the time taken
to search a key in different positions versus n(n is the number of elements in the list). The
elements can be read from file or can be generated using the random number generator.

*/

//LINEAR SEARCH

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;

    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}

int linear(int item, int n, int a[])
{
    for (int i = 0; i < n; i++)
    {

        delay(1);
        if (a[i] == item)
            return i + 1;
    }
    return 0;
}
int main()
{
    int a[10000], pos, n, item, i;
    clock_t start, end;
    double time;

    printf("Enter the array size: ");
    scanf("%d", &n);

    printf("\nElements are:\n");
    for (i = 0; i < n; i++)
    {
        a[i] = (int)rand() % 1000;
        printf("%d\t", a[i]);
    }

    printf("\n\nEnter the element to be searched: ");
    scanf("%d", &item);
    start = clock();
    pos = linear(item, n, a);
    end = clock();

    if (pos == 0)
        printf("item not found\n");
    else
        printf("item found at the position %d", pos);

    time = (end - start) / CLK_TCK;
    printf("\nTime taken = %f\n", time);
}