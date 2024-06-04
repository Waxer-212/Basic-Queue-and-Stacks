#include <stdio.h>
#include <stdlib.h>
#define INT_MIN -10000
typedef int data;

struct node{
    data val;
    struct node *next;
};
typedef struct node Node;

struct queue{
    Node* front;
    Node *rear;
};
typedef struct queue Queue;

Queue* createQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if(q == NULL)
        return NULL;
    q->front = q->rear = NULL;

    return q;
}

void enQueue(Queue* q, data val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    if(q->rear == NULL)
        q->rear = newNode;
    else
    {
        (q->rear)->next = newNode;
        q->rear = newNode;
    }
    if (q->front == NULL)
        q->front = q->rear;

}

int isEmpty(Queue *q)
{
    return(q->front==NULL);
}

data deQueue(Queue* q)
{
    Node*aux;
    data d;
    if(isEmpty(q))
        return INT_MIN;

    aux = q->front;
    q->front = (q->front)->next;
    d = aux->val;
    free(aux);

    if(q->front == NULL) q->rear = NULL;
    return d;
}

void printList(Node* head)
{
    while(head!=NULL)
    {
        printf("%d ",head->val);
        head = head->next;
    }
    printf("\n");
}

void deleteQueue(Queue *q)
{
    Node* aux;
    while(!isEmpty(q))
    {
        aux = q->front;
        q->front = (q->front)->next;
        free(aux);
    }

    free(q);
}

void push(Node** top, data val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = *top;

    *top = newNode;
}

data pop(Node**top)
{
    Node* aux;
    if(*top == NULL)
    {
        return INT_MIN;
    }
    aux = *top;
    *top = (*top)->next;
    data d  = aux->val;
    free(aux);

    return d;
}
int main()
{
    Node* stackTop = NULL;
    Queue*q = createQueue();

    enQueue(q,6);
    enQueue(q,2);
    enQueue(q,612);
    enQueue(q,43);
    enQueue(q,20);
    enQueue(q,7);
    printList((q->front));
    deQueue(q);
    printList((q->front));
    deleteQueue(q);
    printf("%d\n",isEmpty(q));

    push(&stackTop, 7);
    push(&stackTop, 72);
    push(&stackTop, 17);
    push(&stackTop, 32);
    push(&stackTop, 98);
    printList(stackTop);
    pop(&stackTop);
    printList(stackTop);

    return 0 ;
}
