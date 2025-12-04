#include<stdio.h>

void comb(int n, int arr[], int target, int *c, int k, int i) {
    if (k>target) return;

    if (k==target) {
        *c=*c+1;
        return;
    }

    for (i=i; i<n; i++) {
            comb(n, arr, target, c, k+arr[i], i);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    scanf("%d", &target);

    int a=0;
    int *c=&a;

    comb(n, arr, target, c, 0, 0);

    printf("%d", a);
}