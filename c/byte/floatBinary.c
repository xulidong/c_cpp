#include <stdio.h>
#include <stdlib.h>
// 打印浮点数的二进制
int main() {
	float f = 0.0;
	scanf("%f", &f);
	unsigned char *p = (unsigned char *)&f;
	for (int i = 3; i >= 0; i--) {// 高字节在后，低字节在前，逆向输出
		unsigned char ch = p[i];// 得到每个字节的二进制
		for (int j = 7; j >= 0 ; j--) {// 高位在前，低位在后
			printf("%c", ch & (1 << j) ? '1' : '0');// 得到每位的二进制
		}
		printf(" ");	
	}
	printf("\n");	
	return 0;
}
