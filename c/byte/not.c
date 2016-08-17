#include <stdio.h>

int main() {
	unsigned char c = 15;// 0000 1111
	printf("%u\n", c);
	printf("%lu\n", sizeof(c));
	printf("%p\n", &c);
	unsigned char fc = ~c;// 1111 0000
	printf("%u\n", fc);
	unsigned char ffc = ~fc;// 0000 1111
	printf("%u\n", ffc);
	return 0;
}
