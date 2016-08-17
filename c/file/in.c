#include <stdio.h>
#include <stdlib.h>

// C语言是通过文件来操作设备
// stdout对应显示器
// stdin对应键盘
int main1() {
	int num;
	scanf("%d", &num);
	printf("num = %d\n", num);
	
	fscanf(stdin, "%d", &num);
	fprintf(stdout, "num = %d\n", num);

	return 0;
};

int main2() {
	char str[50];
	gets(str);
	puts(str);
	return 0;
}

int main3() {
	char str[50];
	fgets(str, sizeof(str) - 1, stdin);
	fputs(str, stdout);

	return 0;
}

int main4() {
	char ch = getchar();
	fputc(ch, stdout);
	printf("\n");
	return 0;
}

int main() {
	char ch = fgetc(stdin);
	fputc(ch, stdout);
	printf("\n");
	return 0;
}
