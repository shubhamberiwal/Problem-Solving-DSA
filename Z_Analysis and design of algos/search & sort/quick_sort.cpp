// Implement Quick Sort to sort a given set of elements and determine the time required to sort the elements.
// Repeat the experiment for different values of n, the number of elements in the list to be sorted and plot a graph of the time taken versus n.
// The elements can be read from a file or can be generated using the random number generator.
// QUICK SORT
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void quick_sort(int arr[], int, int);
int partition(int arr[], int, int);

void delay(int numberOfSeconds) {
    int milliSeconds = 200 * numberOfSeconds;
    clock_t startTime = clock();
    while(clock() < startTime + milliSeconds);
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int main()
{
    int a[1000];
    int n;
    cout << "\nEnter the size of the array: ";
    cin >> n;
    int i;
    cout << "Elements are as follows:\n";
    for (i = 0; i < n; i++)
    {
        a[i] = (int)rand() % 1000;
        cout << a[i]<<"\t";
    }

    clock_t start, end;
    start = clock();
    quick_sort(a, 0, n-1 );
    end = clock();
    cout << "\nSorted Array is:\n";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    printf("\nTime taken = %ld",(end-start)/CLOCKS_PER_SEC);
    return 0;
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    int temp;
    while (i < j)
    {
        while(arr[i]<=pivot)
        {
            i++;
            delay(1);
        }
        while(arr[j]>pivot)
        {
            j--;
            delay(1);
        }
        if(i<j)
        {
            delay(1);
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
}


/*
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1); 
 
    for (int j = low; j <= high - 1; j++)
    {
        delay(1);   
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
*/





/*
        if (pivot < arr[i] && pivot > arr[j])
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        else if (pivot >= arr[i])
        {
            i++;
        }
        else if (pivot < arr[j])
        {
            j--;
        }
    }
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
*/



/*
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int numberOfSeconds) {
    int milliSeconds = 200 * numberOfSeconds;
    clock_t startTime = clock();
    while(clock() < startTime + milliSeconds);
}
int quickSort(int x[], int low, int high){
    int pos;
    if(low<high) {
        pos = partition(x,low,high);
        quickSort(x,low,pos-1);
        quickSort(x,pos+1,high);
    }
    return;
}

int partition(int x[], int low, int high) {
    int key,temp,true=1;
    int left,right;

    key = x[low];
    left = low + 1;
    right = high;

    while(true) {
        while ((left<high) && (key >= x[left])) {
            left++;
            delay(1);
        }
        while(key < x[right]) {
            right--;
            delay(1);
        }
        if(left < right) {
            temp = x[left];
            x[left] = x[right];
            x[right] = temp;
        }
        else {
            temp = x[low];
            x[low] = x[right];
            x[right] = temp;
            return(right);
        }
    }
    return 0;
}
int main() {
    int a[1000],n,i,low,high;
    clock_t start,end;
    float time;

    printf("enter array size ");
    scanf("%d",&n);

    printf("\nelements are \n");

    for(i=0;i<n;i++) {
        a[i] = (int)rand()/1000;
        printf("%d\t",a[i]);
    }
    low = 0;
    high = n-1;

    start = clock();
    quickSort(a,low,high);
    end = clock();

    printf("the sorted list is \n");
    for(i=0;i<n;i++) {
        printf("%d\t",a[i]);
    }
    printf("\ntime taken = %ld",(end-start)/CLOCKS_PER_SEC);
}
*/
