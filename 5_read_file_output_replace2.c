#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


int main()
{
	char oldword[50], fileline[50], changefileline[50], change[50], fixstring[50];
	int i = 0;
	//oldword�� �ٲٱ� �� �ܾ�, change�� �ٲ� �ܾ�, fileline�� ���� �� ������ ������ ���پ� �ٷ� ����
	//changefileline�� ����ǥ�� ���ڿ��� �ٷ� ����, fixstring�� n�� ������ ����� �ű�� �۾��� ���´�
	FILE* eng; //���� �� ����
	FILE* changefile; //������ �ܾ �����ϴ� ����
	FILE* end; //�Է� ���� ������ �о� ����� ����� ����

	eng = fopen("c:\\in.txt", "r"); //���� �� ������ �б�� ����
	changefile = fopen("c:\\changefile.txt", "r"); //������ �ܾ ������ ������ �б�� ����
	end = fopen("c:\\out.txt", "w"); //���� ������ ����� �����ش�

	while (fgets(changefileline, sizeof(changefileline), changefile) != NULL)
	{//����ǥ�� �о� ù° �� ���� ���� ������ �о� �� �ܾ �����ϴ��� ã�´�
		char* chnum = strtok(changefileline, " ");
		strcpy(oldword, chnum);
		chnum = strtok(NULL, " ");
		strcpy(change, chnum);
		//������ ���پ� ������ ã�� �ܾ�� ������ �ܾ ������ ����

		eng = fopen("c:\\in.txt", "r");
		end = fopen("c:\\out.txt", "w");
		//������(in)������ �б�����, ������ ������ out���Ͽ� �����Ѵ�

		while (fgets(fileline, sizeof(fileline), eng) != NULL)
		{//���� �� ������ ���پ� �����Ѵ�
			char* orderstring = strtok(fileline, " "); //�м��� �ش� ���ڿ�(��) ���� �������� �ڸ���
			while (orderstring != NULL) //�ڸ� ���� ������� �ʴٸ�(������) �ݺ�
			{
				if (strcmp(orderstring, oldword) == 0)
				{//�ڸ� ���ڿ�(orderstring)�� ã���� �ϴ� ��(oldword)�� ������?
					fprintf(end, "%s ", change); //���ٸ� �ٲ� �ܾ�� ���
				}
				else
				{
					fprintf(end, "%s ", orderstring); //�ƴϸ� ���� ���ڿ� ���
				}
				orderstring = strtok(NULL, " "); //�� ���� �������� ���� �������� �߶� ���ڿ��� ����
			}
		}
		fclose(eng);
		fclose(end);
		//�� ������ �ݾ� ���� ������ �����Ѵ�

		end = fopen("c:\\out.txt", "r"); //������ ������ �б�� ����
		eng = fopen("c:\\in.txt", "w"); //���� �� ������ ����� ����
		while (fgets(fixstring, sizeof(fixstring), end) != NULL)
		{
			fprintf(eng, "%s", fixstring);
		}
		fclose(eng);
		fclose(end);
		//�ش� ������ ���� : �ش� ���α׷��� ũ�� ���� ����ǥ�� �ݺ��Ǹ鼭 ������ �̷�� ����.
		//�̿� ����ǥ�� ù° �� ������ ������ ������ ������ ���� �� ������ �Ǹ� �� ������ ������ ��������
		//����ǥ�� ���� �ٷ� �Ѱ� �ݺ��� �̷�� ����. 
	}
	fclose(eng);
	fclose(changefile);
	fclose(end);
}