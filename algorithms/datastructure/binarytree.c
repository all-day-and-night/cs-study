#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node*leftChild;
    struct Node*rightChild;
}Node;

Node * initNode(int data, Node*leftChild, Node*rightChild){
    Node*node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->leftChild = leftChild;
    node->rightChild = rightChild;
    return node;
}

void preorder(Node *root){//왼쪽우선 순회, 전위우선순회
    if(root){
        printf("%d\n", root->data);
        preorder(root->leftChild);
        preorder(root->rightChild);
    }
}

void inorder(Node*root){
    if(root){
        inorder(root->leftChild);
        printf("%d\n", root->data);
        inorder(root->rightChild);
    }
}

void postorder(Node*root){
    if(root){
        postorder(root->leftChild);
        postorder(root->rightChild);
        printf("%d\n", root->data);
    }
}

int main() {
Node* n7 = initNode(50, NULL, NULL); 
Node* n6 = initNode(37, NULL, NULL); 
Node* n5 = initNode(23, NULL, NULL); 
Node* n4 = initNode(5, NULL, NULL); 
Node* n3 = initNode(48, n6, n7); 
Node* n2 = initNode(17, n4, n5); 
Node* n1 = initNode(30, n2, n3); 
preorder(n1); 
printf("\n"); 
inorder(n1); 
printf("\n"); 
postorder(n1); 
return 0;
}