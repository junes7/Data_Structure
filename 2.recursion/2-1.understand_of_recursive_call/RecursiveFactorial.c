#include <stdio.h>

void Recursive(int num) {
    if(num<=0)
        return;
    printf("Recursive call! %d\n",num);
    return Recursive(num-1);
}

int RecursiveFactorial(int n) {
    if(n==0)
        return 1;
    else
        return n*RecursiveFactorial(n-1);
}

int main(void) {
    Recursive(5);
    printf("\n");
    printf("1! = %d\n", RecursiveFactorial(1));
    printf("2! = %d\n", RecursiveFactorial(2));
    printf("3! = %d\n", RecursiveFactorial(3));
    printf("8! = %d\n", RecursiveFactorial(8));
    printf("9! = %d\n", RecursiveFactorial(9));
    return 0;
}
