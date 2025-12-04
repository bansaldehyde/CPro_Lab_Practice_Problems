#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
 
    // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
 
    // return arg1 - arg2; // erroneous shortcut: undefined behavior in case of
                           // integer overflow, such as with INT_MIN here
}

int main() {
	int t; scanf("%d", &t);

	for (int i=0; i<t; i++) {
		int n; scanf("%d", &n);

		int arr[n];
		for (int j=0; j<n; j++) scanf("%d", &arr[j]);

		qsort(arr, n, sizeof(int), compare_ints);

		int x=((n+1)/2)-1;
		int count=1;

		while ((x+1)!=n && arr[x+1]==arr[x]) {
			count++;
			x++;
		}
		printf("%d\n", count);
	}
}