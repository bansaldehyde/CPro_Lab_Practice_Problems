#include <stdio.h>
#include <math.h>

long long int dp[100][10000];

long long int max_value(int w[], int v[], int W, int N, int i) {
	if (i==N) return 0;
	if (W==0) return 0;
	else if (W<0) return -1e9;

	if (dp[i][W]!=-1) return dp[i][W];
	
	long long int a1=-1e9, a2, ans=0;

	if (W>=w[i]) a1=max_value(w, v, W-w[i], N, i+1)+v[i];
	a2=max_value(w, v, W, N, i+1);

	ans=fmax(a1, a2);

	dp[i][W]=ans;
	return ans;
}

int main() {
	int N, W; scanf("%d %d", &N, &W);

	int w[N], v[N];
	for (int i=0; i<N; i++) scanf("%d %d", &w[i], &v[i]);

	for (int i=0; i<N; i++) {
		dp[i][0]=0;
		for (int j=1; j<W+1; j++) dp[i][j]=-1;
	}

	printf("%lld", max_value(w, v, W, N, 0));
}