#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n, idx;
    bool flag;
    char **s = (char **)malloc(sizeof(char *) * 1000000);
    char *name = (char *)malloc(sizeof(char) * 5), *state = (char *)malloc(sizeof(char) * 5);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", name, state);
        flag = true;
        printf("name: %s, state: %s\n", name, state);
        if (strcmp(state, "enter") == 0) {
            for (int i = 0; i < idx; i++) {
                if (strcmp(s[i], name) == 0) {
                    flag = false;
                    break;
                }
            }
            printf("name: %s, flag: %d, state: %s\n", name, flag, state);
            if (flag) {
                s[idx] = (char *)malloc(sizeof(char) * strlen(name));
                strcpy(s[idx++], name);
            }
        } else {
            printf("name: %s, idx: %d\n", name, idx);
            for (int i = 0; i < idx; i++) {
                printf("%s ", s[i]);
                if (strcmp(s[i], name) == 0) {
                    while (i < idx - 1) {
                        strcpy(s[i], s[i + 1]);
                        i += 1;
                    }
                    break;
                    idx--;
                }
            }
        }
    }
    printf("\nidx: %d\n", idx);
    for (int i = 0; i < idx; i++) {
        printf("%s\n", s[i]);
    }
    return 0;
}