#include <stdio.h>
#include <stdlib.h>

int main() {
	int w = getw(stdin);// 从键盘读入4个字节作为一个字符
	putw(w, stdout);
	putc('\n', stdout);
	putc(97, stdout);
	putc(97, stdout);
	putc(97, stdout);
	putc(97, stdout);
	putc('\n', stdout);
	putw(97, stdout);
	putc('\n', stdout);
	return 0;
}
