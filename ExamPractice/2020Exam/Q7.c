void removeStringFromStringHelper(char* str,char* substr){
  int len = strlen(substr);
  char* found = strstr(str,substr);
  if(found!=NULL){
    *found='\0';
    strcat(str,found+len);
    removeStringFromStringHelper(str,substr);
  }else{
    return;
  }
}

const char* removeStringFromString(const char* str,const char* substr){
  char* tempstr = (char*)malloc(sizeof(char)*strlen(str));
  strcpy(tempstr,str);
  removeStringFromStringHelper(tempstr,substr);
  return tempstr;
}
