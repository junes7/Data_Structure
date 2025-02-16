#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool isprime(int n) {
    if (n < 2) return false;
    for (int i = 2; i < (int)pow(n, 0.5) + 1; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int find_visited_val(int **visited, int target, int idx) {
    for (int i = 0; i < idx; i++) {
        if (visited[i][0] == target) {
            return i;
        }
    }
    return -1;
}
int find_min_steps(int start, int target, int n) {
    int **visited = (int **)malloc(sizeof(int *) * n);
    int *queue = (int *)malloc(sizeof(int) * n);
    char *curr_str = (char *)malloc(sizeof(char) * 5);
    char *ch = (char *)malloc(sizeof(char) * 5);
    for (int i = 0; i < n; i++) {
        visited[i] = (int *)malloc(sizeof(int) * 2);
    }
    int idx = 0, curr, digit, next_num;
    queue[idx] = start;
    visited[idx][0] = start;
    visited[idx++][1] = 0;
    while (idx > 0) {
        curr = queue[0];
        for (int i = 1; i < idx; i++) {
            queue[i - 1] = queue[i];
        }
        if (curr == target) {
            if (find_visited_val(visited, curr, idx) != -1) {
                digit = find_visited_val(visited, curr, idx);
                return visited[digit][1];
            }
        }
        idx--;
        sprintf(curr_str, "%d", curr);
        printf("%s\n", curr_str);

        for (int i = 0; i < 4; i++) {
            strcpy(ch, curr_str);
            for (int j = 0; j < 10; j++) {
                if (i == 0 && j == 0 || j == ch[i] - 48)
                    continue;
                ch[i] = j + 48;
                next_num = atoi(ch);
                if (isprime(next_num) && find_visited_val(visited, next_num, idx) == -1) {
                    visited[idx][0] = next_num;
                    visited[idx++][1] = visited[digit][1] + 1;
                }
            }
        }
    }
}
int main(void) {
    int t, start, target;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &start, &target);
        printf("%d\n", find_min_steps(start, target, t));
    }
    return 0;
}
