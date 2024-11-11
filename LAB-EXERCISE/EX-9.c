Scenario 1: A navigation system for delivery trucks needs to calculate the shortest path between
various locations in a city. The locations and distances are represented as a graph, and the system must
dynamically handle updates as new routes are added or removed.

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

void addRoute(int src, int dest, int distance) {
    graph[src][dest] = distance;
    graph[dest][src] = distance;
}

int findMinDistance(int dist[], int visited[]) {
    int min = INT_MAX, minIndex = -1;
    for (int i = 0; i < locations; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int src, int dest) {
    int dist[MAX_LOCATIONS], visited[MAX_LOCATIONS];
    for (int i = 0; i < locations; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < locations - 1; count++) {
        int u = findMinDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < locations; v++) {
            if (!visited[v] && graph[u][v] != INT_MAX && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    if (dist[dest] == INT_MAX) {
        printf("No path exists between location %d and location %d\n", src, dest);
    } else {
        printf("Shortest path from %d to %d is %d\n", src, dest, dist[dest]);
    }
}

int main() {
    int choice, src, dest, distance;

    while (1) {
        printf("\n1. Add Location\n2. Add Route\n3. Find Shortest Path\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addLocation();
            printf("Location %d added.\n", locations - 1);
        } else if (choice == 2) {
            printf("Enter source location: ");
            scanf("%d", &src);
            printf("Enter destination location: ");
            scanf("%d", &dest);
            printf("Enter distance: ");
            scanf("%d", &distance);
            addRoute(src, dest, distance);
        } else if (choice == 3) {
            printf("Enter source location: ");
            scanf("%d", &src);
            printf("Enter destination location: ");
            scanf("%d", &dest);
            dijkstra(src, dest);
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}



Scenario 2: A game character needs to find the shortest path from its current position to a goal
location on a grid. The game uses pointers to represent the grid dynamically, and the algorithm should
consider obstacles along the path.


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    int distance;
} QueueNode;

int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int isValid(int **grid, int rows, int cols, int visited[rows][cols], int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 0 && !visited[x][y];
}

int bfs(int **grid, int rows, int cols, Point start, Point goal) {
    int visited[rows][cols];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            visited[i][j] = 0;

    QueueNode queue[rows * cols];
    int front = 0, rear = 0;
    queue[rear++] = (QueueNode){start, 0};
    visited[start.x][start.y] = 1;

    while (front < rear) {
        QueueNode node = queue[front++];
        if (node.point.x == goal.x && node.point.y == goal.y)
            return node.distance;

        for (int i = 0; i < 4; i++) {
            int newX = node.point.x + directions[i][0];
            int newY = node.point.y + directions[i][1];
            if (isValid(grid, rows, cols, visited, newX, newY)) {
                visited[newX][newY] = 1;
                queue[rear++] = (QueueNode){{newX, newY}, node.distance + 1};
            }
        }
    }
    return -1;
}

int main() {
    int rows, cols, startX, startY, goalX, goalY;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int **grid = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        grid[i] = (int *)malloc(cols * sizeof(int));

    printf("Enter grid (0 for open path, 1 for obstacle):\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &grid[i][j]);

    printf("Enter start coordinates (x y): ");
    scanf("%d %d", &startX, &startY);

    printf("Enter goal coordinates (x y): ");
    scanf("%d %d", &goalX, &goalY);

    Point start = {startX, startY};
    Point goal = {goalX, goalY};

    int result = bfs(grid, rows, cols, start, goal);
    if (result != -1)
        printf("Shortest path length is %d\n", result);
    else
        printf("No path exists\n");

    for (int i = 0; i < rows; i++)
        free(grid[i]);
    free(grid);

    return 0;
}




Scenario 3: A logistics company needs to calculate the shortest route for a fleet of trucks to travel
between multiple warehouses and client locations. The routes are represented as a weighted graph, and
the program should allow dynamic updates as new destinations are added.


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

void addRoute(int src, int dest, int distance) {
    graph[src][dest] = distance;
    graph[dest][src] = distance;
}

int findMinDistance(int dist[], int visited[]) {
    int min = INT_MAX, minIndex = -1;
    for (int i = 0; i < locations; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int src) {
    int dist[MAX_LOCATIONS], visited[MAX_LOCATIONS];
    for (int i = 0; i < locations; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < locations - 1; count++) {
        int u = findMinDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < locations; v++) {
            if (!visited[v] && graph[u][v] != INT_MAX && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 0; i < locations; i++) {
        if (dist[i] == INT_MAX) {
            printf("No path from %d to %d\n", src, i);
        } else {
            printf("Shortest path from %d to %d is %d\n", src, i, dist[i]);
        }
    }
}

int main() {
    int choice, src, dest, distance;

    while (1) {
        printf("\n1. Add Location\n2. Add Route\n3. Find Shortest Routes from Source\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addLocation();
            printf("Location %d added.\n", locations - 1);
        } else if (choice == 2) {
            printf("Enter source location: ");
            scanf("%d", &src);
            printf("Enter destination location: ");
            scanf("%d", &dest);
            printf("Enter distance: ");
            scanf("%d", &distance);
            addRoute(src, dest, distance);
        } else if (choice == 3) {
            printf("Enter source location: ");
            scanf("%d", &src);
            dijkstra(src);
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
