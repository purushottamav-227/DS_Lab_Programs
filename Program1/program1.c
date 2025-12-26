#include <stdio.h>
int maxsize=2;
int arr[2];
int top=-1;
void push(){
    int ele;
    if (top==(maxsize-1)){
        printf("Stack overflow\n");
    }else{
        top++;
        printf("Enter the element to be pushed: ");
        scanf("%d", &ele);
        arr[top] = ele;
        printf("Element pushed successfully \n");
    }
}

int pop(){
    if (top==-1){
        printf ("Stack underflow \n");
        return -1;
    } else {
        int item = arr[top];
        top--;
        printf("Element poped\n");
        return item;
    }
}
void display()
{
    if (top == -1)
    {
        printf("Stack underflow in");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", arr[i]);
        }
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("Enter choice in 1. Push in 2. Pop in 3. display in 4. exit");
        scanf("%d", &choice);
        if (choice == 1)
            push();
        else if (choice == 2)
            printf("Popped element: %d\n", pop());
        else if (choice == 3)
            display();
        else
            break;
    }
}

