Scenario 1: A city is planning to lay down new roads between various locations. The goal is to
minimize the construction costs by ensuring the minimum amount of road is built while still connecting
all locations. The road network is represented as a graph.


  #include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_LOCATIONS 100

int graph[MAX_LOCATIONS][MAX_LOCATIONS];
int locations = 0;

void addLocation() {
    locations++;
    for (int i = 0; i < locations; i++) {
        graph[i][locations - 1] = INT_MAX;
        graph[locations - 1][i] = INT_MAX;
    }
}

void addRoad(int src, int dest, int cost) {
    graph[src][dest] = cost;
    graph[dest][src] = cost;
}

int findMinKey(int key[], int inMST[]) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < locations; v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST() {
    int parent[MAX_LOCATIONS];
    int key[MAX_LOCATIONS];
    int inMST[MAX_LOCATIONS];

    for (int i = 0; i < locations; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < locations - 1; count++) {
        int u = findMinKey(key, inMST);
        inMST[u] = 1;

        for (int v = 0; v < locations; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalCost = 0;
    printf("Roads included in the minimum cost network:\n");
    for (int i = 1; i < locations; i++) {
        if (parent[i] != -1) {
            printf("Road from %d to %d with cost %d\n", parent[i], i, graph[i][parent[i]]);
            totalCost += graph[i][parent[i]];
        }
    }
    printf("Total construction cost: %d\n", totalCost);
}

int main() {
    int choice, src, dest, cost;

    while (1) {
        printf("\n1. Add Location\n2. Add Road\n3. Find Minimum Construction Cost\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addLocation();
            printf("Location %d added.\n", locations - 1);
        } else if (choice == 2) {
            printf("Enter source location: ");
            scanf("%d", &src);
            printf("Enter destination location: ");
            scanf("%d", &dest);
            printf("Enter cost: ");
            scanf("%d", &cost);
            addRoad(src, dest, cost);
        } else if (choice == 3) {
            if (locations < 2) {
                printf("Need at least two locations to calculate minimum construction cost.\n");
            } else {
                primMST();
            }
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}



Scenario 2: A network engineer is tasked with setting up cables between multiple offices within a
building, aiming to minimize the total length of cable used. The office locations are modeled as a graph,
and the engineer needs to implement a minimum spanning tree algorithm.

  #include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_OFFICES 100

int graph[MAX_OFFICES][MAX_OFFICES];
int offices = 0;

void addOffice() {
    offices++;
    for (int i = 0; i < offices; i++) {
        graph[i][offices - 1] = INT_MAX;
        graph[offices - 1][i] = INT_MAX;
    }
}

void addCable(int src, int dest, int length) {
    graph[src][dest] = length;
    graph[dest][src] = length;
}

int findMinKey(int key[], int inMST[]) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < offices; v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST() {
    int parent[MAX_OFFICES];
    int key[MAX_OFFICES];
    int inMST[MAX_OFFICES];

    for (int i = 0; i < offices; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < offices - 1; count++) {
        int u = findMinKey(key, inMST);
        inMST[u] = 1;

        for (int v = 0; v < offices; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalCableLength = 0;
    printf("Cables included in the minimum cable length network:\n");
    for (int i = 1; i < offices; i++) {
        if (parent[i] != -1) {
            printf("Cable from Office %d to Office %d with length %d meters\n", parent[i], i, graph[i][parent[i]]);
            totalCableLength += graph[i][parent[i]];
        }
    }
    printf("Total cable length used: %d meters\n", totalCableLength);
}

int main() {
    int choice, src, dest, length;

    while (1) {
        printf("\n1. Add Office\n2. Add Cable\n3. Find Minimum Cable Length\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addOffice();
            printf("Office %d added.\n", offices - 1);
        } else if (choice == 2) {
            printf("Enter source office: ");
            scanf("%d", &src);
            printf("Enter destination office: ");
            scanf("%d", &dest);
            printf("Enter cable length (in meters): ");
            scanf("%d", &length);
            addCable(src, dest, length);
        } else if (choice == 3) {
            if (offices < 2) {
                printf("Need at least two offices to calculate minimum cable length.\n");
            } else {
                primMST();
            }
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}



Scenario 3: An electricity provider needs to set up power lines to connect multiple towns in a region.
The goal is to minimize the total cost of laying down the power lines while ensuring all towns are
connected. The towns and distances between them are represented as a graph, and the program should
dynamically handle updates to the network.


  #include <stdio.h>
#include <stdlib.h>

#define MAX_TOWNS 100

typedef struct {
    int src, dest, cost;
} Edge;

int parent[MAX_TOWNS];
int rank[MAX_TOWNS];

Edge edges[MAX_TOWNS * (MAX_TOWNS - 1) / 2];
int edgeCount = 0;
int towns = 0;

void addTown() {
    towns++;
}

int find(int i) {
    if (parent[i] == -1) {
        return i;
    }
    return find(parent[i]);
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

void addPowerLine(int src, int dest, int cost) {
    edges[edgeCount].src = src;
    edges[edgeCount].dest = dest;
    edges[edgeCount].cost = cost;
    edgeCount++;
}

int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->cost - ((Edge *)b)->cost;
}

void kruskalMST() {
    for (int i = 0; i < towns; i++) {
        parent[i] = -1;
        rank[i] = 0;
    }

    qsort(edges, edgeCount, sizeof(Edge), compareEdges);

    int totalCost = 0;
    printf("Power lines included in the minimum cost network:\n");

    for (int i = 0; i < edgeCount; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int cost = edges[i].cost;

        int rootSrc = find(src);
        int rootDest = find(dest);

        if (rootSrc != rootDest) {
            unionSets(rootSrc, rootDest);
            printf("Power line from Town %d to Town %d with cost %d\n", src, dest, cost);
            totalCost += cost;
        }
    }

    printf("Total power line cost: %d\n", totalCost);
}

int main() {
    int choice, src, dest, cost;

    while (1) {
        printf("\n1. Add Town\n2. Add Power Line\n3. Find Minimum Cost for Power Lines\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addTown();
            printf("Town %d added.\n", towns - 1);
        } else if (choice == 2) {
            printf("Enter source town: ");
            scanf("%d", &src);
            printf("Enter destination town: ");
            scanf("%d", &dest);
            printf("Enter power line cost: ");
            scanf("%d", &cost);
            addPowerLine(src, dest, cost);
        } else if (choice == 3) {
            if (towns < 2) {
                printf("Need at least two towns to calculate minimum cost.\n");
            } else {
                kruskalMST();
            }
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
