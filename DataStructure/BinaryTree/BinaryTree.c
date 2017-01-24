#include<stdio.h>
#include<stdlib.h>
#include"BinaryTree.h"

int main(){
    BTreeNode * bt1 = MakeBTreeNode(); 
    BTreeNode * bt2 = MakeBTreeNode();
    BTreeNode * bt3 = MakeBTreeNode();
    BTreeNode * bt4 = MakeBTreeNode();
    
    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    
    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);
    
    //bt1의 왼쪽 자식 노드의 데이터 출력
    printf("%d \n", GetData(GetLeftSubTree(bt1)));
    
    //bt1의 왼쪽 자식 노드의 왼쪽 자식 노드의 데이터 출력
    printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));
}

BTreeNode * MakeBTreeNode(){
    BTreeNode * newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

BTData GetData(BTreeNode * bt){
    return bt->data;
}

void SetData(BTreeNode * bt, BTData data){
    bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt){
    return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt){
    return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub){
    if(main->left != NULL){
        free(main->left);
    }
    main->left = sub;  
}


void MakeRightSubTree(BTreeNode * main, BTreeNode * sub){
    if(main->right != NULL){
        free(main->right);
    } 
    main->right = sub;  
}