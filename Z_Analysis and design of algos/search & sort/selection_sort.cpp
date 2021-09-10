/*Implement the following Sort algorithms to sort a given set ofelements and determine the time
required to sort the elements. Repeat the experiment fordifferent values of n, the number of
elements in the list to be sorted and plot a graph of thetime taken versus n. The elements can be
read from a file or can be generated using therandom number gene rator.
        Analyze the time efficiency of each of these methods and compare their performances by
        referring the graphs plotted.
SELECTION SORT;
*/

#include <bits/stdc++.h>
#include <time.h>
using namespace std;
void selection_sort(int arr[], int n);
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void delay(int i)
{
    int mili_seconds = 50 * i;
    clock_t start_time = clock();
    while (clock() < start_time + mili_seconds);
}
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
    selection_sort(a, n);
    end = clock();
    cout << "\n\nSorted Array is: ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    double timetaken = (end - start) / CLOCKS_PER_SEC;
    cout << "\n Time taken is " << timetaken << " seconds\n";
    return 0;
}
void selection_sort(int arr[], int n)
{
    int i, j;
    int indexmin;
    for (i = 0; i < n - 1; i++)
    {
        // delay(1);
        indexmin = i;
        for (j = i + 1; j < n; j++)
        {
            // delay(1);
            if (arr[j] < arr[indexmin])
                indexmin = j;
        }
        swap(&arr[indexmin], &arr[i]);
    }
}

// select ename from emp where desig in (select desig from emp where empname = 'Arun')
// select ename from emp where sal in (select sal from emp where max(sal))
// select ename from emp where sal in (select max(sal) from emp);