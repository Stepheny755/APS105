struct listNode* createNode(int value){
  struct listNode* temp = (struct listNode*)malloc(sizeof(struct listNode));
  temp->value = value;
  temp->nextNode = NULL;
  return temp;
}

struct listNode* insertTail(struct groupNode* group,int value){
  if(group->firstNode==NULL){
    group->firstNode=createNode(value);
    return group->firstNode;
  }
  struct listNode* temp = group->firstNode;
  while(temp->nextNode!=NULL){
    temp=temp->nextNode;
  }
  temp->nextNode = createNode(value);
  return temp->nextNode;
}

struct listNode *insertGNode(int value) {// put your code here
  for(int i = 0;i < NUMGROUPS;i++){
    if(value<groups[i].maxInGroup){
      return insertTail(groups+i,value);
    }
  }
  return NULL;
}

int inGroup(struct groupNode* group,int value){
  if(group->firstNode==NULL){
    return 0;
  }
  struct listNode* temp = group->firstNode;
  while(temp!=NULL){
    if(temp->value==value){
      return 1;
    }
    temp=temp->nextNode;
  }
  return 0;
}

int foundGNode(int valIn) {//put your code here
  for(int i = 0;i < NUMGROUPS;i++){
    if(valIn<groups[i].maxInGroup&&(inGroup(groups+i,valIn))){
      return i;
    }
  }
  return 0;
}
