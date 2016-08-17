#include <stdio.h>
#include <stdlib.h>

int main() {
	char str[100] = {};
	scanf("%s", str);
	printf("cmd = %s", str);
	system(str);
	return 0;
}
// 执行：./a.out < cmd.txt，将文件的内容作为输入
// 执行：./a.out < cmd.txt > out.txt，将显示的内容输出到文件
