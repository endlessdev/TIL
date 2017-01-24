#include <stdio.h>
#include "CircleQueue.h"
#include <stdlib.h>

int main(){
    Queue q;
    QueueInit(&q);
    
    Enqueue(&q, 1); Enqueue(&q, 2);
    Enqueue(&q, 3); Enqueue(&q, 4);
    Enqueue(&q, 5);
    
    while(!QIsEmpty(&q)){
        printf("%d ", Dequeue(&q));
    }
    
    return 0;
}

void QueueInit(Queue * pq){
    pq->front = 0;
    pq->rear = 0;
}

int QIsEmpty(Queue * pq){
    if(pq->front == pq -> rear){
        return TRUE;
    } else {
        return FALSE;
    }
}


int NextPostIdx(int pos){
    if(pos == QUE_LEN -1)
        return 0;
    else
        return pos+1;
}


void Enqueue(Queue * pq, Data data){
    if(NextPostIdx(pq->rear) == pq->front){
        printf("꽉 찼다!");
        exit(-1);
    }
    
    pq->rear = NextPostIdx(pq->rear);
    pq->queArr[pq->rear] = data;
    
}

Data Dequeue(Queue * pq){
    if(QIsEmpty(pq)){
        printf("비어있다");
        exit(-1);
    } 
    
    pq->front = NextPostIdx(pq->front);
    return pq->queArr[pq->front];
}

Data QPeek(Queue * pq){
    if(QIsEmpty(pq)){
        printf("큐가 공허하다!!");
        exit(-1);
    }
    
    return pq->queArr[NextPostIdx(pq->front)];
}

