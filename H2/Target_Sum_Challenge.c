#include <stdio.h>

int a=0;

void tcs(int n, long long x, int arr[], int i, long long sum) {
	if (a==1) return;
	
	if (i==n) {
		if (sum==x) a=1;
		return;
	}

	tcs(n, x, arr, i+1, sum+arr[i]);
	if (i!=0) tcs(n, x, arr, i+1, sum-arr[i]);

	return;
}

int main() {
	int n; 
	long long x; 
	scanf("%d %lld", &n, &x);

	int arr[n];
	for (int i=0; i<n; i++) scanf("%d", &arr[i]);

	tcs(n, x, arr, 0, 0);

	if (a==1) printf("YES\n");
	else printf("NO\n");
}