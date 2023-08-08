#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


int main()
{
	char name[50], name3[50]; //name은 찾을 단어, name3는 파일에서 가져와서 분석할 줄이다
	int line = 0, word = 0; //line은 in파일의 줄 수를 담는다. word는 in파일의 단어 수를 담는다.
	FILE* eng; //입력 값이 저장되는 파일
	FILE* end; //업력 받은 파일을 읽어 결과를 출력할 파일

	eng = fopen("c:\\in.txt", "r"); //입력받은 파일을 읽기로 연다
	end = fopen("c:\\out.txt", "w"); //받을 파일을 쓰기로 열어준다

	gets(name); //도스창에서 단어를 입력받는다

	while (fgets(name3, sizeof(name3), eng) != NULL)
	{//파일에서 한 줄을 빼내어 문자열 변수에 담은 값이 널 값이 아니라면 반복
		line++; //라인 수를 늘린다
		word = 0; //단어 위치 초기화

		char *name2 = strtok(name3, " "); //분석할 해당 문자열(줄) 띄어쓰기 기준으로 자른다

		while (name2 != NULL) //자른 값이 비어있지 않다면(끝지점) 반복
		{
			word++; //단어 수 세기(단어 위치 이동)
			if (strcmp(name2, name) == 0) //자른 문자열(name2)이 찾고자 하는 값(name)과 같은가?
			{
				fprintf(end, "%s는 %d 줄에 %d 번째 존재\n", name, line, word);
				//같다면 현 정보를 출력
			}
				name2 = strtok(NULL, " "); //널 값을 기준으로 띄어쓰기 기준으로 잘라 문자열에 저장
		}
		
	}
	fclose(eng);
	fclose(end);
}