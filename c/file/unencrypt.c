#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* pfw = fopen("un.txt","w");
	FILE* pfr = fopen("after.txt","r");
	while(!feof(pfr)) {
		char ch = fgetc(pfr);	
		ch -= 1;
		fputc(ch, pfw);
	}

	fclose(pfr);
	fclose(pfw);

	return 0;
}
