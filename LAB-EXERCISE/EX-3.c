//SCENARIO-1:

#include <stdio.h>
#include <string.h>

#define MAX_JOBS 10
#define JOB_NAME_LENGTH 50

typedef struct {
    char jobName[JOB_NAME_LENGTH];
} PrintJob;

PrintJob queue[MAX_JOBS];
int front = -1, rear = -1;

void enqueueJob(char job[]) {
    if (rear == MAX_JOBS - 1) {
        printf("Queue is full! Cannot enqueue more jobs.\n");
    } else {
        if (front == -1) {
            front = 0;  // First job
        }
        rear++;
        strcpy(queue[rear].jobName, job);
        printf("Job '%s' added to the print queue.\n", job);
    }
}

void dequeueJob() {
    if (front == -1) {
        printf("Queue is empty! No jobs to dequeue.\n");
    } else {
        printf("Job '%s' is being printed.\n", queue[front].jobName);
        for (int i = front; i < rear; i++) {
            queue[i] = queue[i + 1];
        }
        rear--;
        if (rear == -1) {
            front = -1;  // Queue is now empty
        }
    }
}

void displayQueue() {
    if (front == -1) {
        printf("No jobs in the print queue.\n");
    } else {
        printf("Current print queue:\n");
        for (int i = front; i <= rear; i++) {
            printf("%s\n", queue[i].jobName);
        }
    }
}

int main() {
    enqueueJob("Job 1");
    enqueueJob("Job 2");
    displayQueue();
    dequeueJob();
    displayQueue();
    return 0;
}



//SCENARIO-2:
#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 10
#define NAME_LENGTH 50

typedef struct {
    char customerName[NAME_LENGTH];
} Customer;

Customer queue[MAX_CUSTOMERS];
int front = -1, rear = -1;

void addCustomer(char name[]) {
    if (rear == MAX_CUSTOMERS - 1) {
        printf("Queue is full! Cannot add more customers.\n");
    } else {
        if (front == -1) {
            front = 0;  // First customer
        }
        rear++;
        strcpy(queue[rear].customerName, name);
        printf("Customer '%s' added to the queue.\n", name);
    }
}

void serveCustomer() {
    if (front == -1) {
        printf("Queue is empty! No customers to serve.\n");
    } else {
        printf("Serving customer '%s'.\n", queue[front].customerName);
        for (int i = front; i < rear; i++) {
            queue[i] = queue[i + 1];
        }
        rear--;
        if (rear == -1) {
            front = -1;  // Queue is now empty
        }
    }
}

void displayQueue() {
    if (front == -1) {
        printf("No customers in the queue.\n");
    } else {
        printf("Current customer queue:\n");
        for (int i = front; i <= rear; i++) {
            printf("%s\n", queue[i].customerName);
        }
    }
}

int main() {
    addCustomer("Alice");
    addCustomer("Bob");
    displayQueue();
    serveCustomer();
    displayQueue();
    return 0;
}


//SCENARIO-3:

#include <stdio.h>
#include <string.h>

#define MAX_CALLS 10
#define CALLER_NAME_LENGTH 50

typedef struct {
    char callerName[CALLER_NAME_LENGTH];
} Call;

Call queue[MAX_CALLS];
int front = -1, rear = -1;

void enqueueCall(char name[]) {
    if (rear == MAX_CALLS - 1) {
        printf("Call queue is full! Cannot accept more calls.\n");
    } else {
        if (front == -1) {
            front = 0;  // First call
        }
        rear++;
        strcpy(queue[rear].callerName, name);
        printf("Call from '%s' added to the queue.\n", name);
    }
}

void dequeueCall() {
    if (front == -1) {
        printf("No calls in the queue.\n");
    } else {
        printf("Handling call from '%s'.\n", queue[front].callerName);
        for (int i = front; i < rear; i++) {
            queue[i] = queue[i + 1];
        }
        rear--;
        if (rear == -1) {
            front = -1;  // Queue is now empty
        }
    }
}

void displayQueue() {
    if (front == -1) {
        printf("No calls in the queue.\n");
    } else {
        printf("Current call queue:\n");
        for (int i = front; i <= rear; i++) {
            printf("%s\n", queue[i].callerName);
        }
    }
}

int main() {
    enqueueCall("John");
    enqueueCall("Mary");
    displayQueue();
    dequeueCall();
    displayQueue();
    return 0;
}

//SCENARIO-4:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Inquiry {
    char customerName[50];
    struct Inquiry *next;
} Inquiry;

Inquiry *front = NULL, *rear = NULL;

void addInquiry(char name[]) {
    Inquiry *newInquiry = (Inquiry *)malloc(sizeof(Inquiry));
    strcpy(newInquiry->customerName, name);
    newInquiry->next = NULL;
    if (rear == NULL) {
        front = rear = newInquiry;
    } else {
        rear->next = newInquiry;
        rear = newInquiry;
    }
    printf("Inquiry from '%s' added to the queue.\n", name);
}

void resolveInquiry() {
    if (front == NULL) {
        printf("No inquiries to resolve.\n");
    } else {
        Inquiry *temp = front;
        printf("Resolving inquiry from '%s'.\n", front->customerName);
        front = front->next;
        if (front == NULL) {
            rear = NULL;  // Queue is now empty
        }
        free(temp);
    }
}

void displayInquiries() {
    if (front == NULL) {
        printf("No inquiries in the queue.\n");
    } else {
        printf("Current inquiries in the queue:\n");
        Inquiry *temp = front;
        while (temp != NULL) {
            printf("%s\n", temp->customerName);
            temp = temp->next;
        }
    }
}

int main() {
    addInquiry("Alice");
    addInquiry("Bob");
    displayInquiries();
    resolveInquiry();
    displayInquiries();
    return 0;
}


//SCENARIO-5:


#include <stdio.h>
#include <stdlib.h>

typedef struct Customer {
    int customerId;
    struct Customer *next;
} Customer;

Customer *front = NULL, *rear = NULL;

void enqueueCustomer(int customerId) {
    Customer *newCustomer = (Customer *)malloc(sizeof(Customer));
    newCustomer->customerId = customerId;
    newCustomer->next = NULL;
    if (rear == NULL) {
        front = rear = newCustomer;
    } else {
        rear->next = newCustomer;
        rear = newCustomer;
    }
    printf("Customer %d added to the queue.\n", customerId);
}

void dequeueCustomer() {
    if (front == NULL) {
        printf("No customers in the queue.\n");
    } else {
        Customer *temp = front;
        printf("Serving customer %d.\n", front->customerId);
        front = front->next;
        if (front == NULL) {
            rear = NULL;  // Queue is now empty
        }
        free(temp);
    }
}

void displayQueue() {
    if (front == NULL) {
        printf("No customers in the queue.\n");
    } else {
        printf("Current customer queue:\n");
        Customer *temp = front;
        while (temp != NULL) {
            printf("Customer %d\n", temp->customerId);
            temp = temp->next;
        }
    }
}

int main() {
    enqueueCustomer(101);
    enqueueCustomer(102);
    displayQueue();
    dequeueCustomer();
    displayQueue();
    return 0;
}



//SCENARIO-6:


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RideRequest {
    char riderName[50];
    struct RideRequest *next;
} RideRequest;

RideRequest *front = NULL, *rear = NULL;

void addRideRequest(char name[]) {
    RideRequest *newRequest = (RideRequest *)malloc(sizeof(RideRequest));
    strcpy(newRequest->riderName, name);
    newRequest->next = NULL;
    if (rear == NULL) {
        front = rear = newRequest;
    } else {
        rear->next = newRequest;
        rear = newRequest;
    }
    printf("Ride request from '%s' added to the queue.\n", name);
}

void serveRideRequest() {
    if (front == NULL) {
        printf("No ride requests in the queue.\n");
    } else {
        RideRequest *temp = front;
        printf("Serving ride request from '%s'.\n", front->riderName);
        front = front->next;
        if (front == NULL) {
            rear = NULL;  // Queue is now empty
        }
        free(temp);
    }
}

void displayRideRequests() {
    if (front == NULL) {
        printf("No ride requests in the queue.\n");
    } else {
        printf("Current ride requests in the queue:\n");
        RideRequest *temp = front;
        while (temp != NULL) {
            printf("%s\n", temp->riderName);
            temp = temp->next;
        }
    }
}

int main() {
    addRideRequest("John");
    addRideRequest("Alice");
    displayRideRequests();
    serveRideRequest();
    displayRideRequests();
    return 0;
}
