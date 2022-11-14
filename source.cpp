#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10


int arr[SIZE];

void Merge(int arr[], int left, int right, int mid)
{
    int i, j, k, b[SIZE];
    i = left;
    k = left;
    j = mid + 1;
    while (i <= mid && j < right) {
        if (arr[i] < arr[j]) {
            b[k++] = arr[i++];
        }
        else  {
            b[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        b[k++] = arr[i++];
    }
    while (j < right) {
        b[k++] = arr[j++];
    }
    for (i = left; i < k; i++)  {
        arr[i] = b[i];
    }
}

void MergeSort(int arr[], int left, int right)
{
    if (right-left==1){
        int mid=(left+right)/2;
        MergeSort(arr,left,mid);
        MergeSort(arr,mid,right);
        Merge(arr,left,right,mid);
    }
}

void QuickSort(int arr[], int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[left+int(rand()%(right-left))];
    int temp;

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (j > left)
        QuickSort(arr, left, j);
    if (i < right)
        QuickSort(arr, i, right);
}

int main()
{
   srand(time(NULL));
   int arr[SIZE];
   for(int i=0;i<SIZE;++i)
   {
       arr[i]=rand()%100;
       printf("%i ",arr[i]);
   }
   printf("\n");
   QuickSort(arr,0,SIZE-1);
    for(int i=0;i<SIZE;++i)
    {
        printf("%i ",arr[i]);
    }

}
