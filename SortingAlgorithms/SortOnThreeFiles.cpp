#define UI unsigned int
#include "romkagaiLib.h"
#include <iostream>

//�������: ������������ ���������� �� ���� ������

//�������� ����� � ������� � ��������� �� left �� right
void CreateFile(const char* name, int n, int lf, int rt)
//name � ��� �����, n � ���������� �����, lf � ����� �������, rt - ������ �������
{
	int x, i; FILE* f;
	fopen_s(&f, name, "w");
	if (f == NULL) { perror("error opening file in CreateFile"); exit(1); }
	else {
		for (i = 0; i < n; i++)
		{
			x = rand() % (rt - lf + 1) + lf; fprintf(f, "%d ", x);
		}
		fclose(f);
	}
}

//����������� ����� 
void CopyFile(FILE* from, FILE* to)
{
	int x;
	while (fscanf_s(from, "%d", &x) != EOF) fprintf(to, "%d ", x);
}

//������ ����������� �����
void PrintFile(const char* name)
{
	FILE* f; int x;
	fopen_s(&f, name, "r");
	if (f == NULL) {
		puts("ERROR");
		_getch();
	}
	else {
		while (fscanf_s(f, "%d", &x) != EOF) printf("%d ", x);
		fclose(f);
	}
}


int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");

	int kolvo, lf, rt;
	int x1, x2, y1, y2, n;
	FILE* F; FILE* G1; FILE* G2; FILE* HELPER;

	cout << "���������� ������������ �������� �� ������� ������" << endl;
	cout << "������� ���������� ��������� � �������� �����:" << endl;

	cin >> kolvo;

	printf("������� ��� �����: ����� � ������ ������� ������������ ����� ��������������:\n");
	cout << "�����: ";
	cin >> lf;
	cout << "������ ";
	cin >> rt;

	CreateFile("F.txt", kolvo, lf, rt);
	printf("\n�������� ���� ����� ���:\n");
	PrintFile("F.txt");

	while (true)
	{
		// �������� ������ ��� ���������
		fopen_s(&F, "F.txt", "r");
		fopen_s(&G1, "G1.txt", "w");
		fopen_s(&G2, "G2.txt", "w");

		// ��������� ��������� �����
		n = 1;
		fscanf_s(F, "%d", &x1);
		while (!feof(F))
		{
			HELPER = n ? G1 : G2; // ��������� ��������. ���� n=1 - ������ �������� true � G1, ���� n=0 - ������ �������� false � G2;
			fprintf(HELPER, "%d ", x1);
			while (fscanf_s(F, "%d", &x2) != EOF && x2 >= x1)
			{
				x1 = x2;
				fprintf(HELPER, "%d ", x1);
			}
			x1 = x2; n = 1 - n;
		}

		//��������� ����� ����� ���������
		_fcloseall();

		//�������� ����� G2 �� �������
		fopen_s(&G2, "G2.txt", "r");
		if (fscanf_s(G2, "%d", &x1) == EOF) {
			puts("\n\nG2.txt - ����! ���������� ���������. ���� G1.txt - ����� ��������������� ����:");
			PrintFile("G1.txt");
			fclose(G2);
			_getch();
			break;
		}

		//�������� ������ ��� �������
		fopen_s(&G2, "G2.txt", "r");
		fopen_s(&F, "F.txt", "w");
		fopen_s(&G1, "G1.txt", "r");

		//�������: ����� x1 � y1 ���� �������� ��������� �� G1; x2 � y2 ���� �������� ��������� �� G1
		fscanf_s(G1, "%d", &x1);
		fscanf_s(G2, "%d", &x2);
		while (!feof(G1) && !feof(G2))
		{
			if (x1 < x2)											//���������� ������ ��� �������� ������������ ������������� ��������
			{
				fprintf(F, "%d ", x1);								//���� ������ �� G1 ������, �� �� ����������� � F
				fscanf_s(G1, "%d", &y1);							//��������� ��������� �� ��� �������
				if (!feof(G1) && x1 <= y1) 
				{
					x1 = y1;										//���� ��������� ������� ������ �������, �� �� "�����" ������; ������� � (x1<x2)
				}
				else
				{
					fprintf(F, "%d ", x2);							//���� � G1 "����������" �������, �� ������� �� G2 ��������� �������������� � F
					fscanf_s(G2, "%d", &y2);
					while (!feof(G2) && x2 <= y2)
					{
						x2 = y2;
						fprintf(F, "%d ", x2);
						fscanf_s(G2, "%d", &y2);
					}
					x1 = y1; x2 = y2;								//����� ��������� ���� ��������. ������� � ��������� ����.
				}
			}
			else													//---------------------------------------------------------------------
			{
				fprintf(F, "%d ", x2);								//���� ������ �� G2 ������, �� �� ����������� � F
				fscanf_s(G2, "%d", &y2);							//��������� ��������� �� ��� �������
				if (!feof(G2) && x2 <= y2)
				{
					x2 = y2;										//���� ��������� ������� ������ �������, �� �� "�����" ������; ������� � (x1<x2)
				}
				else
				{
					fprintf(F, "%d ", x1);							//���� � G2 "����������" �������, �� ������� �� G1 ��������� �������������� � F
					fscanf_s(G1, "%d", &y1);
					while (!feof(G1) && x1 <= y1)
					{
						x1 = y1;
						fprintf(F, "%d ", x1);
						fscanf_s(G1, "%d", &y1);
					}
					x1 = y1; x2 = y2;								//����� ��������� ���� ��������. ������� � ��������� ����.
				}
			}
		}
		while (!feof(G1))											//�������������� ������� ����� G1
		{
			fprintf(F, "%d ", x1);
			fscanf_s(G1, "%d", &y1);
			x1 = y1;
		}									
		while (!feof(G2))											//�������������� ������� ����� G2
		{
			fprintf(F, "%d ", x2);
			fscanf_s(G2, "%d", &y2);
			x2 = y2;
		}									

		//��������� ����� ����� �������
		_fcloseall();
	} 
	return(0);
	
	
	

}