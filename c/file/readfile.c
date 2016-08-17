#include <stdio.h>
#include <stdlib.h>
// r模式文件必须存在，否则打开失败
// 如果写入不会报错，但是不能写入成功
// r+可读写
// fclose 将文件缓冲区的内容写入
// 如果程序意外关闭，没有调用fclose，数据会丢失
int main() {
	FILE* pf = fopen("out.txt", "r");
	if (!pf) {
		fprintf(stderr, "文件不存在");
		return -1;
	}
	
	while(!feof(pf)) {
		char c = fgetc(pf);	
		putchar(c);
	}
	
	int ret = fputc('A', pf);
	if (ret == -1) {
		fprintf(stderr, "文件写入失败:%d", ret);
	}

	fclose(pf);

	return 0;
}
