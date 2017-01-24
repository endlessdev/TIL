#define TRUE 1

#include <stdio.h>
#include<stdlib.h>
typedef struct _node{
    int data;
    struct _node * next;
}Node;

int main(){
    
    Node * cur=NULL;
    Node * head=NULL;
    Node * tail=NULL;
    Node * newNode=NULL;
    
    int data;
    
    while(TRUE){

        printf("자연수를 입력해 주세요. 다 끝났으면 -1을 입력해주세요.");
        scanf("%d", &data);
        
        if(data < 0){
            break;
        } 
        
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        
        if(head == NULL){
            head = newNode;
        } else {
            tail->next = newNode;
        }
        
        tail = newNode;
    }

    if(head == NULL) {
        printf("처음부터 그러기냐 씨발아 ㅡㅡ");
    } else {
        cur = head;
        printf("%d ", cur->data);
        
        while(cur->next != NULL){
            cur = cur->next;
            printf("%d", cur->data);
        }
    }
    
}