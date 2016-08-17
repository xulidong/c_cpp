#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* pf = fopen("out.txt", "r");	
	char ch;
	do {
		ch = fgetc(pf);	
		putchar(ch);
	} while(ch != EOF);
	
	fclose(pf);

	return 0;
}
