#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* pf = fopen("test.txt", "r");	
	char str[200] = {0};
	while(fgets(str, 200, pf)) {
		puts(str);
	}
	fclose(pf);
	return 0;
}

