#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	char name[20], name2[20]; //���ĺ��� ������ ���� name2�� name�� ���ĺ��� ���� ��
	FILE* eng; //�Է� ���� ����Ǵ� ����
	FILE* end; //���ڿ��� ���̸� ������ ����

	eng = fopen("c:\\in.txt", "w"); //����� ������ �����ش�

	gets(name, sizeof(name), stdin); //�Է¹޴´�(���ڿ�������, ���ڿ�ũ�⸸ŭ, ǥ���Է�����)

	fputs(name, eng); //gets�� �Է¹��� ���ڿ� ������ eng(in����)�� ����Ѵ�

	fclose(eng); //�Է¹��� ������ �ݴ´�

	//������ �о�� �ٸ� ���Ͽ� �ҷ�����


	eng = fopen("c:\\in.txt", "r"); //�Է¹��� ������ �б�� ����
	end = fopen("c:\\out.txt", "w"); //���� ������ ����� �����ش�

	fgets(name2, sizeof(name2), eng); //���������� �Է¹޴´�(name2������, �������̸�ŭ, eng(in)���Ͽ���)

	fprintf(end, "%s�� ���̴� %d�Դϴ�.", name2, strlen(name2)); //���������� �ش� ���Ͽ� ���

	fclose(eng);
	fclose(end);

}