#include <stdio.h>
#include <stdlib.h>

int main() {
	char* filename = "tst.txt";	
	char* new_filename = "test.txt";	
	int res = rename(filename, new_filename);
	if(res == 0) {
		printf("改名成功\n");	
	} else {
		printf("改名失败\n");	
	}
	return 0;
}
