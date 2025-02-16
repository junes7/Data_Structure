#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int compare(const void *pa, const void *pb) {
    const int *a = *(int **)pa;
    const int *b = *(int **)pb;
    return a[0] > b[0];
}
int main(void) {
    int n, elem, idx = 0;
    scanf("%d", &n);
    bool flag;
    int *pt = (int *)malloc(sizeof(int) * n);
    int **ptdic = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        flag = true;
        scanf("%d", &elem);
        pt[i] = elem;
        for (int j = 0; j < idx; j++) {
            if (ptdic[j][0] == elem) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ptdic[idx] = (int *)malloc(sizeof(int) * 2);
            ptdic[idx][0] = elem;
            ptdic[idx++][1] = i;
        }
    }
    qsort(ptdic, idx, sizeof(int *), compare);
    for (int i = 0; i < idx; i++)
        ptdic[i][1] = i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < idx; j++) {
            if (ptdic[j][0] == pt[i]) {
                printf("%d ", ptdic[j][1]);
                break;
            }
        }
    }
    return 0;
}