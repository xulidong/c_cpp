#include <stdio.h>
#include <stdlib.h>

int main() {
	fprintf(stderr, "stderr error:%d, msg:%s\n", 3,  "权限不够");// 始终在显示器输出
	fprintf(stdout, "stdout error:%d, msg:%s\n", 3,  "权限不够");// 可以重定向到文件
	// 使用./a.out > test.txt执行，stdout会被写入磁盘，stderr仍然在显示器上输出
	return 0;
}
