void pointerStuff(int** p){
  **p=100;
  *p=*(p+1);
  return;
}

int main(void){
  int* q;
  int myNumbers[10];

  q=&(myNumbers[3]);
  pointerStuff(&q);
}
