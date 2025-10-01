#include<stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i=0; i<T; i++) {
        int N;
        long long int K;
        scanf("%d %lld", &N, &K);

        int arr[N];

        for (int j=0; j<N; j++) {
            scanf("%d", &arr[j]);
        }

        long long int c=0;
        //Bubble Sort
        for (int p=0; p<N-1 && c<K; p++) {
            for (int j=1; j<N-p && c<K; j++) {
                if (c<K && arr[j-1]>arr[j]) {
                    int temp=arr[j];
                    arr[j]=arr[j-1];
                    arr[j-1]=temp;
                    c++;
                }
            }
        }

        for (int j=0; j<N; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
}