include <stdio.h>
include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

struct Node *CreateNode(int value){
    struct Node *newNode = (struct Node *)
    malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node *head, int value){
    struct Node *newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(struct Node *head){
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Sorting
void sortList(struct Node *head) {
    if (head == NULL) return;
    int swapped;
    struct Node *ptr;
    struct Node *lptr = NULL;

    do {
        swapped = 0;
        ptr = head;

        while (ptr->next != lptr){
            if (ptr->data > ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
}
//Reverse sll
struct Node *reverseList(struct Node *head) {
    struct Node *prev = NULL, *current = head, *nextNode = NULL;
    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

// concatenate two lists
struct Node *concatenate(struct Node *head1, struct Node *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    struct Node *temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    insertEnd(&list1, 30);
    insertEnd(&list1, 10);
    insertEnd(&list1, 50);
    insertEnd(&list1, 20);
    printf("List1 before sorting:\n");
    display(list1);
    sortList(list1);
    printf("List1 after sorting:\n");
    display(list1);
    list1 = reverseList(list1);
    printf("List1 after reversing:\n");
    display(list1);

    insertEnd(&list2, 5);
    insertEnd(&list2, 15);
    insertEnd(&list2, 25);
    printf("List 2:\n");
    display(list2);

    struct Node *merged=concatenate(list1, list2);
    printf("Concatenated list:");
    display(merged);
    return 0;
}
