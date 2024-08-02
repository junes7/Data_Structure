#include <stdio.h>

int BSearchRecur(int ar[], int first, int end, int target) {
    if(first>end)
        return -1;
    int mid=(first+end)/2;
    if(ar[mid]==target)
        return mid;
    else if(ar[mid]>target)
        return BSearchRecur(ar, first, mid-1, target);
    else
        return BSearchRecur(ar, mid+1, end, target);
}

int main(void) {
    int arr[]={1, 3, 5, 7, 9};
    int idx=BSearchRecur(arr, 0, sizeof(arr)/sizeof(int)-1, 7);
    printf((idx==-1)?"탐색 실패\n":"타겟 저장 인덱스: %d\n",idx);
    idx=BSearchRecur(arr, 0, sizeof(arr)/sizeof(int)-1, 4);
    printf((idx==-1)?"탐색 실패\n":"타겟 저장 인덱스: %d\n",idx);
    return 0;
}