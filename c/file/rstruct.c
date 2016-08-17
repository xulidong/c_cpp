#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
	long id;
	char name[20];
	int age;
	char addr[100];
}Stu;

int main() {
	Stu stus[2] = {0};
	FILE* pf = fopen("stus.dat", "rb");
	int res = fread(stus, sizeof(Stu), 2, pf);
	printf("res = %d\n", res);
	fclose(pf);

	for (int i = 0; i < 2; i++) {
		printf("id: %ld\n", stus[i].id);
		printf("name: %s\n", stus[i].name);
		printf("age: %d\n", stus[i].age);
		printf("addr: %s\n", stus[i].addr);
		printf("\n");
	}

	return 0;
}
