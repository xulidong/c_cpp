#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* pf = fopen("bfile", "rb");

	float arr[3] = {0};
	fread(arr, 4, 3, pf);
	
	for (int i = 0; i < 3; i++) {
		printf("%f\n", arr[i]);
	}

	fclose(pf);
	return 0;
}
