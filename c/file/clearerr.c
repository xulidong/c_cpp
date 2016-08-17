#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* pf = fopen("out.txt", "w");
	fputs("hello world!", pf);
	rewind(pf);
	char ch = fgetc(pf);
	// 读取失败和读到文件尾部都反悔EOF(-1)
	if (ch == EOF) {
		if (feof(pf)) {
			printf("读到文件末尾\n");	
			clearerr(pf);// 重置文件流的状态,在调用clearerr(fp)后,ferror(fp)的值变为0
		}
		if (ferror(pf)) {
			printf("文件读取出错\n");
			clearerr(pf);// 重置文件流的状态,在调用clearerr(fp)后,ferror(fp)的值变为0
		}
		if (ferror(pf)) {
			printf("文件读取出错\n");
		} else {
			printf("文件正常\n");
		}
	}
	fclose(pf);
	return 0;
}
