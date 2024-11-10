Scenario-1: Imagine a simple calculator application that allows users to input mathematical 
expressions in postfix notation. This is particularly useful for evaluating expressions 
without needing to worry about operator precedence or parentheses


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h> 
#define MAX 100
typedef struct{
    int top;
    int items[MAX];
}Stack;
void initStack(Stack *s){
    s->top=-1;
}
int isEmpty(Stack *s){
    return s->top==-1;
}
void push(Stack *s,int item){
    if(s->top<MAX-1){
        s->items[++s->top]=item;
    }else{
        printf("Stack overflow!\n");
    }
}
int pop(Stack *s){
    if(!isEmpty(s)){
        return s->items[s->top--];
    }else{
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
}
int evaluatePostfix(char *expression){
    Stack stack;
    initStack(&stack);
    char *token=strtok(expression," ");

    while(token != NULL){
        if(isdigit(token[0])){  
            push(&stack,atoi(token));
        }else{
            int operand2=pop(&stack);
            int operand1=pop(&stack);

            switch(token[0]){
                case '+':
                    push(&stack,operand1+operand2);
                    break;
                case '-':
                    push(&stack,operand1-operand2);
                    break;
                case '*':
                    push(&stack,operand1*operand2);
                    break;
                case '/':
                    if(operand2!=0){
                        push(&stack,operand1/operand2);
                    }else{
                        printf("Division by zero!\n");
                        exit(EXIT_FAILURE);
                    }
                    break;
                default:
                    printf("Unknown operator: %s\n",token);
                    exit(EXIT_FAILURE);
            }
        }
        token=strtok(NULL," ");
    }

    return pop(&stack); 
}

int main(){
    char expression[100];
    
    printf("Enter a postfix expression: ");
    fgets(expression,sizeof(expression),stdin);
    
  
    expression[strcspn(expression,"\n")]=0;

    int result=evaluatePostfix(expression);
    printf("Result of postfix expression '%s': %d\n",expression,result);
}


Scenario-2:Consider a code editor that highlights syntax errors in programming 
languages. One common error is mismatched parentheses, brackets, or braces.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct{
    char items[MAX];
    int top;
}Stack;
void initStack(Stack *s){
    s->top=-1;
}
int isEmpty(Stack *s){
    return s->top==-1;
}
void push(Stack *s,char item){
    if (s->top< MAX - 1){
        s->items[++(s->top)]=item;
    }
}
char pop(Stack *s){
    if (!isEmpty(s)){
        return s->items[(s->top)--];
    }
    return '\0'; 
}
int isMatchingPair(char opening, char closing){
    if (opening=='(' && closing==')') return 1;
    if (opening=='{' && closing=='}') return 1;
    if (opening=='[' && closing==']') return 1;
    return 0;
}

void checkBalancedDelimiters(const char *code){
    Stack s;
    initStack(&s);

    for (int i=0; i< strlen(code); i++){
        char ch=code[i];

        if (ch=='(' || ch=='{' || ch=='['){
            push(&s, ch);
        }
        else if (ch==')' || ch=='}' || ch==']'){
            if (isEmpty(&s) || !isMatchingPair(pop(&s), ch)){
                printf("Syntax error: unmatched closing bracket '%c' at position %d\n", ch, i);
                return;
            }
        }
    }
    if (!isEmpty(&s)){
        printf("Syntax error: unmatched opening bracket '%c'\n", s.items[s.top]);
    } else{
        printf("All delimiters are balanced.\n");
    }
}

int main(){
    char code[MAX];
    printf("Enter your code: %s\n",code);
    fgets(code, MAX, stdin);
    code[strcspn(code, "\n")]='\0';
    checkBalancedDelimiters(code);
    
}


Scenario-3:A text processing application that allows users to reverse strings 
for various purposes, such as creating palindromes or simply reversing text for fun.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct{
    char items[MAX];
    int top;
} Stack;
void initStack(Stack *s){
    s->top=-1;
}
int isEmpty(Stack *s){
    return s->top==-1;
}
void push(Stack *s,char item){
    if (s->top< MAX-1){
        s->items[++(s->top)]=item;
    }
}
char pop(Stack *s){
    if (!isEmpty(s)){
        return s->items[(s->top)--];
    }
    return '\0'; 
}
void reverseString(const char *str){
    Stack s;
    initStack(&s);
    
    for (int i=0; i< strlen(str); i++){
        push(&s,str[i]);
    }
    printf("Reversed string: ");
    while (!isEmpty(&s)){
        printf("%c",pop(&s));
    }
    printf("\n");
}
int main(){
    char input[MAX];
    printf("Enter a string: %s\n",input);
    fgets(input,MAX,stdin);
    input[strcspn(input,"\n")]='\0';
    reverseString(input);
    return 0;
}
