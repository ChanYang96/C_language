#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


int main()
{
	char oldword[50], fileline[50], change[50], fixstring[50];
	//oldword�� �ٲٱ� �� �ܾ�, change�� �ٲ� �ܾ�, fileline�� ������ ���Ͽ� ����ϱ� ���� ���ڿ� ����
	FILE* eng; //�Է� ���� ����Ǵ� ����
	FILE* end; //���� ���� ������ �о� ����� ����� ����

	eng = fopen("c:\\in.txt", "r"); //�Է¹��� ������ �б�� ����
	end = fopen("c:\\out.txt", "w"); //���� ������ ����� �����ش�

	gets(oldword);
	gets(change);

	while (fgets(fileline, sizeof(fileline), eng) != NULL)
	{//���Ͽ��� �� ���� ������ ���ڿ� ������ ���� ���� �� ���� �ƴ϶�� �ݺ�
		char* orderstring = strtok(fileline, " "); //�м��� �ش� ���ڿ�(��) ���� �������� �ڸ���
		while (orderstring != NULL) //�ڸ� ���� ������� �ʴٸ�(������) �ݺ�
		{

			if (strcmp(orderstring, oldword) == 0)
			{//�ڸ� ���ڿ�(orderstring)�� ã���� �ϴ� ��(oldword)�� ������?
				fprintf(end, " %s", change); //���ٸ� �ٲ� �ܾ�� ���
			}
			else
			{
				fprintf(end, " %s", orderstring); //�ƴϸ� ���� ���ڿ� ���
			}
			orderstring = strtok(NULL, " "); //�� ���� �������� ���� �������� �߶� ���ڿ��� ����
		}
	}
	fclose(eng);
	fclose(end);
}