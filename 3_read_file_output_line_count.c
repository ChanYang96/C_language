#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


int main()
{
	char name[50], name3[50]; //name�� ã�� �ܾ�, name3�� ���Ͽ��� �����ͼ� �м��� ���̴�
	int line = 0, word = 0; //line�� in������ �� ���� ��´�. word�� in������ �ܾ� ���� ��´�.
	FILE* eng; //�Է� ���� ����Ǵ� ����
	FILE* end; //���� ���� ������ �о� ����� ����� ����

	eng = fopen("c:\\in.txt", "r"); //�Է¹��� ������ �б�� ����
	end = fopen("c:\\out.txt", "w"); //���� ������ ����� �����ش�

	gets(name); //����â���� �ܾ �Է¹޴´�

	while (fgets(name3, sizeof(name3), eng) != NULL)
	{//���Ͽ��� �� ���� ������ ���ڿ� ������ ���� ���� �� ���� �ƴ϶�� �ݺ�
		line++; //���� ���� �ø���
		word = 0; //�ܾ� ��ġ �ʱ�ȭ

		char *name2 = strtok(name3, " "); //�м��� �ش� ���ڿ�(��) ���� �������� �ڸ���

		while (name2 != NULL) //�ڸ� ���� ������� �ʴٸ�(������) �ݺ�
		{
			word++; //�ܾ� �� ����(�ܾ� ��ġ �̵�)
			if (strcmp(name2, name) == 0) //�ڸ� ���ڿ�(name2)�� ã���� �ϴ� ��(name)�� ������?
			{
				fprintf(end, "%s�� %d �ٿ� %d ��° ����\n", name, line, word);
				//���ٸ� �� ������ ���
			}
				name2 = strtok(NULL, " "); //�� ���� �������� ���� �������� �߶� ���ڿ��� ����
		}
		
	}
	fclose(eng);
	fclose(end);
}