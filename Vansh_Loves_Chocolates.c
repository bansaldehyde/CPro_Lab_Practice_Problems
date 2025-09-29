#include<stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];

    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    //Insertion Sort
    for (int i=1; i<n; i++) {
        int key=arr[i];
        int j=i-1;

        while (j>=0 && arr[j]>key) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }

    int c=0;

    //Loop1
    for (int i=0; i<n-2; i++) {
        //Loop2 (Nested Loop)
        for (int j=i+1; j<n-1; j++) {
            //Binary Search inside the loop
            int target = k-(arr[i]+arr[j]);
            int left=j+1, right=n-1;
            int mid=left+(right-left)/2;
            while (left<=right && arr[mid]!=target) {
                if (arr[mid]>target) {
                    right=mid-1;
                    mid=left+(right-left)/2;
                }
                if (arr[mid]<target) {
                    left=mid+1;
                    mid=left+(right-left)/2;
                }
            }
            if (arr[mid]==target) {
                c++;
            }
        }
    }
    printf("%d", c);
}