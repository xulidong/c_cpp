#include <stdio.h>
#include <stdlib.h>
/*
 * SEEK_SET 0 文件头
 * SEEK_CUR 1 当前位置
 * SEEK_END 2 文件尾
 * */

int main() {
	// 求文件的大小 
	FILE* pf = fopen("ftell.c", "r");	
	fseek(pf, 0, SEEK_END);// 相对于SEEK_END偏移0个字节
	int flen = ftell(pf);// 获取当前位置相对于文件首的位移,单位：字节
	printf("ftell.c size:%d\n", flen);
	fclose(pf);

	return 0;
}
