#include <stdio.h>

// 求除以4的余数
int main() {
	int num = 33;	
	printf("%d\n", num - (num & ~3));
	return 0;
}
