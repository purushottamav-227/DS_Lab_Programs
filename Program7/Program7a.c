include <stdio.h>
include <stdlib.h>

struct node{
    int data;
    Struct node *prev;
    Struct node *next;
};

struct node *Start = NULL;
void createList(){
    Start = NULL;
    void createList (int item) {
        struct node *p;
        p = (struct node*) malloc (sizeof(struct node));
        p->next = NULL;
        p->prev = NULL;
        if (start == NULL) {
            start = p;
        } else {
            start->next = p;
            start->prev = p;
            p->prev = start;
            p->next = start;
            start = p;
            start->prev = NULL;
        }
    }
}

void insertLeft (int item, int value, struct node *start){
    struct node *p, *temp;
    p = (struct node*) malloc(sizeof(struct node));
    p->data = item;
    if (start == NULL){
        printf("List is empty\n");
        return;
    }
    temp = start;
    while (temp!= NULL && temp->data != value)
        temp = temp->next;
    if (temp == NULL) {
        printf ("Value not found \n");
        return;
    }
    p->next = temp;
    p->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = p;
    else start = p;
        temp->prev = p;
}
void deleteNode( int item) {
    struct node *temp = start;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL && temp->data != item) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        start = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

void display() {
    struct node *temp = start;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Doubly linked list:");
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main() {
    int choice, data, item;
    createlist();
    createlist(40);
    createlist(60);
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the item to insert: ");
                scanf("%d", &item);
                printf("Enter the value: ");
                scanf("%d", &value);
                insertLeft (item, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode (value);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exited...");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}


