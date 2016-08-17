#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* pf = fopen("bfile", "wb");

	float arr[4] = {1.0, 2.4, 4.9};
	fwrite(arr, 4, 3, pf);
	
	fclose(pf);
	return 0;
}
