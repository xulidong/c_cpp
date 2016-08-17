#include <stdio.h>
#include <stdlib.h>

int main() {
	char str[100] = {0};
	FILE* pf = fopen("cmd.txt", "r");	
	fscanf(pf, "%s", str);
	printf("str = %s\n", str);
	fclose(pf);
	
	return 0;
}
