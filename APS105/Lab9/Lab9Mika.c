#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "rawRecipes.h"

//removes the first character from a string
const char* strShift(char string[60]){
    int i=0;
    while(string[i] != '\0'){
        string[i] = string[i+1];
        i++;
    }
    return string;
}

int main()
{
    printf("hello\n");

    char words[][60] ={"august","september","october"};
    char newwords[3][60];
    for(int i = 0; i<3;i++){
        printf("%s\n",rawRecipes[i]);
        char p[60];
        p=rawRecipes[i];
        strcpy(newwords[i],strShift(p));
        printf("\nword: %s\n",newwords[i]);
    }

    printf("\nbye");

    return 0;
}
