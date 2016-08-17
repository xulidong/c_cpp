#include <stdio.h>
#include <stdlib.h>

int main() {
	char* filename = "out.txt";	
	int res = remove(filename);
	if(res == 0) {
		printf("删除成功\n");	
	} else {
		printf("删除失败\n");	
	}
	return 0;
}
