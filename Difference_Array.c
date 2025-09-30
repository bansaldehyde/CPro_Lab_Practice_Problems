#include<stdio.h>

int main() {
    long long int n, q;
    scanf("%lld %lld", &n, &q);

    long long int arr[n];

    long long int p_arr[n];

    for (long long int i=0; i<n; i++) {
        p_arr[i]=0;
    }

    for (int i=0; i<q; i++) {
        long long int l, r, x;
        scanf("%lld %lld %lld", &l, &r, &x);

        p_arr[l-1]=p_arr[l-1]+x;

        if (r!=n) {
            p_arr[r]=p_arr[r]+(-1*x);
        }
    }

    arr[0]=p_arr[0];
    printf("%lld ", arr[0]);

    for (int i=1; i<n; i++) {
        arr[i]=arr[i-1]+p_arr[i];
        printf("%lld ", arr[i]);
    }
}