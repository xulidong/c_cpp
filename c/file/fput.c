#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* pf = fopen("text.txt", "w");
	fputs("test text", pf);
	fflush(pf);// 让文件缓冲区内容立即写入，否则缓冲区内容将在文件关闭的时候写入文件
	fclose(pf);
	return 0;
}
