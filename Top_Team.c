#include<stdio.h>

int main () {
    int N, Q;
    scanf("%d %d", &N, &Q);

    int arr[N];

    for (int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
    }

    // Bubble Sort
    for (int i=0; i<N-1; i++) {
        for (int j=0; j<N-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    int X, Y;
    for (int i=0; i<Q; i++) {
        scanf("%d %d", &X, &Y);

        int sum=0;
        for(int j=N-X; j<N-X+Y; j++) {
            sum=sum+arr[j];
        }
        printf("%d\n", sum);
    }
}