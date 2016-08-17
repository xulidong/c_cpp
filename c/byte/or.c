#include <stdio.h>

int main() {
	unsigned char num = 129;// 1000 0001
	unsigned char a = 15;// 0000 1111
	unsigned char b = 240;// 1111 0000
	unsigned char c = 255;// 1111 1111
	unsigned char d = 0;// 0000 0000
	printf("%u\n",num | a);
	printf("%u\n",num | b);
	printf("%u\n",num | c);
	printf("%u\n",num | d);
	return 0;
}
