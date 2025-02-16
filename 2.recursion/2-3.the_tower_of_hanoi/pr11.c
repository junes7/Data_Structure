#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int bfs(int n, int m, int **grid) {
    int front = 0, rear = 0, y, x, wall_broken, dist, ny, nx, directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool ***visited = (bool ***)malloc(sizeof(bool **) * n);
    for (int i = 0; i < n; i++) {
        visited[i] = (bool **)malloc(sizeof(bool *) * m);
        for (int j = 0; j < m; j++) {
            visited[i][j] = (bool *)malloc(sizeof(bool) * 2);
            memset(visited[i][j], false, sizeof(bool) * 2);
            // visited[i][j][0] = false;
            // visited[i][j][1] = false;
        }
    }
    int **que = (int **)malloc(sizeof(int *) * (n));
    for (int i = 0; i < n; i++)
        que[i] = (int *)malloc(sizeof(int) * 4);
    que[rear][0] = 0, que[rear][1] = 0, que[rear][2] = 0, que[rear++][3] = 1;
    visited[0][0][0] = true;
    while (front < rear) {
        y = que[front][0], x = que[front][1], wall_broken = que[front][2], dist = que[front++][3];
        printf("wall: %d %d %d %d %d %d\n", y, x, wall_broken, dist, n, m);
        if (y == n - 1 && x == m - 1)
            return dist;
        for (int i = 0; i < 4; i++) {
            ny = y + directions[i][0];
            nx = x + directions[i][1];
            if (0 <= ny && ny < n && 0 <= nx && nx < m) {
                printf("%d %d %d %d\n", ny, nx, grid[ny][nx], visited[ny][nx][wall_broken]);
                if (grid[ny][nx] == 0 && visited[ny][nx][wall_broken] == false) {
                    visited[ny][nx][wall_broken] = true;
                    que[rear][0] = ny, que[rear][1] = nx, que[rear][2] = wall_broken, que[rear++][3] = dist + 1;
                } else if (grid[ny][nx] == 1 && wall_broken == 0 && visited[ny][nx][1] == false) {
                    visited[ny][nx][1] = true;
                    que[rear][0] = ny, que[rear][1] = nx, que[rear][2] = 1, que[rear++][3] = dist + 1;
                }
            }
        }
    }
    return -1;
}
int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    char *t = (char *)malloc(sizeof(char) * (m + 1));
    int **grid = (int **)malloc(sizeof(int *) * (n));
    for (int i = 0; i < n; i++) {
        scanf("%s", t);
        grid[i] = (int *)malloc(sizeof(int) * (m));
        for (int j = 0; j < m; j++) {
            grid[i][j] = t[j] - 48;
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         printf("%d ", grid[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d", bfs(n, m, grid));
    return 0;
}
