#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int flowers[n];

    for (int i=0; i<n; i++) {
        scanf("%d", &flowers[i]);
    }

    int c=0;
    int lg=0, rg=0;
    for (int k=0; k<n; k++) {
        for (int i=0; i<=k; i++) {
            lg=lg+flowers[i];
            if ((n-(2*k)-1+i)>=0) {
                rg=rg+flowers[n-(2*k)-1+i];
            }
        }
        if (lg==rg) c++;
        lg=0;
        rg=0;
    }
    printf("%d", c);
}