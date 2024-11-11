Scenario 1: A password manager stores user credentials and needs to quickly check if a username
already exists before allowing a new user to register. The system uses a hash table to store usernames.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 100

typedef struct Node {
    char username[50];
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

unsigned int hashFunction(const char* username) {
    unsigned int hash = 0;
    for (int i = 0; username[i] != '\0'; i++) {
        hash = (hash * 31 + username[i]) % TABLE_SIZE;
    }
    return hash;
}

void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

int searchUsername(const char* username) {
    unsigned int index = hashFunction(username);
    Node* temp = hashTable[index];
    while (temp != NULL) {
        if (strcmp(temp->username, username) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void insertUsername(const char* username) {
    if (searchUsername(username)) {
        printf("Username '%s' already exists.\n", username);
        return;
    }
    unsigned int index = hashFunction(username);
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->username, username);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
    printf("Username '%s' registered successfully.\n", username);
}

int main() {
    initializeTable();
    int choice;
    char username[50];
    do {
        printf("1. Register Username\n2. Check Username\n3. Exit\nChoose an option: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter username to register: ");
            scanf("%s", username);
            insertUsername(username);
        } else if (choice == 2) {
            printf("Enter username to check: ");
            scanf("%s", username);
            if (searchUsername(username)) {
                printf("Username '%s' exists.\n", username);
            } else {
                printf("Username '%s' is available.\n", username);
            }
        }
    } while (choice != 3);
    return 0;
}


Scenario 2: An e-commerce platform uses hashing to store and retrieve product IDs for fast lookups.
The system uses dynamic memory allocation to handle varying numbers of products, allowing quick
access by product ID.

  #include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100

typedef struct ProductNode {
    int productID;
    struct ProductNode* next;
} ProductNode;

ProductNode* hashTable[TABLE_SIZE];

unsigned int hashFunction(int productID) {
    return productID % TABLE_SIZE;
}

void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

int searchProduct(int productID) {
    unsigned int index = hashFunction(productID);
    ProductNode* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->productID == productID) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void insertProduct(int productID) {
    if (searchProduct(productID)) {
        printf("Product ID %d already exists.\n", productID);
        return;
    }
    unsigned int index = hashFunction(productID);
    ProductNode* newNode = (ProductNode*)malloc(sizeof(ProductNode));
    newNode->productID = productID;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
    printf("Product ID %d inserted successfully.\n", productID);
}

int main() {
    initializeTable();
    int choice, productID;
    do {
        printf("1. Insert Product ID\n2. Check Product ID\n3. Exit\nChoose an option: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter Product ID to insert: ");
            scanf("%d", &productID);
            insertProduct(productID);
        } else if (choice == 2) {
            printf("Enter Product ID to check: ");
            scanf("%d", &productID);
            if (searchProduct(productID)) {
                printf("Product ID %d exists.\n", productID);
            } else {
                printf("Product ID %d is not found.\n", productID);
            }
        }
    } while (choice != 3);
    return 0;
}


Scenario-3:

  #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Article {
    char title[100];
    char content[1000];
    struct Article* next;
} Article;

Article* hashTable[TABLE_SIZE];

unsigned int hash(const char* title) {
    unsigned int hashValue = 0;
    for (int i = 0; title[i] != '\0'; i++) {
        hashValue = (hashValue * 31 + title[i]) % TABLE_SIZE;
    }
    return hashValue;
}

void insertArticle(const char* title, const char* content) {
    unsigned int index = hash(title);
    Article* newArticle = (Article*)malloc(sizeof(Article));
    strcpy(newArticle->title, title);
    strcpy(newArticle->content, content);
    newArticle->next = hashTable[index];
    hashTable[index] = newArticle;
}

Article* searchArticle(const char* title) {
    unsigned int index = hash(title);
    Article* current = hashTable[index];
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    int choice;
    char title[100];
    char content[1000];
    while (1) {
        printf("\n1. Insert Article\n2. Search Article\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar();
        if (choice == 1) {
            printf("Enter article title: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0;
            printf("Enter article content: ");
            fgets(content, sizeof(content), stdin);
            content[strcspn(content, "\n")] = 0;
            insertArticle(title, content);
        } else if (choice == 2) {
            printf("Enter article title to search: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0;
            Article* article = searchArticle(title);
            if (article != NULL) {
                printf("Content: %s\n", article->content);
            } else {
                printf("Article not found\n");
            }
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}

