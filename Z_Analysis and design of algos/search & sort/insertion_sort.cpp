

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
