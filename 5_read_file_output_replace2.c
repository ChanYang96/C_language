#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


int main()
{
	char oldword[50], fileline[50], changefileline[50], change[50], fixstring[50];
	int i = 0;
	//oldword는 바꾸기 전 단어, change는 바꿀 단어, fileline은 수정 전 파일의 내용을 한줄씩 다룰 변수
	//changefileline는 수정표의 문자열을 다룰 변수, fixstring은 n차 수정의 결과를 옮기는 작업을 돕는다
	FILE* eng; //수정 전 파일
	FILE* changefile; //수정할 단어가 존재하는 파일
	FILE* end; //입력 받은 파일을 읽어 결과를 출력할 파일

	eng = fopen("c:\\in.txt", "r"); //수정 전 파일을 읽기로 연다
	changefile = fopen("c:\\changefile.txt", "r"); //수정할 단어가 존재할 파일을 읽기로 연다
	end = fopen("c:\\out.txt", "w"); //받을 파일을 쓰기로 열어준다

	while (fgets(changefileline, sizeof(changefileline), changefile) != NULL)
	{//수정표를 읽어 첫째 줄 부터 파일 끝까지 읽어 그 단어가 존재하는지 찾는다
		char* chnum = strtok(changefileline, " ");
		strcpy(oldword, chnum);
		chnum = strtok(NULL, " ");
		strcpy(change, chnum);
		//파일을 한줄씩 빼내어 찾을 단어와 수정할 단어를 나누어 저장

		eng = fopen("c:\\in.txt", "r");
		end = fopen("c:\\out.txt", "w");
		//수정전(in)파일을 읽기전용, 수정후 정보를 out파일에 저장한다

		while (fgets(fileline, sizeof(fileline), eng) != NULL)
		{//수정 전 파일을 한줄씩 저장한다
			char* orderstring = strtok(fileline, " "); //분석할 해당 문자열(줄) 띄어쓰기 기준으로 자른다
			while (orderstring != NULL) //자른 값이 비어있지 않다면(끝지점) 반복
			{
				if (strcmp(orderstring, oldword) == 0)
				{//자른 문자열(orderstring)이 찾고자 하는 값(oldword)과 같은가?
					fprintf(end, "%s ", change); //같다면 바꿀 단어로 출력
				}
				else
				{
					fprintf(end, "%s ", orderstring); //아니면 기존 문자열 출력
				}
				orderstring = strtok(NULL, " "); //널 값을 기준으로 띄어쓰기 기준으로 잘라 문자열에 저장
			}
		}
		fclose(eng);
		fclose(end);
		//두 파일을 닫아 현재 정보를 저장한다

		end = fopen("c:\\out.txt", "r"); //수정된 파일을 읽기로 연다
		eng = fopen("c:\\in.txt", "w"); //수정 전 파일을 쓰기로 연다
		while (fgets(fixstring, sizeof(fixstring), end) != NULL)
		{
			fprintf(eng, "%s", fixstring);
		}
		fclose(eng);
		fclose(end);
		//해당 구문의 의의 : 해당 프로그램은 크게 보면 수정표가 반복되면서 수정이 이루어 진다.
		//이에 수정표의 첫째 줄 수정이 끝나면 수정된 정보가 수정 전 정보가 되며 그 수정된 정보를 기준으로
		//수정표를 다음 줄로 넘겨 반복이 이루어 진다. 
	}
	fclose(eng);
	fclose(changefile);
	fclose(end);
}