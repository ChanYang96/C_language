#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


int main()
{
	char name[100]; //name�� ���ڿ��� ��´�. �׸��� ������ �ƽ�Ű �ڵ��ȣ�� �����Ѵ�
	int word = 0, a = 0, num[500] = { 0 }; //word�� �Է¹��� ���ڿ��� ���̸� ��� a�� �ݺ����� ���� ��
										 //num�� ������ �ƽ�Ű�ڵ� �� ��ȣ�� ����� ���
	FILE* eng; //�Է� ���� ����Ǵ� ����
	FILE* end; //���� ���� ������ �о� ����� ����� ����

	eng = fopen("c:\\in.txt", "w"); //����� ������ �����ش�

	while (1) { //Ư�� �ൿ ���� �ݺ��ȴ�
		gets(name); //���ڿ��� �Է� �޴´�. ���鵵 �����ؾ� �ϹǷ� gets �Լ� ���
		if (strcmp(name, "q") == 0) //�Է� ���� ���ڰ� q�� ������? ������ �ݺ��� ����
		{
			break;
		}
		word = strlen(name); //���� �� ���ڿ��� ���̸� �����Ѵ�
		for (a = 0; a < word; a++)//���ڿ��� ���̸�ŭ �ݺ��Ѵ�
		{
			num[name[a]]++; //�ƽ�Ű�ڵ��� ����-���ڿ� ��ȭ�Ŀ� �ǰ� ���� 'a'�� ���Դٸ�
			                //�ش� �迭�� num[97]�� 1�� �þ�� ���̴�
		}

		fputs(name, eng); //gets�� �Է¹��� ���ڿ� ������ eng(in����)�� ����Ѵ�
		fputs("\n", eng); //�� ���� �Է��ϰ� �ٹٲ��� ����
	}

	fclose(eng); //�Է¹��� ������ �ݴ´�

	eng = fopen("c:\\in.txt", "r"); //�Է¹��� ������ �б�� ����
	end = fopen("c:\\out.txt", "w"); //���� ������ ����� �����ش�

	for (a = 65; a <= 122; a++)// 65('A') ���� 122('z(�ҹ���)')���� �ݺ��� �Ѵ�
	{
		if (num[a] > 0)// �ش� �迭�� ���� 0�� �ƴѰ�? �� �ѹ��̶� �������� �ִ°�?
		{
			fprintf(end, "%c : %d\n", a, num[a]); //�ִٸ� �ش� ���Ͽ� �ش� ���ĺ��� ���� ���
		}
	}
}