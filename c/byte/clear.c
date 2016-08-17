#include <stdio.h>
// 与位数有关可以借助~1
int main() {
	// 最低位清零
	unsigned char a = 15;// 0000 1111
	unsigned short b = 1;// 0000 0000 0000 0001
	a = a & ~1;// ~1:1111 1110, 结果:0000 1110
	b = b & ~1;// ~1:1111 1111 结果:0000 0000 0000 0000 
	printf("a = %u, b = %u\n", a, b);

	return 0;
}
