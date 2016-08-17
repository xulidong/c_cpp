#include <stdio.h>
#include <stdlib.h>
// mktemp产生位移的临时目录名,最后六个字符必须是XXXXXX
int main() {
	// char* dirname = "tmpXXXXXX";// 会报错：Bus error：10
	char dirname[] = "tmpXXXXXX";
	char* res = mktemp(dirname);
	if (!res) {
		perror("目录创建失败");
		return -1;
	}
	printf("%s\n", res);
	return 0;
}
