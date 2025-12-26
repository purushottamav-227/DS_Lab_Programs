#include <stdio.h>
include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int value) {
    struct Node newNode = (struct Node)
    malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

//push
void push(struct Node *top, int value) {
    struct Node *newNode = createNode(value);
    newNode->next = top;
    *top = newNode;
    printf("%d pushed to stack \n", value);
}
//pop
void pop(struct Node *top) {
    if (top == NULL) {
        printf ("Stock underflow\n");
        return;
    } 
    struct Node *temp = *top;
    printf("%d popped from stack \n", temp->data);
    *top = (*top)->next;
    free (temp);
}

// Display
void displayStack (struct Node *top) {
    printf ("Stack: ");
    while (top!= NULL) {
        printf("%d", top->data);
        top top->next;
    } 
    printf ("Null \n");
}

// Enqueue
void enqueue (struct Node **front, struct Node **rear,int value){
    struct Node *newNode = CreateNode (value);
    if (*rear==NULL){
        *front = *rear= newNode;
    }else{
        (*rear) -> next = NewNode;
        *rear = newNode;
    } 
    printf ("%d enqueued to queue \n", value);
}
    // Dequeue
void dequeue (struct Node **front, struct Node **rear) {
    if (*front==NULL){
        printf ("Queue underflow \n");
        return;
    }
    struct Node *temp = *front;
    printf("%d dequeued from queue \n", temp->data);
    *front = (*front)->next;
    if(*front == NULL) {
        *rear = NULL;
    } 
    free (temp);
}

void displayQueue (struct Node *front){
    printf("\nQueue: ");
    while(front){
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main(){
    struct Node *stackTop = NULL, *queueFront = NULL, *queueRear = NULL;
    // Stack operations
    push(&stackTop, 10);
    push(&stackTop, 20);
    push(&stackTop, 30);
    displayStack(stackTop);
    pop(&stackTop);
    displayStack(stackTop);

    // Queue operations
    enqueue(&queueFront, &queueRear, 100);
    enqueue(&queueFront, &queueRear, 200);
    enqueue(&queueFront, &queueRear, 300);
    displayQueue(queueFront);
    dequeue(&queueFront, &queueRear);
    displayQueue(queueFront);
    return 0;
}
