// #include <stdio.h>
// #include <stdlib.h>

// int compare_ints(const void* a, const void* b)
// {
//     int arg1 = *(const int*)a;
//     int arg2 = *(const int*)b;
 
//     if (arg1 < arg2) return -1;
//     if (arg1 > arg2) return 1;
//     return 0;
 
//     // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
 
//     // return arg1 - arg2; // erroneous shortcut: undefined behavior in case of
//                            // integer overflow, such as with INT_MIN here
// }

// int main() {
// 	int t; scanf("%d", &t);

// 	for (int i=0; i<t; i++) {
// 		int n, x; scanf("%d %d", &n, &x);

// 		int arr[n]; for (int j=0; j<n; j++) scanf("%d", &arr[j]);

// 		qsort(arr, n, sizeof(int), compare_ints);

// 		int count=0, pos=0;

// 		while (pos<n) {
// 			if (arr[pos]>=x) {
// 				count++;
// 				pos++;
// 			} else {
// 				if (x%arr[pos]==0 && (pos+(x/arr[pos]))<n) {
// 					count++;
// 					pos=pos+(x/arr[pos]);
// 				} else if ((pos+(x/arr[pos])+1)<n) {
// 					count++;
// 					pos=pos+(x/arr[pos])+1;
// 				}
// 			}
// 		}
// 		printf("%d\n", count);
// 	}
// }

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return 1;
    if (arg1 > arg2) return -1;
    return 0;
}

int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N,X;
        scanf("%d %d",&N,&X);
        int arr[N];
        //scan
        for(int j=0;j<N;j++){
            scanf("%d",&arr[j]);
        }
        //sort
        int count=0,min=arr[0],totalsum=0;
        qsort(arr, N, sizeof(int), compare_ints);

        for(int k=0;k<N;k++){
            count++;
            min=arr[k];
            if(count*min>=X){
                // if(k+1<N-1)min=arr[k+1];
                // else min=0;
                count=0;
                totalsum++;
            }

        }
        printf("%d\n",totalsum);


    }
}