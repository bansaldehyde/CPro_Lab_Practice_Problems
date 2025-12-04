#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bank_acc {
	char name[51];
	int amount;
} bank_acc;

bank_acc create_acc(char name[]) {
	bank_acc acc;
	strcpy(acc.name, name);
	return acc;
}

void deposit