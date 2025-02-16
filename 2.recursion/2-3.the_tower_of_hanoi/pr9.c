#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
void bfs(char **arr, int **visited, int n, int m) {
    int y, x, ny, nx, idx = 1;
    visited[0][0] = 1;
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    int **dq = (int **)malloc(sizeof(int *) * 10002);
    for (int i = 0; i < n; i++) {
        dq[i] = (int *)malloc(sizeof(int) * 2);
        for (int j = 0; j < 2; j++)
            dq[i][j] = 0;
    }
    while (idx > 0) {
        y = dq[0][0], x = dq[0][1];
        for (int i = 1; i < idx; i++) {
            dq[i - 1][0] = dq[i][0];
            dq[i - 1][1] = dq[i][1];
        }
        idx--;
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if (0 <= ny && ny < n && 0 <= nx && nx < m) {
                if (visited[ny][nx] == -1 && arr[ny][nx] == '1') {
                    visited[ny][nx] = visited[y][x] + 1;
                    dq[idx][0] = ny;
                    dq[idx++][1] = nx;
                }
            }
        }
    }
}
int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    char **arr = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = (char *)malloc(sizeof(char) * (m + 1));
        scanf("%s", arr[i]);
    }
    int **visited = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        visited[i] = (int *)malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++)
            visited[i][j] = -1;
    }
    bfs(arr, visited, n, m);
    printf("%d", visited[n - 1][m - 1]);
    return 0;
}