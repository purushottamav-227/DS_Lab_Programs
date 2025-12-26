#include <stdio.h>
#include <string.h> // for strlen()
#include <ctype.h> // for isalnum()
#define MAX 100
char Stack [MAX];
int top = -1;

void push (char c) {
    if (top == MAX)
        printf("Stack Overflow\n");
    else {
        top = top + 1;
        Stack [top] = c;
    }
}
char peek() {
    if (top == -1)
        return '\0';
    return Stack [top];
}
int precedence (char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}
char pop(){
    char val;
    if (top == -1){
        printf("Stack underflow\\n");
        return -1;
    } else {
        val = Stack[top];
        top = top - 1;
        return val;
    }
}

void infixToPostfix(char infix[], char postfix[]){
    int i, k = 0;
    char c;
    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];
        if (isalnum(c)){
            postfix[k] = c;
            k = k + 1;
        } else if (c == '('){
            push(c);
        } else if (c == ')'){
            while (top != -1 && peek() != '('){
                postfix[k] = pop();
                k = k + 1;
            }
            pop();
        } else {
            while(top != -1 && precedence(peek()) >= precedence(c)){
                postfix[k] = pop();
                k = k + 1;
            }
            push (c);
        }
    while (top!=-1){
        postfix [k]=pop();
        k=k+1
    } 
    postfix [k]='\0';
    }
}

int main(){
    char infix [Max], postfix [Max];
    printf ("Enter a valid paranthesized infix expression: ");
    scanf("%s", infix);
    infixToPostfix (infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}
