A database of student records contains student IDs and their corresponding details. The
system needs to find the record of a student based on their unique student ID. The list of records is
stored in a dynamic array.



  #include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
} Student;

int main() {
    int capacity = 2, size = 0, id, age, choice, found;
    char name[50];
    Student *students = (Student*)malloc(capacity * sizeof(Student));

    while (1) {
        printf("\n1. Add Student\n2. Search Student\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (size == capacity) {
                capacity *= 2;
                students = (Student*)realloc(students, capacity * sizeof(Student));
            }
            printf("Enter ID: ");
            scanf("%d", &id);
            printf("Enter Name: ");
            scanf("%s", name);
            printf("Enter Age: ");
            scanf("%d", &age);

            students[size].id = id;
            strcpy(students[size].name, name);
            students[size].age = age;
            size++;
        } else if (choice == 2) {
            printf("Enter ID to search: ");
            scanf("%d", &id);
            found = 0;
            for (int i = 0; i < size; i++) {
                if (students[i].id == id) {
                    printf("ID: %d, Name: %s, Age: %d\n", students[i].id, students[i].name, students[i].age);
                    found = 1;
                    break;
                }
            }
            if (!found) printf("Student not found.\n");
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    free(students);
    return 0;
}



Scenario 2: A social media platform needs to search for a user by their unique username in a list of
thousands of users. The system should be designed to search through a dynamic list, optimizing
performance for large datasets.


  #include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char username[50];
    int age;
} User;

int binarySearch(User *users, int size, const char *username) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(users[mid].username, username);
        if (cmp == 0) return mid;
        if (cmp < 0) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int capacity = 2, size = 0, age, choice;
    char username[50];
    User *users = (User*)malloc(capacity * sizeof(User));

    while (1) {
        printf("\n1. Add User\n2. Search User\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (size == capacity) {
                capacity *= 2;
                users = (User*)realloc(users, capacity * sizeof(User));
            }
            printf("Enter Username: ");
            scanf("%s", username);
            printf("Enter Age: ");
            scanf("%d", &age);

            strcpy(users[size].username, username);
            users[size].age = age;
            size++;

            for (int i = size - 1; i > 0; i--) {
                if (strcmp(users[i - 1].username, users[i].username) > 0) {
                    User temp = users[i];
                    users[i] = users[i - 1];
                    users[i - 1] = temp;
                }
            }
        } else if (choice == 2) {
            printf("Enter Username to search: ");
            scanf("%s", username);
            int index = binarySearch(users, size, username);
            if (index != -1) {
                printf("Username: %s, Age: %d\n", users[index].username, users[index].age);
            } else {
                printf("User not found.\n");
            }
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    free(users);
    return 0;
}



Scenario 3: A telephone directory application needs to search for a specific contact’s phone number
by their name. The contact list is stored using dynamic memory allocation, and the search should be
efficient and work for any list size.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[15];
} Contact;

int binarySearch(Contact *contacts, int size, const char *name) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(contacts[mid].name, name);
        if (cmp == 0) return mid;
        if (cmp < 0) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int capacity = 2, size = 0, choice;
    char name[50], phone[15];
    Contact *contacts = (Contact*)malloc(capacity * sizeof(Contact));

    while (1) {
        printf("\n1. Add Contact\n2. Search Contact\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (size == capacity) {
                capacity *= 2;
                contacts = (Contact*)realloc(contacts, capacity * sizeof(Contact));
            }
            printf("Enter Name: ");
            scanf("%s", name);
            printf("Enter Phone: ");
            scanf("%s", phone);

            strcpy(contacts[size].name, name);
            strcpy(contacts[size].phone, phone);
            size++;

            for (int i = size - 1; i > 0; i--) {
                if (strcmp(contacts[i - 1].name, contacts[i].name) > 0) {
                    Contact temp = contacts[i];
                    contacts[i] = contacts[i - 1];
                    contacts[i - 1] = temp;
                }
            }
        } else if (choice == 2) {
            printf("Enter Name to search: ");
            scanf("%s", name);
            int index = binarySearch(contacts, size, name);
            if (index != -1) {
                printf("Name: %s, Phone: %s\n", contacts[index].name, contacts[index].phone);
            } else {
                printf("Contact not found.\n");
            }
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    free(contacts);
    return 0;
}
