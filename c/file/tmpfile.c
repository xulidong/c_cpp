#include <stdio.h>
#include <stdlib.h>
// tmpfile以wb+创建一个临时二进制文件，程序结束自动删除
int main() {
	FILE* pf = tmpfile();
	if (!pf) {
		perror("临时文件创建时失败");	
		return -1;
	}
	fputs("test", pf);
	rewind(pf);
	char str[100];
	fgets(str, 100, pf);
	puts(str);
	fclose(pf);
	return 0;
}
