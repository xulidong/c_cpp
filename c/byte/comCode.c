#include <stdio.h>
#include <stdlib.h>

int main() {
	int num = 0;
	scanf("%d", &num);
	printf("%d 的补码：", num);
	int data = 1 << 31;
	for (int i = 1; i <= 32; i++) {
		printf("%c",(num & data) ? '1' : '0');
		if (i % 4 == 0) {
			printf(" ");	
		}
	}
	printf("\n");
	return 0;
}
