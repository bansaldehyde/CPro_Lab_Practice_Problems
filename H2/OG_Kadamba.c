#include <stdio.h>

int max_ways(int n, int arr[n][n], int i, int j, int dp[n][n]) {
	if (i>=n || j>=n || arr[i][j]==0) return 0;
	if (i==n-1 && j==n-1) return 1;

	if (dp[i][j]!=-1) return dp[i][j];

	int ans=0;
	ans=(ans+max_ways(n, arr, i, j+1, dp))%1000000007;
	ans=(ans+max_ways(n, arr, i+1, j, dp))%1000000007;

	dp[i][j]=ans;
	return ans;
}

int main() {
	int n; scanf("%d", &n);
	
	char str[n+1];
	int arr[n][n];
	
	for (int i=0; i<n; i++) {
		scanf("%s", str);
		for (int j=0; j<n; j++) {
			if (str[j]=='.') arr[i][j]=1;
			else arr[i][j]=0;
		}
	}

	// for (int i=0; i<n; i++) {
	// 	printf("\n");
	// 	for (int j=0; j<n; j++) {
	// 		printf("%d", arr[i][j]);
	// 	}
	// }

	int dp[n][n];
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) dp[i][j]=-1;
	}

	printf("%d", max_ways(n, arr, 0, 0, dp));

}