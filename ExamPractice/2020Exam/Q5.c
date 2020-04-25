unsigned int generateInt(int list[],int size){
  unsigned int result = 0;
  for(int i = 0;i<size;i++){
    result+=pow(2,list[i]);
  }
  return result;
}
