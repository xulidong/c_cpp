#include <stdio.h>

#define PRINT(x) printf("%s = %d\n",#x, x);

extern int x;

void show() {
	PRINT(x);
}

int x = 0;

int main() {
	show();
	return 0;
}
