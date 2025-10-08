#include <stdio.h>

int xor(int n, int arr[]) {
    if (arr[n-1]!=0) {
        return arr[n-1];
    } else {
        int a=(xor(n-1, arr)^xor(n-2, arr))+xor(n/2, arr);
        arr[n-1]=a;
        return a;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i=0; i<n; i++) {
        arr[i]=0;
    }
    arr[0]=1;
    arr[1]=2;
    printf("%d", xor(n, arr));
}