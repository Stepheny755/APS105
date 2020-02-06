#include <stdio.h>

void getPairDivisor(int n, int q, int* mAddress, int* pAddress);

int main(void){

  int input,query,mAdd,pAdd;

  printf("Please enter an input number n: ");
  scanf("%d",&input);

  printf("Please enter a query number q: ");
  scanf("%d",&query);

  getPairDivisor(input,query,&mAdd,&pAdd);

  if(mAdd==0&&pAdd==-1){
	printf("The program could not find any pair divisors for these inputs");
  }else{
	printf("m = %d, p = %d, m*p = %d, and m+p = %d\n",mAdd,pAdd,input,query);  
  }

  return 0;
}

void getPairDivisor(int n,int q,int* mAddress,int* pAddress){
  for(int m = 0;m<=n;m++){
    for(int p = 0;p<=n;p++){
      if(m*p==n&&m+p==q){
        *mAddress=m;
        *pAddress=p;
        //printf("m=%d p=%d",m,p);
        return;
      }
    }
  }
  *mAddress=0;
  *pAddress=-1;
}
