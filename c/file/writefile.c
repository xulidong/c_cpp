#include <stdio.h>
#include <stdlib.h>
// w模式打开文件，如果不存在则创建，存在则清空
// 如果读取不会报错，但是不会成功
// w+可读写
int main() {
	FILE* pf = fopen("in.txt", "w");
	if (!pf) {
		fprintf(stderr, "文件不存在");
		return -1;
	}
	
	fputs("test text", pf);

	rewind(pf);// 将文件指针移动到开头
	char c = fgetc(pf);	
	if (c == -1) {
		fprintf(stderr, "文件读取失败:%d", c);
	}
	putchar(c);// 输出为空

	fclose(pf);

	return 0;
}
