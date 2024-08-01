#include <stdio.h>

int BSearch(int ar[], int len, int target) {
    int first=0, last=len-1, mid;
    int opcnt=0;
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
        opcnt+=1;
    }
    printf("비교연산횟수: %d\n",opcnt);
    return -1;
}

int main(void) {
    int arr1[500]={0,};
    int arr2[5000]={0,};
    int arr3[50000]={0,};

    int idx=BSearch(arr1,sizeof(arr1)/sizeof(int),1);
    printf((idx==-1)?"탐색 실패\n":"타겟 저장 인덱스: %d\n", idx);
    idx=BSearch(arr2,sizeof(arr2)/sizeof(int),2);
    printf((idx==-1)?"탐색 실패\n":"타겟 저장 인덱스: %d\n", idx);
    idx=BSearch(arr3,sizeof(arr3)/sizeof(int),3);
    printf((idx==-1)?"탐색 실패\n":"타겟 저장 인덱스: %d\n", idx);
    return 0;
}