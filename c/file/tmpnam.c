#include <stdio.h>
// tmpnam产生一个唯一的文件名
int main() {
	char name[20];
	char* res = tmpnam(name);
	if (!res) {
		perror("创建失败");
		return -1;
	}
	printf("Temporyary name: %s\n", name);
	return 0;
}
