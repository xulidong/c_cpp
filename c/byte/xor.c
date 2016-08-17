#include <stdio.h>

int main() {
	unsigned char num = 129;// 1000 0001
	unsigned char a = 15;// 0000 1111
	unsigned char b = 240;// 1111 0000
	unsigned char c = 255;// 与之异或全部反转 1111 1111
	unsigned char d = 0;// 0000 0000
	printf("%u\n",num ^ a);// 1000 1110
	printf("%u\n",num ^ b);// 0111 1110
	printf("%u\n",num ^ c);// 0111 0001
	printf("%u\n",num ^ d);// 1000 1110

	// 交换两个值
	printf("a = %u, b = %u\n", a, b);
	a = a ^ b;// 1111 1111
	b = a ^ b;// 0000 1111
	a = a ^ b;// 1111 0000
	printf("a = %u, b = %u\n", a, b);

	return 0;
}
