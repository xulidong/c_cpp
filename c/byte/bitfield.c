#include <stdio.h>
#include <stdlib.h>

// 各元素所占位：
// 1111 1111 1111 11
// 1111
// 1111 1
// 字节对齐：
// 1111 1111 1111 1111
// 4个字节
// 虽然字节对齐添加了字节，但空白位无法使用，结构体限定了元素的位数，越界会溢出
// 位字段的长度不能大于类型本身的长度,且位数也不能为0
// 不能对位段使用sizeof,也不能取位字段的地址，因为地址是以字节为单位的
// 如果连续的两个字段相加小于8位，会补齐到8位，即一个字节
// 可以定义无名的位，但没有意义，无法使用
typedef struct {
	unsigned int year : 14;// 0 - 31, 2^5 = 32, 5 bit
	unsigned int month : 4;// 1 - 12, 2^4 = 16, 4 bit
	unsigned int day : 5;// 0-9999, 2^14 = 16384, 14 bit
}Date;

int main() {
	Date d;
	d.year = 2015;
	d.month = 10;
	d.day = 2;
	printf("%lu\n", sizeof(d));// 输出：4
	return 0;
}
