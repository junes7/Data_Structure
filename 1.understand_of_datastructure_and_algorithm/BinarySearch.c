#include <stdio.h>

int LSearch(int ar[], int len, int target) {
    for(int i=0;i<len;i++) {
        if(ar[i]==target)
            return i;
    }
    return -1;
}

int BSearch(int ar[], int len, int target) {
    int first=0, last=len-1;
    int mid;
    while(first<=last) {
        mid=(first+last)/2;
        if(target==ar[mid]) {
            return mid;
        } else {
            if(target<ar[mid])
                last=mid-1;
            else
                first=mid+1;
        }
    }
    return -1;
}

int main(void) {
    int arr[]={1, 3, 5, 7, 9};
    int idx=BSearch(arr,sizeof(arr)/sizeof(int),7);
    printf((idx==-1)?"탐색 실패\n":"타겟 저장 인덱스: %d\n",idx);
    idx=BSearch(arr,sizeof(arr)/sizeof(int),4);
    printf((idx==-1)?"탐색 실패\n":"타겟 저장 인덱스: %d\n",idx);
    return 0;
}