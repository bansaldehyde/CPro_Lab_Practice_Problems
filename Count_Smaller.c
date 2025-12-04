#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Item;

Item tempArr[2000005];

// Merge function to count smaller elements to the right
void merge(Item arr[], int left, int mid, int right, long long count[]) {
    int i = left, j = mid + 1, k = left;
    long long rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i].value <= arr[j].value) {
            // arr[i] is taking items on its right that are smaller
            count[arr[i].index] += rightCount;
            tempArr[k++] = arr[i++];
        } else {
            // arr[j] is smaller than arr[i]
            rightCount++;
            tempArr[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        count[arr[i].index] += rightCount;
        tempArr[k++] = arr[i++];
    }

    while (j <= right) {
        tempArr[k++] = arr[j++];
    }

    for (int x = left; x <= right; x++)
        arr[x] = tempArr[x];
}

// Merge sort + counting
void mergeSort(Item arr[], int left, int right, long long count[]) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, count);
    mergeSort(arr, mid + 1, right, count);

    merge(arr, left, mid, right, count);
}

int main() {
    int N;
    scanf("%d", &N);

    Item arr[N];
    long long count[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
        count[i] = 0;
    }

    mergeSort(arr, 0, N - 1, count);

    for (int i = 0; i < N; i++) {
        printf("%lld ", count[i]);
    }

    return 0;
}