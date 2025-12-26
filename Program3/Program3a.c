
#include <stdio.h>
#define MAX 2
int queue [MAX];
front=-1;
rear=-1;
// insertion of element to the queue
void enqueue (int item) {
    if (rear==MAX-1){
        printf(" Queue Overflow \n");
    }else if (front ==-1) {
        front=0;
        rear=0;
        queue [rear] = item;
        printf("%d is added to the queue \n", item);
    }
    else
    {
        rear=rear+1;
        queue [rear]=item;
        printf("%d is added to the queue \n", item);
    }
}

// deletion of element from the queue
void dequeue() {
    int item;
    if (front==-1){
        printf (" Queue Underflow \n");
    }
    else if (front == rear) {
        item= queue [rear];
        front=-1;
        rear=-1;
        printf("%d is deleted \n", item);
    }
    else
    {
        item=queue [rear];
        rear=rear-1;
        printf("%d is deleted \n", item);
    }
}

// displaying the elements in the queue
void display()
{
    if (front == -1)
        printf("Queue underflow\n");
    else
    {
        printf("The elements are: \n");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}

// main function
void main()
{
    int choice;
    while (1)
    {
        printf("Enter your choice \n1. Enqueue \n2. Dequeue \n3. Display \n4. Exit\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int item;
            printf("Enter the Element to insert: ");
            scanf("%d", &item);
            enqueue(item);
        }
        else if (choice == 2)
            dequeue();
        else if (choice == 3)
            display();
        else if (choice == 4)
            exit(0);
    }
}
