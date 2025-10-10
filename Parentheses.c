#include <stdio.h>

void generate(char str[], int pos, int open, int close, int n) {
    if (open == n && close == n) {
        str[pos] = '\0';
        printf("%s\n", str);
        return;
    }
    
    if (open < n) {
        str[pos] = '(';
        generate(str, pos + 1, open + 1, close, n);
    }
    
    if (close < open) {
        str[pos] = ')';
        generate(str, pos + 1, open, close + 1, n);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    char str[17];  // max 2*8 + 1 for null terminator
    generate(str, 0, 0, 0, n);
    
    return 0;
}
