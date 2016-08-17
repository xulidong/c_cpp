#include <stdio.h>

int main() {
	register int num = 6;
	// printf("%p\n", &num);// 寄存器变量在cpu的地址中，没有地址，对其取地址会报错
	return 0;
}
