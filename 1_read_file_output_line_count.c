#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


int main()
{
	char name[50], name2, name3[50]; //name은 문자열을 담는다. name2는 문자를 담는다
	int line = 0, word = 0; //line은 in파일의 줄 수를 담는다. word는 in파일의 단어 수를 담는다.
	FILE* eng; //입력 값이 저장되는 파일
	FILE* end; //업력 받은 파일을 읽어 결과를 출력할 파일

	eng = fopen("c:\\in.txt", "w"); //쓰기로 파일을 열어준다

	while (1) { //특정 행동 없이 반복된다
		gets(name); //문자열을 입력 받는다. 공백도 포함해야 하므로 gets 함수 사용
		if (strcmp(name, "q") == 0) //입력 받은 문자가 q와 같은가? 같으면 반복문 중지
		{
			break;
		}
		fputs(name, eng); //gets로 입력받은 문자열 변수를 eng(in파일)에 출력한다
		fputs("\n", eng); //한 줄을 입력하고 줄바꿈을 실행
	}

	fclose(eng); //입력받은 파일을 닫는다

	//파일을 읽어내어 다른 파일에 불러낸다


	eng = fopen("c:\\in.txt", "r"); //입력받은 파일을 읽기로 연다
	end = fopen("c:\\out.txt", "w"); //받을 파일을 쓰기로 열어준다

	while ((name2 = fgetc(eng)) != EOF) 
	{//입력받은 파일에서 문자 하나씩 꺼내어 넣은 변수가 파일 끝에 도달하지 않았는가?
		// == 즉 해당 파일을 문자 하나씩 비교해 보았는가?
		if (name2 == '\n') //만약 현재 문자 함수에 담긴 값이 줄 바꿈 값이면 라인과 워드 값을 더한다
			// 워드값을 늘리는 이유는 줄 바꿈을 하면 또 다른 문자가 생기기 때문
		{
			line++;
			word++;
		}
		if (name2 == ' ') //만약 문자 함수에 담긴 값이 띄어쓰기 값이라면 워드의 값을 더한다
		{
			word++;
		}
	}
	fprintf(end, "해당 파일의 단어 수는 %d개 이며 길이는 %d줄 입니다.", word, line);
	//반복문으로 알아낸 값을 출력한다.
	fclose(eng);
	fclose(end);

}