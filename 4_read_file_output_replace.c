#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


int main()
{
	char oldword[50], fileline[50], change[50], fixstring[50];
	//oldword는 바꾸기 전 단어, change는 바꿀 단어, fileline은 파일을 파일에 출력하기 위한 문자열 변수
	FILE* eng; //입력 값이 저장되는 파일
	FILE* end; //업력 받은 파일을 읽어 결과를 출력할 파일

	eng = fopen("c:\\in.txt", "r"); //입력받은 파일을 읽기로 연다
	end = fopen("c:\\out.txt", "w"); //받을 파일을 쓰기로 열어준다

	gets(oldword);
	gets(change);

	while (fgets(fileline, sizeof(fileline), eng) != NULL)
	{//파일에서 한 줄을 빼내어 문자열 변수에 담은 값이 널 값이 아니라면 반복
		char* orderstring = strtok(fileline, " "); //분석할 해당 문자열(줄) 띄어쓰기 기준으로 자른다
		while (orderstring != NULL) //자른 값이 비어있지 않다면(끝지점) 반복
		{

			if (strcmp(orderstring, oldword) == 0)
			{//자른 문자열(orderstring)이 찾고자 하는 값(oldword)과 같은가?
				fprintf(end, " %s", change); //같다면 바꿀 단어로 출력
			}
			else
			{
				fprintf(end, " %s", orderstring); //아니면 기존 문자열 출력
			}
			orderstring = strtok(NULL, " "); //널 값을 기준으로 띄어쓰기 기준으로 잘라 문자열에 저장
		}
	}
	fclose(eng);
	fclose(end);
}