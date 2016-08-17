#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* pfr = fopen("before.txt","r");
	FILE* pfw = fopen("after.txt","w");
	while(!feof(pfr)) {
		char ch = fgetc(pfr);	
		ch += 1;
		fputc(ch, pfw);
	}

	fclose(pfr);
	fclose(pfw);

	return 0;
}
