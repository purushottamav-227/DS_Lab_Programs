#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

/* Insert at beginning */
struct node *insertllbeg(struct node *start, int item) {
    struct node *p, *temp;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = item;

    if (start == NULL) {
        printf("No list is found, hence new node is created and inserted..\n");
        p->next = NULL;
        start = p;
    } else {
        p->next = start;
        start = p;
    }
    return start;
}

/* Insert at end */
struct node *insertllend(struct node *start, int item) {
    struct node *p, *temp;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = item;

    if (start == NULL) {
        printf("No list is found, hence new node is created and inserted..\n");
        p->next = NULL;
        start = p;
    } else {
        temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        p->next = NULL;
        temp->next = p;
    }
    return start;
}

/* Insert at specific position */
struct node *insertllgnpos(struct node *start, int item, int pos) {
    struct node *p, *temp, *follow;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = item;

    if (start == NULL) {
        printf("No list is found, hence new node is created and inserted..\n");
        p->next = NULL;
        start = p;
    } else {
        temp = start;
        int i = 0;

        if (pos == 1) {
            start = insertllbeg(start, item);
        } else {
            while (temp->next != NULL) {
                follow = temp;
                temp = temp->next;
                i = i + 1;

                if (pos - 1 == i) {
                    follow->next = p;
                    p->next = temp;
                    exit(0);
                }
            }
        }
    }
    return start;
}

/* Delete from beginning */
struct node *deletesllbeg(struct node *start) {
    struct node *temp;

    if (start == NULL) {
        printf("Linked list is empty...\n");
    } else if (start->next == NULL) {
        temp = start;
        printf("The deleted element is : %d\n", start->info);
        start = NULL;
        free(temp);
    } else {
        temp = start;
        printf("The deleted element is : %d\n", start->info);
        start = start->next;
        free(temp);
    }
    return start;
}

/* Delete from end */
struct node *deletesllend(struct node *start) {
    struct node *temp, *follow;

    if (start == NULL) {
        printf("Linked list is empty...\n");
        start = NULL;
    } else if (start->next == NULL) {
        printf("The deleted element is : %d\n", start->info);
        free(start);
        start = NULL;
    } else {
        temp = start;
        while (temp->next != NULL) {
            follow = temp;
            temp = temp->next;
        }
        printf("The deleted element is : %d\n", temp->info);
        follow->next = NULL;
        free(temp);
    }
    return start;
}

/* Delete from specific position */
struct node *deletesllgnpos(struct node *start, int pos) {
    struct node *temp, *follow;

    if (start == NULL) {
        printf("Linked list is empty...\n");
        start = NULL;
    } else {
        temp = start;
        int i = 0;

        if (pos == 1) {
            start = deletesllbeg(start);
        } else {
            while (temp->next != NULL) {
                follow = temp;
                temp = temp->next;
                i = i + 1;

                if (pos - 1 == i) {
                    follow->next = temp->next;
                    free(temp);
                    exit(0);
                }
            }
        }
    }
    return start;
}

/* Display */
void display(struct node *start) {
    struct node *temp = start;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    } else {
        printf("Current list : ");
        while (temp != NULL) {
            printf("%d ", temp->info);
            temp = temp->next;
        }
        printf("\n");
    }
}

/* Main */
void main() {
    struct node *start = NULL;
    int operation, choice, item, pos;

    while (1) {
        printf("\n--- Main Menu ---\n");
        printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &operation);

        switch (operation) {
        case 1:
            while (1) {
                printf("\n--- Insertion Menu ---\n");
                printf("1. Beginning\n2. End\n3. Specific Position\n4. Back to main menu\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if (choice == 4)
                    break;

                printf("Enter the element to insert: ");
                scanf("%d", &item);

                switch (choice) {
                case 1:
                    start = insertllbeg(start, item);
                    break;
                case 2:
                    start = insertllend(start, item);
                    break;
                case 3:
                    printf("Enter the position to insert: ");
                    scanf("%d", &pos);
                    start = insertllgnpos(start, item, pos);
                    break;
                default:
                    printf("Invalid choice\n");
                }
            }
            break;

        case 2:
            while (1) {
                printf("\n--- Deletion Menu ---\n");
                printf("1. Beginning\n2. End\n3. Specific Position\n4. Back to main menu\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if (choice == 4)
                    break;

                switch (choice) {
                case 1:
                    start = deletesllbeg(start);
                    break;
                case 2:
                    start = deletesllend(start);
                    break;
                case 3:
                    printf("Enter the position to delete: ");
                    scanf("%d", &pos);
                    start = deletesllgnpos(start, pos);
                    break;
                default:
                    printf("Invalid choice\n");
                }
            }
            break;

        case 3:
            display(start);
            break;

        case 4:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}
