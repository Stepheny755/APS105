#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

int printArray(int arr[],int n);
int* copyArray(int arr[],int n);
void nl();
void swap(int* a,int* b){
  int  temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int list[],int low,int high){
  int pivot = high,left = low,right = high-1;
  while(left<=right){
    while(list[left]<list[pivot]){
      left++;
    }
    while(list[right]>list[pivot]){
      right--;
    }
    if(left<right){
      swap(&list[left],&list[right]);
    }else{
      swap(&list[pivot],&list[left]);
    }
  }
}

void quickSort(int list[],int low,int high){
  if(low<high){
    int pivot = partition(list,low,high);
    printArray(list,high);
    quickSort(list,low,pivot-1);
    quickSort(list,pivot+1,high);
    printArray(list,high-low);
  }
}

void merge(int list[],int low,int mid,int high){
  //printf("%d %d %d\n",low,mid,high);
  int size1 = mid-low+1,size2 = high-mid,i,j;
  int temp1[size1],temp2[size2];
  for(i = 0;i < size1;i++){
    temp1[i]=list[low+i];
  }
  for(j = 0;j < size2;j++){
    temp2[j]=list[mid+1+j];
  }
  i = 0;
  j = 0;
  int k = low;
  while(i<size1&&j<size2){
    if(temp1[i]<=temp2[j]){
      list[k]=temp1[i];
      i++;
    }else{
      list[k]=temp2[j];
      j++;
    }
    k++;
  }
  while(i < size1){
    list[k] = temp1[i];
    i++;
    k++;
  }
  while(j < size2){
    list[k] = temp2[j];
    j++;
    k++;
  }
}

void mergeSort(int list[],int low,int high){
  if(high>low){
    int mid = (low+high)/2;
    mergeSort(list,low,mid);
    mergeSort(list,mid+1,high);
    merge(list,low,mid,high);
  }
}


void insertionSort(int list[],int n){
  for(int i = 1;i<n;i++){
    printArray(list,n);
    int current = list[i];
    int index = i;
    while(i > 0 && current < list[index-1]){
      list[index]=list[index-1];
      index--;
    }
    list[index]=current;
  }
}

void selectionSort(int list[],int n){
  int index = 0,min = INT_MAX;
  for(int i = 0;i<n;i++){
    printArray(list,n);

    if(list[i]<min){
      min = list[i];
    }
    if(i == n-1){
      i = ++index;
    }
  }
}







int main(void){
  int n = 10;
  int arr[]={1,5,8,2,6,0,4,3,7,9};
  //printArray(arr,n);
  int* arr2 = copyArray(arr,n);
  printArray(arr2,n);

  mergeSort(arr2,0,n);
  printArray(arr2,n);
  nl();


  return 0;
}

void nl(){
  printf("\n");
}

int printArray(int arr[],int n){
  printf("[");
  for(int i = 0;i < n;i++){
    printf("%d",arr[i]);
    if(i<n-1){
      printf(",");
    }
  }
  printf("]\n");
}

int* copyArray(int arr[],int n){
  int* new = (int*)malloc(sizeof(int)*n);
  memcpy(new,arr,sizeof(int)*n);
  return new;
}
