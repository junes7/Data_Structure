#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n, cmd, num, frt = 0, idx = 0;
    scanf("%d", &n);
    int *deq = (int *)malloc(sizeof(int) * n);
    int *deqcpy = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cmd);
        if (cmd == 1) {
            scanf("%d", &num);
            // if (idx > 0) {
            //     for (int j = idx - 1; j >= 0; j--) {
            //         deq[j + 1] = deq[j];
            //     }
            //     deq[0] = num;
            // } else {
            //     deq[idx] = num;
            // }

            idx++;
        } else if (cmd == 2) {
            scanf("%d", &num);
            deq[idx++] = num;
        } else if (cmd == 3) {
            printf("%d\n", idx - frt == 0 ? -1 : deq[frt++]);
        } else if (cmd == 4) {
            printf("%d\n", idx - frt == 0 ? -1 : deq[idx-- - 1]);
        } else if (cmd == 5) {
            printf("%d\n", idx - frt);
        } else if (cmd == 6) {
            printf("%d\n", idx - frt == 0 ? 1 : 0);
        } else if (cmd == 7) {
            printf("%d\n", idx - frt == 0 ? -1 : deq[frt]);
        } else if (cmd == 8) {
            printf("%d\n", idx - frt == 0 ? -1 : deq[idx - 1]);
        }
    }
    return 0;
}