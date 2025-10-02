#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    
    for (int i=0; i<n; i++) scanf("%d", &arr[i]);

    int c=1; //Rightmost soldier is always the leader

    int leader=arr[n-1];
    int l_arr[n];
    l_arr[c-1]=leader;

    for (int i=n-2; i>=0; i--) {
        if (arr[i]>leader) {
            c++;
            leader=arr[i];
            l_arr[c-1]=leader;
        }
    }
    for (int i=c-1; i>=0; i--) printf("%d ", l_arr[i]);
}