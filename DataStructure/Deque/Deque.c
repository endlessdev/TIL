#include "Deque.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    // Deque의 생성 및 초기화
	Deque deq;
	DequeInit(&deq);

	// 데이터 넣기 1차
	DQAddFirst(&deq, 3);
	DQAddFirst(&deq, 2);
	DQAddFirst(&deq, 1);

	DQAddLast(&deq, 4);
	DQAddLast(&deq, 5);
	DQAddLast(&deq, 6);

	// 데이터 꺼내기 1차
	while (!DQIsEmpty(&deq))
		printf("%d ", DQRemoveFirst(&deq));

	printf("\n");

	// 데이터 넣기 2차
	DQAddFirst(&deq, 3);
	DQAddFirst(&deq, 2);
	DQAddFirst(&deq, 1);

	DQAddLast(&deq, 4);
	DQAddLast(&deq, 5);
	DQAddLast(&deq, 6);

	// 데이터 꺼내기 2차
	while (!DQIsEmpty(&deq))
		printf("%d ", DQRemoveLast(&deq));

	return 0;
}

void DequeInit(Deque * pdeq){
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

int DQIsEmpty(Deque * pdeq){
    if(pdeq->head == NULL){
        return TRUE;
    } else {
        return FALSE;
    }
}

void DQAddFirst(Deque * pdeq, Data data){
    
    Node * newNode = (Node*)malloc(sizeof(Node));
    
    newNode->data = data;
    newNode->next = pdeq->head;
    
    if(DQIsEmpty(pdeq)){
        pdeq->tail = newNode;
    } else {
        pdeq->head->prev = newNode;
    }
    
    newNode->prev = NULL;
    pdeq->head = newNode;
}

void DQAddLast(Deque * pdeq, Data data){
    Node * newNode = (Node*)malloc(sizeof(Node));
    
    newNode->data = data;
    newNode->prev = pdeq->tail;
    
    if(DQIsEmpty(pdeq)){
        pdeq->head = newNode;
    } else {
        pdeq->tail->next = newNode;
    }  
    
    newNode -> next = NULL;
    pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque * pdeq){
    Node * tmpNode = pdeq->head;
    Data tmpData = tmpNode->data;
    
    if(DQIsEmpty(pdeq)){
        printf("메모리 에러가 났다..");
        exit(-1);
    }
    
    
    pdeq->head = pdeq->head->next;
    free(tmpNode);

    
    if(DQIsEmpty(pdeq)){
        pdeq->tail = NULL;
    } else {
        pdeq->head->prev = NULL;
    }
    
    return tmpData;

}

Data DQRemoveLast(Deque * pdeq){
    Node * tmpNode = pdeq->tail;
    Data tmpData;
    
    if(DQIsEmpty(pdeq)){
        printf("메모리 에러가 났다..");
        exit(-1);
    }
    tmpData = pdeq->tail->data;
    
    pdeq->tail = pdeq->tail->prev;
    free(tmpNode);

    
    if(pdeq->tail == NULL){
        pdeq->head = NULL;
    } else {
        pdeq->tail->next = NULL;
    }
    
    return tmpData;
}

Data DQGetFirst(Deque * pdeq){
    if(DQIsEmpty(pdeq)){
        printf("참조할 수 없음");
        exit(-1);
    }
    
    return pdeq->head->data;
}

Data DQGetLast(Deque * pdeq){
    if(DQIsEmpty(pdeq)){
        printf("참조할 수 없음");
        exit(-1);
    }
    
    return pdeq->tail->data;
}