#include <stdio.h>

int main() {
	int a = 0;
	int b = 0;
	printf("&a: %p, &b: %p \n", &a, &b);
	// 栈的地址上大下小
	// a的地址大，证明栈开口向下
	// b的地址大，证明栈开口向上
	return 0;
}
