#include<stdio.h>
#include<stdlib.h>
#include"BinaryTree2.h"

void ShowIntData(int data){
    printf("%d ", data);
}
int main(){
    BTreeNode * bt1 = MakeBTreeNode(); 
    BTreeNode * bt2 = MakeBTreeNode();
    BTreeNode * bt3 = MakeBTreeNode();
    BTreeNode * bt4 = MakeBTreeNode();
    BTreeNode * bt5 = MakeBTreeNode();
    BTreeNode * bt6 = MakeBTreeNode();
    
    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    SetData(bt5, 5);
    SetData(bt6, 6);
    
    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);
    MakeRightSubTree(bt2, bt5);
    MakeRightSubTree(bt3, bt6);
    
    PreorderTravers(bt1, ShowIntData);
    printf("\n");
    InorderTravers(bt1, ShowIntData);
    printf("\n");
    PostorderTravers(bt1, ShowIntData);
    printf("\n");
    return 0;
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

void PreorderTravers(BTreeNode * bt, VisitFuncPtr action){
    if(bt == NULL){
       // printf("응 아니야");
        return ;
    }
    
    action(bt->data);
    PreorderTravers(bt->left, action);
    PreorderTravers(bt->right, action);
}


void InorderTravers(BTreeNode * bt, VisitFuncPtr action){
    if(bt==NULL){
       // printf("응 아니야");
        return;
    }
    InorderTravers(bt->left, action);
    action(bt->data);
    InorderTravers(bt->right, action);
}

void PostorderTravers(BTreeNode * bt, VisitFuncPtr action){
    if(bt==NULL){
      //  printf("응 아니야");
        return;
    }
    PostorderTravers(bt->left, action);
    PostorderTravers(bt->right, action);
    action(bt->data);
}