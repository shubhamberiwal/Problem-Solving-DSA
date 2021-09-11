/*
Search a key element in a given set of elements using the methods list below and determine the
time required. Repeat the experiment for different values of n and plot a graph of the time taken
to search a key in different positions versus n(n is the number of elements in the list). The
elements can be read from file or can be generated using the random number generator.

Interpolation Search

Analyze the time efficiency of each of these methods and compare their performances by
referring the graphs plotted.
*/
#include<bits/stdc++.h>
using namespace std;


void delay(int number_of_seconds)
{
    int milli_seconds = 200 * number_of_seconds;

    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}

int interpolationSearch(int arr[], int n, int x)
{
    int lo = 0, hi = (n - 1);
    
    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        delay(10);
        if (lo == hi)
        {
            if (arr[lo] == x) return lo;
            return -1;
        }
        int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
        
        if (arr[pos] == x)
            return pos;

        if (arr[pos] < x)
            lo = pos + 1;
        else
            hi = pos - 1;
    }
    return -1;
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
    pos = interpolationSearch(a, n, item);
    end = clock();

    if (pos == -1)
        printf("Item not found\n");
    else
        printf("Item found at the position %d\n", pos);

    time = (end - start) / CLK_TCK;
    printf("\nTime taken = %f seconds\n", time);
}



// // Driver Code
// int main()
// {
//     // Array of items on which search will
//     // be conducted.
//     int arr[] = {10, 12, 13, 16, 18, 19, 20, 21,
//                  22, 23, 24, 33, 35, 42, 47};
//     int n = sizeof(arr)/sizeof(arr[0]);
 
//     int x = 18; // Element to be searched
//     int index = interpolationSearch(arr, n, x);
 
//     // If element was found
//     if (index != -1)
//         cout << "Element found at index " << index;
//     else
//         cout << "Element not found.";
//     return 0;
// }
