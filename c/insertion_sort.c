#include <stdio.h>

/*
 * 打印数组
 * */
void printArray(int arr[], int n) {
	int i = 0;
	for (i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/*
 * 插入排序
 * 在已经有序的数组中插入新的元素，是数组仍然有序
 * */
void insertionSort(int arr[], int n) {
	int i = 0;
	int j = 0;
	int k = 0;
	int tmp = 0;

	for (i = 1; i < n; ++i) {
		for (j = 0; j < i; ++j) {
			if (arr[i] < arr[j]) {
				break;
			}
		}
		if (j != i) {
			tmp = arr[i];
			for (k = i; k > j; --k) {
				arr[k] = arr[k - 1];
			}
			arr[j] = tmp;
		}
	}
}

/*
 * 插入排序优化
 * 在比较大小的同时移动元素的位置
 * */
void insertionSort1(int arr[], int n) {
	int i = 0;
	int j = 0;
	int tmp = 0;
	for(i = 1; i < n; ++i) {
		tmp = arr[i];
		for (j = i; j > 0 && a[j] < a[j - 1]; ++j) {
			a[j] = a[j - 1];
		}
		arr[j] = tmp;
	}
}

int main() {
	int arr[] = {9, 5, 8, 4, 7, 3, 2, 0, 6, 1};
	printArray(arr, 10);
	insertionSort(arr, 10);
	printArray(arr, 10);

	return 0;
}
