
/* Implement the following Sort algorithms to sort a given set ofelements and determine the time
required to sort the elements. Repeat the experiment fordifferent values of n, the number of
elements in the list to be sorted and plot a graph of thetime taken versus n. The elements can be
read from a file or can be generated using therandom number gene rator.

Merge Sort

Analyze the time efficiency of each of these methods and compare their performances by
referring the graphs plotted.
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;


void delay(int numberOfSeconds) {
    int milliSeconds = 150 * numberOfSeconds;
    clock_t startTime = clock();
    while(clock() < startTime + milliSeconds);
}

void merge_sort(int arr[],int , int);
void merge(int arr[], int , int, int);
int main()
{
    
    int a[1000],n;
    clock_t start, end;
    double time;

    cout << "Enter the array size: ";
    cin >> n;

    cout << "Elements are:\n";
    for (int i = 0; i < n; i++)
    {
        a[i] = (int)rand() % 1000;
        cout << a[i]<<"\t";
    }

    start = clock();
    merge_sort(a, 0, n);
    cout << "\nSorted array is \n";
    for(int i = 0; i < n ; i++){
        cout << a[i] << "\t";
    }
    end = clock();

    time = (end-start)/CLK_TCK;
    cout<<"\nTime take = "<<time<<" seconds"<<endl;

	return 0;
}

void merge_sort(int arr[], int l, int u)
{

    if (l >= u)
    {
        return;
    }
    int mid = (l + u) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, u);
    merge(arr, l, mid, u);
}
void merge(int arr[], int l, int m, int u)
{
    int n1 = m - l + 1;
    int n2 = u - m;
    int a[n1];
    int r[n2];
    int i , j;
    for (i = 0; i < n1; i++)
    {
        a[i] = arr[l+i];
    }
    for (i = 0; i < n2; i++)
    {
        r[i] = arr[m+1+i];
    }
    i = j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        delay(1);
        if (a[i] <= r[j])
        {
            arr[k] = a[i];
            i++;
        }
        else
        {
            arr[k] = r[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        delay(1);
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        delay(1);
        arr[k] = r[j];
        k++;
        j++;
    }
}








// #include<stdio.h>
// #include<stdlib.h>
// #include<time.h>

// void delay(int numberOfSeconds) {
//     int milliSeconds = 200 * numberOfSeconds;
//     clock_t startTime = clock();
//     while(clock() < startTime + milliSeconds);
// }
// void merge(int b[1000],int c[1000],int a[1000],int p,int q) {
//     int i=0,j=0,k=0;

//     while(i<p && j<q) {
//         if(b[i]<c[j]) {
//             a[k] = b[i];
//             i++;
//         }else {
//             a[k] = c[j];
//             j++;
//         }
//         k++;
//         delay(1);
//     }
//     while(i<p) {
//         a[k] = b[i];
//         i++;
//         k++;
//         delay(1);
//     }
//     while(j<q) {
//         a[k] = c[j];
//         j++;
//         k++;
//         delay(1);
//     }
// }
// void MergeSort(int a[1000], int n) {
//     int b[1000], c[1000], i,j,p,q;

//     if(n>1) {
//         for(i=0;i<n/2;i++) {
//             b[i] = a[i];
//         }p=i;
//         for(i=n/2,j=0;i<n;i++,j++) {
//             c[j] = a[i];
//         }q=j;
//         MergeSort(b,q);
//         MergeSort(c,q);
//         merge(b,c,a,p,q);
//     }
//     return;
// }

// int main() {
//     int a[1000], n,i;
//     clock_t start, end;
//     double t;

//     printf("\nEnter the size of the array: ");
//     scanf("%d",&n);

//     printf("The elements are:\n");
//     for(i=0;i<n;i++) {
//         a[i]=(int)rand()/1000;
//         printf("%d\t",a[i]);
//     }
//     start = clock();
//     MergeSort(a,n);
//     end = clock();

//     printf("\nSorted list is:\n");
//     for(i=0;i<n;i++) {
//         printf("%d\t",a[i]);
//     }
//     printf("\nTime taken = %ld", (end-start)/CLOCKS_PER_SEC);

// }