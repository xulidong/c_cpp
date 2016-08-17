#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// access判断文件或者文件夹是否存在, 0存在, -1不存在 
// 0 R_OK 是否存在
// 1 W_OK 是否可执行
// 2 X_OK 是否可写
// 4 F_OK 是否可读
int main() {
	printf("%d\n", access("1", 0));	
	return 0;
}
