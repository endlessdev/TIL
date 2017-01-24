#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

int main(){
        
    Stack stack;
    StackInit(&stack);
    
    SPush(&stack, 1);SPush(&stack, 2);
    SPush(&stack, 3);SPush(&stack, 4);
    SPush(&stack, 5);
    
    while(!SIsEmpty(&stack)){
        printf("%d ", SPop(&stack));
    }
    
        
    return 0;
}

void StackInit(Stack * pstack){
    pstack->head = NULL;
}
int SIsEmpty(Stack * pstack){
    if(pstack->head == NULL){
        return TRUE;
    }else {
        return FALSE;
    }
}

void SPush(Stack * pstack, Data data){
    Node * newNode =(Node*)malloc(sizeof(Node));
    
    newNode->data = data;
    newNode->next = pstack->head;
    
    pstack->head = newNode;
}
Data SPop(Stack * pstack){
    
    Node * tmpNode;
    Data tmpData;
    
    if(SIsEmpty(pstack)){
        printf("스택이 비어있음");
        exit(-1);
    }
    
    tmpNode = pstack->head;
    tmpData = pstack->head->data;
    
    
    pstack->head = pstack->head->next;
    
    free(tmpNode);
    
    return tmpData;
    
}
Data SPeek(Stack * pstack){
    if(SIsEmpty(pstack)){
        printf("스택이 비어있음");
        exit (-1);
    }
    
    return pstack->head->data;
}
