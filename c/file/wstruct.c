#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
	long id;
	char name[20];
	int age;
	char addr[100];
}Stu;

int main() {
	Stu stus[2] = {
		{10001, "one", 21, "one,one,one"},
		{20002, "two", 22, "two,two,two"}
	};
	FILE* pf = fopen("stus.dat", "wb");
	int res = fwrite(stus, sizeof(Stu), 2, pf);
	printf("res = %d\n", res);
	fclose(pf);

	return 0;
}
