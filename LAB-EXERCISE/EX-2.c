//SCENARIO-1:

#include <stdio.h>
#include <string.h>

#define MAX_HISTORY 100
#define URL_LENGTH 100

char history[MAX_HISTORY][URL_LENGTH];
int top = -1;

void pushHistory(char url[]) {
    if (top < MAX_HISTORY - 1) {
        top++;
        strcpy(history[top], url);
    } else {
        printf("History is full!\n");
    }
}

void popHistory() {
    if (top == -1) {
        printf("No history to pop.\n");
    } else {
        printf("Popped URL: %s\n", history[top]);
        top--;
    }
}

void displayHistory() {
    if (top == -1) {
        printf("No history to display.\n");
    } else {
        printf("Browser History:\n");
        for (int i = 0; i <= top; i++) {
            printf("%s\n", history[i]);
        }
    }
}

int main() {
    pushHistory("www.google.com");
    pushHistory("www.example.com");
    displayHistory();
    popHistory();
    displayHistory();
    return 0;
}


//SCENARIO-2:

#include <stdio.h>
#include <string.h>

#define MAX_CHANGES 100
#define TEXT_LENGTH 100

char changes[MAX_CHANGES][TEXT_LENGTH];
int top = -1;

void pushChange(char change[]) {
    if (top < MAX_CHANGES - 1) {
        top++;
        strcpy(changes[top], change);
    } else {
        printf("Change history is full!\n");
    }
}

void undoChange() {
    if (top == -1) {
        printf("No changes to undo.\n");
    } else {
        printf("Undo change: %s\n", changes[top]);
        top--;
    }
}

void displayChanges() {
    if (top == -1) {
        printf("No changes to display.\n");
    } else {
        printf("Text changes history:\n");
        for (int i = 0; i <= top; i++) {
            printf("%s\n", changes[i]);
        }
    }
}

int main() {
    pushChange("Added text: Hello");
    pushChange("Deleted text: World");
    displayChanges();
    undoChange();
    displayChanges();
    return 0;
}


//SCENARIO-3:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR 100

char stack[MAX_EXPR];
int top = -1;

int precedence(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    }
    if (operator == '*' || operator == '/') {
        return 2;
    }
    return 0;
}

void push(char operator) {
    if (top < MAX_EXPR - 1) {
        stack[++top] = operator;
    } else {
        printf("Stack overflow.\n");
    }
}

char pop() {
    if (top == -1) {
        return -1;
    }
    return stack[top--];
}

void infixToPostfix(char *expr) {
    char result[MAX_EXPR];
    int k = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        if (isalnum(c)) {
            result[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                result[k++] = pop();
            }
            pop(); // Pop '('
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                result[k++] = pop();
            }
            push(c);
        }
    }

    while (top != -1) {
        result[k++] = pop();
    }
    result[k] = '\0';
    printf("Postfix: %s\n", result);
}

int main() {
    char expr[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(expr);
    return 0;
}


//SCENARIO-4:

#include <stdio.h>
#include <stdlib.h>

typedef struct Move {
    int x, y;
    struct Move *next;
} Move;

Move *top = NULL;

void pushMove(int x, int y) {
    Move *newMove = (Move *)malloc(sizeof(Move));
    newMove->x = x;
    newMove->y = y;
    newMove->next = top;
    top = newMove;
}

void popMove() {
    if (top == NULL) {
        printf("No moves to pop.\n");
        return;
    }
    printf("Popped move: (%d, %d)\n", top->x, top->y);
    Move *temp = top;
    top = top->next;
    free(temp);
}

void displayMoves() {
    if (top == NULL) {
        printf("No moves to display.\n");
        return;
    }
    Move *current = top;
    while (current != NULL) {
        printf("Move: (%d, %d)\n", current->x, current->y);
        current = current->next;
    }
}

int main() {
    pushMove(1, 1);
    pushMove(2, 2);
    displayMoves();
    popMove();
    displayMoves();
    return 0;
}


//SCENARIO-5:

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;

Node *top = NULL;

void push(char ch) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = ch;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (top == NULL) {
        return -1;
    }
    char ch = top->data;
    Node *temp = top;
    top = top->next;
    free(temp);
    return ch;
}

int isBalanced(char *expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            char topCh = pop();
            if ((ch == ')' && topCh != '(') ||
                (ch == '}' && topCh != '{') ||
                (ch == ']' && topCh != '[')) {
                return 0; // Unbalanced
            }
        }
    }

    return top == NULL; // If stack is empty, it's balanced
}

int main() {
    char expr[] = "{[()]}";
    if (isBalanced(expr)) {
        printf("Balanced parentheses\n");
    } else {
        printf("Unbalanced parentheses\n");
    }
    return 0;
}



//SCENARIO-6:


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;

Node *top = NULL;

void push(char ch) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = ch;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (top == NULL) {
        return -1;
    }
    char ch = top->data;
    Node *temp = top;
    top = top->next;
    free(temp);
    return ch;
}

int isValidSyntax(char *expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            char topCh = pop();
            if ((ch == ')' && topCh != '(') ||
                (ch == '}' && topCh != '{') ||
                (ch == ']' && topCh != '[')) {
                return 0; // Invalid syntax
            }
        }
    }

    return top == NULL; // If stack is empty, syntax is valid
}

int main() {
    char expr[] = "int main() { if (x == 10) { return 1; } }";
    if (isValidSyntax(expr)) {
        printf("Valid syntax\n");
    } else {
        printf("Invalid syntax\n");
    }
    return 0;
}
