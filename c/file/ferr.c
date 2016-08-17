#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* pf = fopen("out.txt", "w");
	if (ferror(pf) == 0) {
		printf("文件写入正常\n");	
	} else {
		printf("文件写入错误\n");	
	}

	char str[100];
	fgets(str, 100, pf);
	if (ferror(pf) == 0) {
		printf("文件写入正常\n");	
	} else {
		printf("文件写入错误\n");	
	}
	fclose(pf);
	return 0;
}
