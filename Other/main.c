#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void){

	srand(time(NULL));
	double num = (double)rand()/RAND_MAX*4.0+1;
	for(int i = 0;i < 10;i++){
		num = (double)rand()/RAND_MAX*4.0+1;
		printf("%d\n",(int)num);
	}
	return 0;
}
