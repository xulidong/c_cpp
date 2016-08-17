#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* pf = fopen("out.txt", "w");	
	int h = 8848;
	fprintf(pf, "珠峰的高度为：%d", h);
	
	fclose(pf);

	return 0;
}
