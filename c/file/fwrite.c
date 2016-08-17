#include <stdio.h>
#include <stdlib.h>

int main() {
	int arr[100] = {0};
	for (int i = 0; i < 100; i++) {
		arr[i] = i;
	}
	FILE* pf = fopen("array", "wb");
	// 参数：
	// 1 要写入元素的地址
	// 2 没个元素的大小
	// 3 元素个数
	// 4 文件指针
	int res = fwrite(arr, sizeof(int), 100, pf);
	fclose(pf);
	return 0;
}
