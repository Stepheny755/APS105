void convert(char *input, char *output, int lineLength){
  int index = 0,lastindex = 0,linenum = 0;
  char* temp;
  while(input[index]!='\0'){
    printf("%d %d %d %c\n",index,lastindex,linenum,input[index]);
    output[index]=input[index];
    if((index+1)/lineLength>linenum){
      output[lastindex]='\n';
      linenum++;
    }
    if(input[index]==' '){
      lastindex=index;
    }

    index++;
  }
}
