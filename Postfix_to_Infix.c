#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
char stack[100][100];
int top = -1;
void push(char* str) {
    strcpy(stack[++top],str);
}
char* pop() {
    return stack [top--];
}
int isOperator(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/' || x == '^');
}
   int main() {
    char postfix[MAX];
    char op1[100], op2[100], temp[200];
    printf("Enter postfix expression: ");
    scanf("%s",postfix);
    for(int i=0; postfix[i] !='\0'; i++) {
        if(isalnum(postfix[i])) {
            char tempstr[2] = { postfix[i], '\0'};
            push(tempstr);
        }
        else if (isOperator(postfix[i])) {
            strcpy(op2, pop());
            strcpy(op1, pop());
            sprintf(temp, "(%s%c%s)",op1, postfix[i], op2);
            push(temp);
        }
    }
    printf("Infix expression: %s\n",stack[top]);
    return 0;
   }