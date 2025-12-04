#include<stdio.h>

void jump(long long int n, long long int *c, long long int k) {
    if (k>n) return;
    if (k==n) {
        *c=*c+1;
        return;
    }

    jump(n, c, k+1);
    jump(n, c, k+2);
    jump(n, c, k+3);
}

int main() {
    long long int n;
    scanf("%lld", &n);

    long long int p=0;
    long long int *c=&p;

    jump(n, c, 0);

    // long long int j=0;
    // long long int m=p;

    // while (m!=0) {
    //     m=m/10;
    //     j++;
    // }

    // printf("10^%d + %d", j-1, p%10);

    printf("%lld", p);
}