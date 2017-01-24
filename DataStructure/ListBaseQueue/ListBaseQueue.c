#include<stdio.h>
#include<stdlib.h>
#include "ListBaseQueue.h"

int main(){
  Queue q;
  QueueInit(&q);
  
  Enqueue(&q, 1);Enqueue(&q, 2);
  Enqueue(&q, 3);Enqueue(&q, 4);
  Enqueue(&q, 5);

    
  while(!QIsEmpty(&q)){
      printf("%d ", Dequeue(&q));
  }
  
}

void QueueInit (Queue * pq){
    pq->front = NULL;
    pq->rear = NULL;
}
int QIsEmpty(Queue * pq){
    if(pq->front == NULL){
        return TRUE;
    }else{
        return FALSE;
    }
}

void Enqueue(Queue * pq, Data data){
    Node * newNode = (Node*)malloc(sizeof(Node));
    
    newNode->data = data;
    newNode->next = NULL;
    
    if(QIsEmpty(pq)){
        pq->front = newNode;
        pq->rear = newNode;
    }else{
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}
Data Dequeue(Queue * pq){
    
    Node * tmpNode;
    Data tmpData;
    
    if(QIsEmpty(pq)){
        printf("이건 비어있으니까 빼낼 수 없다..");
        exit(-1);
    }
    
    tmpNode = pq->front;
    tmpData = pq->front->data;
    
    pq->front = pq->front->next;
    
    free(tmpNode);
    
    return tmpData;
}
Data QPeek(Queue * pq){
    if(QIsEmpty(pq)){
        printf("이건 비어있으니까 빼낼 수 없다..");
        exit(-1);  
    }
    
    return pq->front->data;
}