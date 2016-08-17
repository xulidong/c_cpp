#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* pf = fopen("tst.txt", "r");
	int ich;
	int nume = 0;// 英文字符
	int num0 = 0;// 数字
	int numc = 0;// 汉字
	int numo = 0;// 其他
	do {
		ich = fgetc(pf);// fgetc返回int，如果使用char，ASCII没有问题，汉字则不行，因为汉字是双字节，char存储不了
		if ((ich >= 'A' && ich <= 'Z') || (ich >= 'a' && ich <= 'z')) {
			nume++;	
		} else if (ich >= '0' && ich <= '9') {
			num0++;	
		} else if (ich > 128) { // 双字节字符
			ich = fgetc(pf);	
			numc++;
		} else {
			numo++;	
		}
	} while(ich != EOF);
	printf("英文:%d\n", nume);
	printf("数字:%d\n", num0);
	printf("汉字:%d\n", numc);
	printf("其他:%d\n", numo);
	fclose(pf);
	return 0;
}
