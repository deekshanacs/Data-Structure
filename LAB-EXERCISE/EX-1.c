//Scenario-1:

#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

Contact contacts[MAX_CONTACTS];
int contactCount = 0;

void addContact(char name[], char phone[]) {
    if (contactCount < MAX_CONTACTS) {
        strcpy(contacts[contactCount].name, name);
        strcpy(contacts[contactCount].phone, phone);
        contactCount++;
    } else {
        printf("Contact list is full!\n");
    }
}

void deleteContact(char name[]) {
    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < contactCount - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            contactCount--;
            found = 1;
            printf("Contact deleted.\n");
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void displayContacts() {
    if (contactCount == 0) {
        printf("No contacts to display.\n");
    } else {
        for (int i = 0; i < contactCount; i++) {
            printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
        }
    }
}

int main() {
    addContact("Alice", "123-456-7890");
    addContact("Bob", "234-567-8901");
    displayContacts();
    deleteContact("Alice");
    displayContacts();
    return 0;
}


//Scenario-2:

#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_LENGTH 50

char shoppingList[MAX_ITEMS][ITEM_LENGTH];
int itemCount = 0;

void addItem(char item[]) {
    if (itemCount < MAX_ITEMS) {
        strcpy(shoppingList[itemCount], item);
        itemCount++;
    } else {
        printf("Shopping list is full!\n");
    }
}

void removeItem(char item[]) {
    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(shoppingList[i], item) == 0) {
            for (int j = i; j < itemCount - 1; j++) {
                strcpy(shoppingList[j], shoppingList[j + 1]);
            }
            itemCount--;
            found = 1;
            printf("Item removed.\n");
            break;
        }
    }
    if (!found) {
        printf("Item not found.\n");
    }
}

void displayList() {
    if (itemCount == 0) {
        printf("Shopping list is empty.\n");
    } else {
        for (int i = 0; i < itemCount; i++) {
            printf("%s\n", shoppingList[i]);
        }
    }
}

int main() {
    addItem("Milk");
    addItem("Bread");
    displayList();
    removeItem("Milk");
    displayList();
    return 0;
}



//Scenario-3:

  
#include <stdio.h>
#define MAX_GRADES 100

int grades[MAX_GRADES];
int gradeCount = 0;

void addGrade(int grade) {
    if (gradeCount < MAX_GRADES) {
        grades[gradeCount++] = grade;
    } else {
        printf("Grade list is full!\n");
    }
}

void displayGrades() {
    if (gradeCount == 0) {
        printf("No grades to display.\n");
    } else {
        for (int i = 0; i < gradeCount; i++) {
            printf("%d ", grades[i]);
        }
        printf("\n");
    }
}

double calculateAverage() {
    if (gradeCount == 0) return 0.0;
    int sum = 0;
    for (int i = 0; i < gradeCount; i++) {
        sum += grades[i];
    }
    return (double)sum / gradeCount;
}

int main() {
    addGrade(85);
    addGrade(90);
    addGrade(78);
    displayGrades();
    printf("Average grade: %.2f\n", calculateAverage());
    return 0;
}


//Scenario-4:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    char name[50];
    struct Task *next;
} Task;

Task *head = NULL;

void addTask(char *name) {
    Task *newTask = (Task *)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->next = head;
    head = newTask;
}

void removeTask() {
    if (head == NULL) {
        printf("No tasks to remove.\n");
        return;
    }

    Task *current = head;
    Task *prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    if (prev != NULL) {
        prev->next = NULL;
    } else {
        head = NULL;
    }

    free(current);
    printf("Task removed from the end.\n");
}

void displayTasks() {
    if (head == NULL) {
        printf("No tasks to display.\n");
        return;
    }

    Task *current = head;
    while (current != NULL) {
        printf("Task: %s\n", current->name);
        current = current->next;
    }
}

int main() {
    addTask("Finish report");
    addTask("Submit assignment");
    displayTasks();
    removeTask();
    displayTasks();
    return 0;
}



//Scenario-5:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char title[50];
    struct Song *next;
} Song;

Song *head = NULL;

void addSong(char *title) {
    Song *newSong = (Song *)malloc(sizeof(Song));
    strcpy(newSong->title, title);
    newSong->next = NULL;

    if (head == NULL) {
        head = newSong;
    } else {
        Song *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newSong;
    }
}

void removeSong(char *title) {
    Song *current = head;
    Song *prev = NULL;

    while (current != NULL && strcmp(current->title, title) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Song not found.\n");
        return;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Song removed.\n");
}

void displayPlaylist() {
    Song *current = head;
    if (current == NULL) {
        printf("Playlist is empty.\n");
    } else {
        while (current != NULL) {
            printf("Song: %s\n", current->title);
            current = current->next;
        }
    }
}

int main() {
    addSong("Song A");
    addSong("Song B");
    displayPlaylist();
    removeSong("Song A");
    displayPlaylist();
    return 0;
}



//Scenario-6:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char title[50];
    struct Book *prev;
    struct Book *next;
} Book;

Book *head = NULL;
Book *tail = NULL;

void addBook(char *title) {
    Book *newBook = (Book *)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    newBook->prev = tail;
    newBook->next = NULL;

    if (tail == NULL) {
        head = newBook;
    } else {
        tail->next = newBook;
    }
    tail = newBook;
}

void removeBook(char *title) {
    Book *current = head;

    while (current != NULL && strcmp(current->title, title) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Book not found.\n");
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        tail = current->prev;
    }

    free(current);
    printf("Book removed.\n");
}

void displayBooks() {
    Book *current = head;
    if (current == NULL) {
        printf("No books to display.\n");
    } else {
        printf("Books in forward order:\n");
        while (current != NULL) {
            printf("%s\n", current->title);
            current = current->next;
        }
    }
}

void displayBooksReverse() {
    Book *current = tail;
    if (current == NULL) {
        printf("No books to display.\n");
    } else {
        printf("Books in reverse order:\n");
        while (current != NULL) {
            printf("%s\n", current->title);
            current = current->prev;
        }
    }
}

int main() {
    addBook("The Great Gatsby");
    addBook("1984");
    addBook("To Kill a Mockingbird");

    displayBooks();
    displayBooksReverse();

    removeBook("1984");
    displayBooks();

    return 0;
}
