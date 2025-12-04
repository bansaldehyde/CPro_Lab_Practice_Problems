#include<stdio.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int arr[n][n];
    char i_arr[n][n+1];

    for (int i=0; i<n; i++) {
        scanf("%s", i_arr[i]);
        for (int j=0; j<n; j++) {
            if (i_arr[i][j]=='*') {
                arr[i][j]=1;
            } else {
                arr[i][j]=0;
            }
        }
    }

    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<n; j++) {
    //         printf("%d ", arr[i][j]);
    //     }
    //     printf("\n");
    // }

    int p_arr[n][n];

    for (int i=0; i<n; i++) {
        p_arr[i][0]=arr[i][0];
        for (int j=1; j<n; j++) {
            p_arr[i][j]=p_arr[i][j-1]+arr[i][j];
        }
    }

    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<n; j++) {
    //         printf("%d ", p_arr[i][j]);
    //     }
    //     printf("\n");
    // }

    for (int i=0; i<q; i++) {
        int y1, x1, y2, x2;
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);

        int y1_, x1_, y2_, x2_;
        y1_=y1-1;
        x1_=x1-1;
        y2_=y2-1;
        x2_=x2-1;

        int sum=0;
        for (int j=y1_; j<=y2_; j++) {
            if (x1_!=0) {
                sum=sum+p_arr[j][x2_]-p_arr[j][x1_-1];
            } else {
                sum=sum+p_arr[j][x2_];
            }
        }
        printf("%d\n", sum);
    }
}