#include <stdio.h>
#include "DLinkedList.h"

int main(){
    
    return 0;
}

void ListInit(List * plist){
    plist->head = (Node)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    
    plist->numOfData = 0;
}

void LInsert(List * plist, Ldata * data){
    if(plist->comp == NULL)
        FInsert(plist, data);
    else
        SInsert(plist, data);
}

// First 값을 넣는거
void FInsert(List * plist, Ldata * data){
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = plist->head->next;
    
    plist->head->next = newNode;
    
    plist->numOfData++;
}

// 
void SInsert(List *plist){
    
}