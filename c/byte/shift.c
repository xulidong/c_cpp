#include <stdio.h>
// 移位在cpu的寄存器中完成计算
// 右移1位，相当于除2，无符号高位补零，有符号填充符号位
// 左移1位，相当于乘2，无符号低位补零
int main() {
	unsigned char a = 128;// 1000 0000
	unsigned char b = 1;// 0000 0001
	char c = -4;// 1111 1100 

	printf("%u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u\n", a, a >> 1, a >> 2, a >> 3, a >> 4, a >> 5, a >> 6, a >> 7, a >> 8, a >> 9, a >> 10);
	printf("%u, %u, %u, %u, %u, %u, %u, %u, %u, %u, %u\n", b, b << 1, b << 2, b << 3, b << 4, b << 5, b << 6, b << 7, b << 8, b << 9, b << 10);
	printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", c, c >> 1, c >> 2, c >> 3, c >> 4, c >> 5, c >> 6, c >> 7, c >> 8, c >> 9, c >> 10);

	return 0;
}
