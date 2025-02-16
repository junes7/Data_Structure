#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int compare(const void *pa, const void *pb) {
    const int *a = *(int **)pa;
    const int *b = *(int **)pb;
    return a[0] > b[0];
}
int main(void) {
    int n, elem, idx = 0, start, end, mid, **numList = (int **)malloc(sizeof(int *) * 500000);
    bool flag;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &elem);
        flag = true;
        start = 0, end = idx - 1;
        while (start <= end) {
            mid = (start + end) / 2;
            // printf("numList mid: %d, elem: %d\n", numList[mid][0], elem);
            if (numList[mid][0] == elem) {
                flag = false;
                numList[mid][1] += 1;
                break;
            } else if (numList[mid][0] > elem) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        // for (int j = idx - 1; j >= 0; j--) {
        //     if (numList[j][0] == elem) {
        //         flag = false;
        //         numList[j][1] += 1;
        //         break;
        //     }
        // }
        if (flag) {
            numList[idx] = (int *)malloc(sizeof(int) * 2);
            numList[idx][0] = elem;
            numList[idx++][1] = 1;
        }
        qsort(numList, idx, sizeof(int *), compare);
    }
    qsort(numList, idx, sizeof(int *), compare);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &elem);
        flag = true;
        start = 0, end = idx - 1;
        while (start <= end) {
            mid = (start + end) / 2;
            if (numList[mid][0] == elem) {
                flag = false;
                printf("%d ", numList[mid][1]);
                break;
            } else if (numList[mid][0] > elem) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        if (flag)
            printf("%d ", 0);
    }
    free(numList);
    return 0;
}