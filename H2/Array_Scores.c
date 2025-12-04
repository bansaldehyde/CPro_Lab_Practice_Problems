#include <stdio.h>
#include <math.h>

int min_sq(int n, int arr[], int sum) {
	if (n==1) return arr[0];

	int ans=1e9;
	
	min_sq()
	
}

int main() {
	int n; scanf("%d", &n);
	 
	int arr1[n];
	for (int i=0; i<n; i++) scanf("%d", &arr1[i]);

	int arr2[n], sum=0;
	for (int i=0; i<n; i++) {
		arr2[i]=arr1[n]^2;
		sum=sum+arr2[i];
	}


}

// #include <stdio.h>
// #include <stdlib.h>

// long long bestDiff = 1e18; 

// void solve(int idx, int n, long long total, long long curr, long long *sq) {
//     if (idx == n) {
//         long long diff = llabs(total - 2 * curr);
//         if (diff < bestDiff) bestDiff = diff;
//         return;
//     }


//     solve(idx + 1, n, total, curr + sq[idx], sq);

   
//     solve(idx + 1, n, total, curr, sq);
// }

// int main() {
//     int n;
//     scanf("%d", &n);

//     long long arr[n], sq[n];
//     long long total = 0;

//     for (int i = 0; i < n; i++) {
//         scanf("%lld", &arr[i]);
//         sq[i] = arr[i] * arr[i];
//         total += sq[i];
//     }

//     solve(0, n, total, 0, sq);

//     printf("%lld\n", bestDiff);
//     return 0;
// }