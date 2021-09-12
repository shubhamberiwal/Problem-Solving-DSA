/*Implement the following Sort algorithms to sort a given set ofelements and determine the time
required to sort the elements. Repeat the experiment fordifferent values of n, the number of
elements in the list to be sorted and plot a graph of thetime taken versus n. The elements can be
read from a file or can be generated using therandom number gene rator.
        Analyze the time efficiency of each of these methods and compare their performances by
        referring the graphs plotted.
INSERTION SORT;
*/


#include <bits/stdc++.h>
#include <time.h>
using namespace std;
void delay(int i)
{
    int mili_seconds = 100 * i;
    clock_t delay_time = clock();
    while (clock() < mili_seconds + delay_time)
        ;
}

void insertion_sort(int arr[], int n);

int main()
{
    int n, i;
    int a[100];
    clock_t start, end;
    cout << "\nEnter the size of the array: ";
    cin >> n;
    cout << "\nArray elements are: ";
    for (i = 0; i < n; i++)
    {
        a[i] = (int)rand() % 1000;
        cout << a[i] << "\t";
    }
    start = clock();
    insertion_sort(a, n);
    end = clock();
    cout << "\n\nSorted Array is: ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    double timetaken = (end - start) / CLOCKS_PER_SEC;
    cout << "\nTime taken is " << timetaken << " seconds\n";
    return 0;
}

void insertion_sort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        // delay(1);
        key = arr[i];
        for (j = i - 1; j >= 0 && key < arr[j]; j--)
        {
            // delay(1);
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}


// void insertion_sort(int arr[], int n)
// {
//     int i, key, j;
//     for (i = 1; i < n; i++)
//     {
//         key = arr[i];
//         j = i - 1;
 
//         /* Move elements of arr[0..i-1], that are
//         greater than key, to one position ahead
//         of their current position */
//         while (j >= 0 && arr[j] > key)
//         {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }
// }

