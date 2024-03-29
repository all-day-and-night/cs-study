#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node * head;

void addFront(Node*root, int data){
    Node*node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = root->next;
    root->next = node;
}
void removeFront(Node * root){
    Node*front = root->next;
    root->next = front->next;
    free(front);
}
void freeAll(){
    Node * cur = head->next;
    while(cur != NULL){
        Node * next = cur -> next;
        free(cur);
        cur = next;
    }
}
void showAll(){
    Node * cur = head->next;
    while(cur != NULL){
        printf("%d\n", cur->data);
        cur = cur->next;
    }
}
int main() {
    head = (Node*)malloc(sizeof(Node));
    Node * node1 = (Node*)malloc(sizeof(Node));
    node1->data = 1;
    head->next = node1;
    Node * node2 = (Node*)malloc(sizeof(Node));
    node2->data = 2;
    node1->next = node2;
    node2->next = NULL;
    Node*cur = head->next;
    while(cur != NULL){
        printf("%d \n", cur->data);
        cur = cur->next;
    }
    return 0;
}