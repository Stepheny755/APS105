#include <stdio.h>
#include <stdlib.h>


int fibhelper(int n);
int fib(int n,int* arr);

int main(void){

printf("%d\n",fibhelper(20));

}

int fibhelper(int n){
int* arr = (int*)calloc(sizeof(int),n);
return fib(n,arr);
}

int fib(int n,int* arr){
printf("%d\n",n);
if(n == 0||n == 1){
return 1;
}else if(arr[n]!=0){
return arr[n];
}else{
arr[n] = fib(n-1,arr)+fib(n-2,arr);
return arr[n];
}
}
