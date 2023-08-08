#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


int main()
{
	char name[100]; //name은 문자열을 담는다. 그리고 문자의 아스키 코드번호를 구분한다
	int word = 0, a = 0, num[500] = { 0 }; //word는 입력받은 문자열의 길이를 담고 a는 반복문을 위한 수
										 //num은 문자의 아스키코드 값 번호가 저장될 장소
	FILE* eng; //입력 값이 저장되는 파일
	FILE* end; //업력 받은 파일을 읽어 결과를 출력할 파일

	eng = fopen("c:\\in.txt", "w"); //쓰기로 파일을 열어준다

	while (1) { //특정 행동 없이 반복된다
		gets(name); //문자열을 입력 받는다. 공백도 포함해야 하므로 gets 함수 사용
		if (strcmp(name, "q") == 0) //입력 받은 문자가 q와 같은가? 같으면 반복문 중지
		{
			break;
		}
		word = strlen(name); //엔터 전 문자열의 길이를 저장한다
		for (a = 0; a < word; a++)//문자열의 길이만큼 반복한다
		{
			num[name[a]]++; //아스키코드의 정수-문자열 변화식에 의거 만약 'a'가 들어왔다면
			                //해당 배열은 num[97]에 1이 늘어나는 것이다
		}

		fputs(name, eng); //gets로 입력받은 문자열 변수를 eng(in파일)에 출력한다
		fputs("\n", eng); //한 줄을 입력하고 줄바꿈을 실행
	}

	fclose(eng); //입력받은 파일을 닫는다

	eng = fopen("c:\\in.txt", "r"); //입력받은 파일을 읽기로 연다
	end = fopen("c:\\out.txt", "w"); //받을 파일을 쓰기로 열어준다

	for (a = 65; a <= 122; a++)// 65('A') 부터 122('z(소문자)')까지 반복을 한다
	{
		if (num[a] > 0)// 해당 배열의 값이 0이 아닌가? 즉 한번이라도 나온적이 있는가?
		{
			fprintf(end, "%c : %d\n", a, num[a]); //있다면 해당 파일에 해당 알파벳과 수를 출력
		}
	}
}