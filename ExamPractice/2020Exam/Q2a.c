

int main(){
  for(int i = 0;i<10;i++){
    char* temp = getInstring();
    char* new = (char*)malloc(sizeof(char)*(strlen(temp)+1));
    strcpy(new,temp);
    pInstring[i]=new;
  }
}
