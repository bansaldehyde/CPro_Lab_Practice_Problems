#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int LIS(int n, int arr[]) {
	int *memo=malloc(n*sizeof(int));
	for (int i=0; i<n; i++) memo[i]=1;
	
	int max_so_far=1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<i; j++) {
			if (arr[j]<arr[i]) {
				memo[i]=fmax(memo[i], 1+memo[j]);
				//if (1+memo[j] > memo[i]) memo[i]=1+memo[j];
				if (max_so_far<memo[i]) {
					max_so_far=memo[i];
				}
			}
		}
	}
	free(memo);
	return max_so_far;
}

int main() {
	int n; scanf("%d", &n);

	int arr[n];
	for (int i=0; i<n; i++) scanf("%d", &arr[i]);

	printf("%d", LIS(n, arr));
}