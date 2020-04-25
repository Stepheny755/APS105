void insertionSort(int list[],int n){
  for(int i = 1;i<n;i++){
    int current = list[i];
    int index = i;
    while(i > 0 && current < list[index-1]){
      list[index]=list[index-1];
      index--;
    }
    list[index]=current;
  }
}
int* merge(int* size){

  int numArrays;
  printf("\nPlease enter the number of arrays you have:");
  scanf("%d",&numArrays);
  int totalsize = 0;
  int* arr = (int*)malloc(sizeof(int)*1);
  int lastindex = 0;
  for(int i = 1;i <= numArrays;i++){
    int arraysize;
    printf("\nPlease enter the size of array %d: ",i);
    scanf("%d",&arraysize);
    totalsize+=(arraysize);
    arr = realloc(arr,totalsize*sizeof(int));
    printf("\nPlease enter the array number %d: ",i);
    for(int j = 0;j < arraysize;j++){
      scanf("%d",arr+lastindex+j);
    }
    lastindex = totalsize;
  }
  *size = totalsize;
  int* output = (int*)malloc(sizeof(int)*totalsize);
  insertionSort(arr,totalsize);
  for(int i = 0;i < totalsize;i++){
    printf(" %d",arr[i]);
  }
  int done = 0,counter = 0,i = 0,j = totalsize-1;
  while(j>=i){
    if(counter%2==0){
      output[counter]=arr[i];
      i++;
    }else{
      output[counter]=arr[j];
      j--;
    }
    counter++;
  }
  free(arr);
  return output;
}
