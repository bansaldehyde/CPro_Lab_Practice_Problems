#include <stdio.h>
#include <stdbool.h>

void print_permutation(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generate_permutations(int arr[], int n, bool used[], int current_index) {
    if (current_index == n) {
        print_permutation(arr, n);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            arr[current_index] = i;
            used[i] = true;

            generate_permutations(arr, n, used, current_index + 1);

            used[i] = false;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    bool used[n + 1];

    for (int i = 1; i <= n; i++) {
        used[i] = false;
    }

    generate_permutations(arr, n, used, 0);
}