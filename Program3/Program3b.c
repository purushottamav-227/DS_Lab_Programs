#include <stdio.h>
#define max 5

int cqueue[max];
int front = -1;
int rear = -1;

void insertion(int item) {
    if (front == (rear + 1) % max) {
        printf("Circular queue is full...\n");
    }
    else if (front == -1){
        front = 0;
        rear = 0;
        cqueue[front] = item;
        printf("%d is inserted...\n", item);
    }
    else {
        rear = (rear + 1) % max;
        cqueue[rear] = item;
        printf("%d is inserted...\n", item);
    }
}

int deletion(){
    int item;
    if (front == -1){
        printf("Circular Queue is empty...");
        item = -1;
    }
    else if (front == rear){
        item = cqueue[front];
        front = -1;
        rear = -1;
    }else {
        item = cqueue[front];
        front = (front + 1) % max;
        return item;
    }
}

void display() {
    if (front == -1) {
        printf("Circular Queue is empty..");
    } else {
        printf("The elements are:\n");
        int i = front;
        while (1) {
            printf("%d \n", cqueue[i]);
            if (i == rear) {
                break;
            }
            i = (i + 1) % max;
        }
    }
}

// main function
void main() {
    int choice, item;
    while (1) {
        printf("Enter your choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to insert:");
                scanf("%d", &item);
                insertion(item);
                break;
            case 2:
                item = deletion();
                if (item != -1) {
                    printf("%d is deleted.\n", item);
                }
                break;
             case 3:
                display();
                 break;
             default:
                 exit(0);
}}}
