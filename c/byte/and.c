#include <stdio.h>

int main() {
	unsigned char num = 129;// 1000 0001 与之相与清零高4位
	unsigned char a = 15;// 0000 1111 与之相与清零高4位
	unsigned char b = 240;// 1111 0000 与之相与清零低4位
	unsigned char c = 255;// 1111 1111
	unsigned char d = 0;// 0000 0000 与之相与全部清零
	printf("%u\n",num & a);
	printf("%u\n",num & b);
	printf("%u\n",num & c);
	printf("%u\n",num & d);
	return 0;
}
