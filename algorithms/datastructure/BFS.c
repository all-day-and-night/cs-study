#include<stdio.h>
#include<stdlib.h>
#define INF 9999999
#define MAX 1001

typedef struct Node{
    int index;
    struct Node* next;
}Node;

typedef struct Queue{
    Node*front;
    Node*rear;
    int count;
}Queue;

Node**a;
int n, m, c[MAX];

void addFront(Node*root, int index){
    Node*node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->next = root->next;
    root->next = node;
}

void queuePush(Queue* queue, int index){
    Node* node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->next = NULL;
    if(queue->count == 0){
        queue->front = node;
    }
    else {
        queue->rear->next = node;
    }
    queue->rear = node;
    queue->count++;
}

int queuePop(Queue * queue){
    if(queue->count==0){
        printf("queue underflow\n");
        return -INF;
    }
    Node * node = queue->front;
    int index = node->index;
    queue->front = node->next;
    free(node);
    queue->count--;
    return index;
}

void bfs(int start){
    Queue q;
    q.front = q.rear  =NULL;
    q.count = 0;
    queuePush(&q, start);
    c[start] = 1;
    while(q.count !=0){
        int x = queuePop(&q);
        printf("%d ", x);
        Node * cur = a[x]->next;
        while(cur != NULL){
            int next = cur->index;
            if(!c[next]){
                queuePush(&q, next);
                c[next]=1;
            }
            cur = cur->next;
        }
    }
}

int main() {
     scanf("%d %d", &n, &m);
    a = (Node**)malloc(sizeof(Node*)*MAX);
    for(int i=1; i<=n ; i++){
        a[i] = (Node*)malloc(sizeof(Node));
        a[i]->next = NULL;
    }
    for(int i=0; i<m; i++){
        int x,y;
        scanf("%d %d", &x, &y);
        addFront(a[x], y);
        addFront(a[y], x);
    }
    int k;
    scanf("%d", &k);
    bfs(k);
    return 0;
}