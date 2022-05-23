#define UI unsigned int
#include "romkagaiLib.h"
#include <iostream>

//Условие: Естественная сортировка на трех файлах

//Создание файла с числами в диапазоне от left до right
void CreateFile(const char* name, int n, int lf, int rt)
//name – имя файла, n – количество чисел, lf – левая граница, rt - правая граница
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

//Копирование файла 
void CopyFile(FILE* from, FILE* to)
{
	int x;
	while (fscanf_s(from, "%d", &x) != EOF) fprintf(to, "%d ", x);
}

//Печать содержимого файла
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

	cout << "Сортировка естественным слиянием на четырех файлах" << endl;
	cout << "Введите количество элементов в исходном файле:" << endl;

	cin >> kolvo;

	printf("Введите два числа: левая и правая граница генерируемых чисел соответственно:\n");
	cout << "Левая: ";
	cin >> lf;
	cout << "Правая ";
	cin >> rt;

	CreateFile("F.txt", kolvo, lf, rt);
	printf("\nИсходный файл имеет вид:\n");
	PrintFile("F.txt");

	while (true)
	{
		// Открытие файлов для разбиения
		fopen_s(&F, "F.txt", "r");
		fopen_s(&G1, "G1.txt", "w");
		fopen_s(&G2, "G2.txt", "w");

		// Разбиение исходного файла
		n = 1;
		fscanf_s(F, "%d", &x1);
		while (!feof(F))
		{
			HELPER = n ? G1 : G2; // Тернарный оператор. Если n=1 - вернет значение true и G1, если n=0 - вернет значение false и G2;
			fprintf(HELPER, "%d ", x1);
			while (fscanf_s(F, "%d", &x2) != EOF && x2 >= x1)
			{
				x1 = x2;
				fprintf(HELPER, "%d ", x1);
			}
			x1 = x2; n = 1 - n;
		}

		//Закрываем файлы после разбиения
		_fcloseall();

		//Проверка файла G2 на пустоту
		fopen_s(&G2, "G2.txt", "r");
		if (fscanf_s(G2, "%d", &x1) == EOF) {
			puts("\n\nG2.txt - пуст! Сортировка завершена. Файл G1.txt - новый отсортированный файл:");
			PrintFile("G1.txt");
			fclose(G2);
			_getch();
			break;
		}

		//Открытие файлов для слияния
		fopen_s(&G2, "G2.txt", "r");
		fopen_s(&F, "F.txt", "w");
		fopen_s(&G1, "G1.txt", "r");

		//Слияние: Здесь x1 и y1 пара соседних элементов из G1; x2 и y2 пара соседних элементов из G1
		fscanf_s(G1, "%d", &x1);
		fscanf_s(G2, "%d", &x2);
		while (!feof(G1) && !feof(G2))
		{
			if (x1 < x2)											//Сравниваем первые два элемента сравниваемых упорядоченных отрезков
			{
				fprintf(F, "%d ", x1);								//Если первый из G1 меньше, то он перепишется в F
				fscanf_s(G1, "%d", &y1);							//Считается следующий за ним элемент
				if (!feof(G1) && x1 <= y1) 
				{
					x1 = y1;										//Если следующий элемент больше первого, то он "новый" первый; возврат к (x1<x2)
				}
				else
				{
					fprintf(F, "%d ", x2);							//Если в G1 "закончился" отрезок, то отрезок из G2 полностью переписывается в F
					fscanf_s(G2, "%d", &y2);
					while (!feof(G2) && x2 <= y2)
					{
						x2 = y2;
						fprintf(F, "%d ", x2);
						fscanf_s(G2, "%d", &y2);
					}
					x1 = y1; x2 = y2;								//Конец сравнения пары отрезков. Переход к следующей паре.
				}
			}
			else													//---------------------------------------------------------------------
			{
				fprintf(F, "%d ", x2);								//Если первый из G2 меньше, то он перепишется в F
				fscanf_s(G2, "%d", &y2);							//Считается следующий за ним элемент
				if (!feof(G2) && x2 <= y2)
				{
					x2 = y2;										//Если следующий элемент больше первого, то он "новый" первый; возврат к (x1<x2)
				}
				else
				{
					fprintf(F, "%d ", x1);							//Если в G2 "закончился" отрезок, то отрезок из G1 полностью переписывается в F
					fscanf_s(G1, "%d", &y1);
					while (!feof(G1) && x1 <= y1)
					{
						x1 = y1;
						fprintf(F, "%d ", x1);
						fscanf_s(G1, "%d", &y1);
					}
					x1 = y1; x2 = y2;								//Конец сравнения пары отрезков. Переход к следующей паре.
				}
			}
		}
		while (!feof(G1))											//Переписывается остаток файла G1
		{
			fprintf(F, "%d ", x1);
			fscanf_s(G1, "%d", &y1);
			x1 = y1;
		}									
		while (!feof(G2))											//Переписывается остаток файла G2
		{
			fprintf(F, "%d ", x2);
			fscanf_s(G2, "%d", &y2);
			x2 = y2;
		}									

		//Закрываем файлы после слияния
		_fcloseall();
	} 
	return(0);
	
	
	

}