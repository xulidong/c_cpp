#include <stdio.h>

// extern int sNum;// 无法调用文件作用域的变量
extern int eNum1;
int eNum2;

int main() {
	// printf("%d\n", sNum);
	printf("%d\n", eNum1);
	printf("%d\n", eNum2);
	return 0;
}
