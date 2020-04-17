#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

int printArray(int arr[],int n);
int* copyArray(int arr[],int n);
void nl();

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
  //printArray(arr2,n);

  insertionSort(arr2,n);
  //printArray(arr2,n);
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
