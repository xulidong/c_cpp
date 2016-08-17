#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* pf = fopen("err.txt", "r");
	if (!pf) {
		perror("打开文件失败");
		return -1;
	}
	fclose(pf);
	return 0;
}
