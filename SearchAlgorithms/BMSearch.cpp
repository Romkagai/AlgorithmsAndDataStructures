#define UI unsigned int
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include <locale>
#include <iostream>
#include <time.h>
#include <iomanip>
#include <string.h>
using namespace std;
// Поиск слова в тексте используя БМ-Поиск

int main()
{
start:
	//setlocale(LC_ALL, "Russian");
	srand(time(NULL));


	char p[40];
	char s[200];
	cout << "Алгоритм Бойера-Мура поиска подстроки в строке" << endl;
	cout << "Введите ваш текст\n";
	gets(s);

	cout << "Искомое слово\n";
	gets(p);

	int result = -1;
	int TAB[256], i, j, m, n, k;
	m = strlen(p);		//Длина слова
	n = strlen(s);		//Длина текста

	for (i = 0; i < 256; i++)
	{
		TAB[i] = m;
	}
	//Создаём таблицу смещений
	for (i = 0; i < m - 1; i++)
	{
		TAB[p[i]] = m - i - 1;
	}

	//Алгоритм БМ-Поиска без флага
	for (i = m - 1; i <= n; i = i + TAB[s[k]])
	{
		for (k = i, j = m - 1; j >= 0 && s[k] == p[j]; k--, j--);
		{
			if (j < 0)
			{
				result = i - m + 1; break;
			}
		}
	}
	if (result != -1) cout << "Слово начинается с " << result << " символа" << endl;
	else cout << "Слова нет в тексте!!!" << endl;


	cout << "Хотите запустить программу заново? (y - да, любая другая клавиша - выйти из программы)" << endl;
	char ch;									//Повторный запуск программы
	cin >> ch;
	while (getchar() != '\n');					//Очистка буфера
	if (ch == 'y') { system("cls"); goto start; }


}


