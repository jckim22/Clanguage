#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	FILE* fp1 = fopen("ex1.txt", "r");
	FILE* fp2 = fopen("ex2.txt", "w");

	char buffer[100];
	char* ptr; //strstr로 받아줘야 하는 포인터

	while (fgets(buffer, 100, fp1) != NULL) { //한 줄
		 
		ptr = strstr(buffer, "abc"); //문장의 첫 abc를 찾아서 a의 주소를 ptr에 담게 됨

		while (ptr != NULL) { //그 줄의 끝까지 가게 되어서 abc를 찾지 못했다면 반복문을 나옴
			
			strncpy(ptr, "000", 3); //ptr에 담긴 abc를 000으로 바꿈

			ptr = strstr(buffer, "abc"); //앞에는 000으로 바뀌었기 때문에 그 다음 abc의 a의 주소를 ptr에 담음
		}
		fputs(buffer,fp2); //000으로 바뀐 버퍼의 값을 파일에 넣어준다.

	}

	fclose(fp1);
	fclose(fp2);
}