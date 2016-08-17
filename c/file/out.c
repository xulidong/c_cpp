#include <stdio.h>
#include <stdlib.h>

int main() {
	putchar('A');
	fputc('B', stdout);

	printf("\nuse printf\n");
	fprintf(stdout, "use fprintf\n");	

	puts("use puts");
	fputs("use fputs\n", stdout);	

	return 0;
};
