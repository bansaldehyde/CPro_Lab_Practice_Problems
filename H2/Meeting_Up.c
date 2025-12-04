#include <stdio.h>

void metup(int S, int T, int *b) {
	if (S==T) {
		*b=*b+1;
		return;
	}
	if (S>T) return;

	metup(S+1, T, b);
	metup(S+2, T, b);
	metup(S+3, T, b);

	return;
}

int main() {
	int S, T; scanf("%d %d", &S, &T);

	int a=0;
	int *b=&a;
	metup(S, T, b);

	printf("%d", a);
}