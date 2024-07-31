#include <stdio.h>

int LSearch(int ar[], int len, int target) {
    for(int i=0;i<len;i++) {
        if(ar[i]==target)
            return i;
    }
    return -1;
}

int main(void) {
    int arr[]={3, 5, 2, 4, 9};
    int idx;
    idx=LSearch(arr,sizeof(arr)/sizeof(int),4);
    printf((idx==-1)?"탐색 실패\n":"타겟 저장 인덱스: %d\n", idx);
    idx=LSearch(arr,sizeof(arr)/sizeof(int),7);
    printf((idx==-1)?"탐색 실패\n":"타겟 저장 인덱스: %d\n", idx);
    return 0;
}