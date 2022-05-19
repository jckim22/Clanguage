#include <stdio.h>
typedef struct stu {
	char name[20];
	float a[3];
	float sum;
}stu;

int main() {
	FILE* fp = fopen("grade.txt", "r");
	stu person[3];
	int cnt = 0;

	while (!feof(fp)) {
		fscanf(fp,"%s %f %f %f", person[cnt].name, &person[cnt].a[0], &person[cnt].a[1], &person[cnt].a[2]);
		person[cnt].sum = person[cnt].a[0] + person[cnt].a[1] + person[cnt].a[2];
		cnt++;
	}
	FILE* fp1 = fopen("gradeCopy.txt", "w");
	for (int i = 0; i < 3; i++) {
		fprintf(fp1,"%s %.2f\n", person[i].name, person[i].sum / 3);
	}
}