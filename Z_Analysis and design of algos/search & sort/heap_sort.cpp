/*
Implement Heap Sort
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 1000

int temp;

void delay(unsigned int mseconds)
{
  clock_t goal = mseconds + clock();
  while (goal > clock())
    ;
}

void swap_largest(int arr[], int n, int i)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && arr[left] > arr[largest])
    largest = left;
  if (right < n && arr[right] > arr[largest])
    largest = right;
  if (largest != i)
  {
    temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    swap_largest(arr, n, largest);
  }
}
void swap_largest2(int arr[], int n, int i)
{
  delay(100);
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && arr[left] > arr[largest])
    largest = left;
  if (right < n && arr[right] > arr[largest])
    largest = right;
  if (largest != i)
  {
    temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    swap_largest2(arr, n, largest);
  }
}
void heap(int arr[], int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
    swap_largest(arr, n, i);
  for (int i = n - 1; i >= 0; i--)
  {
    delay(100);
    temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    swap_largest2(arr, i, 0);
  }
}
void print(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
}
int main()
{
  int arr[200000], n, i;
  clock_t start, end;
  double time;
  printf("Enter the array size:");
  scanf("%d", &n);
  printf("\nElements are:\n");
  for (int i = 0; i < n; i++)
  {
    arr[i] = rand() % MAX;
    for (int j = 0; j <= (i - 1); ++j)
    {
      if (arr[i] != arr[j])
      {
        continue;
      }
      else
      {
        arr[i] = rand() % MAX;
        printf("%d ", arr[i]);
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  start = clock();
  heap(arr, n);
  end = clock();
  printf("\nSorted array: \n");
  print(arr, n);
  time = (double)(end - start) / CLOCKS_PER_SEC;
  printf("\n Time taken by heap sort = %lf\n", time);
}