#define UI unsigned int

int CreateStepsArray(int* step, int n);
void ShellSort(int* a, int n);


// Сортировка Шелла
int main()
{
start:
	setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(nullptr)));
	//~~~~~~~~~~~~~~~~~~
	int n;
	cout << "Введите количество элементов: ";
	cin >> n;
	cout << "Ваш случайный массив: " << endl;
	int* mas = new int[n];
	for (int i = 0; i < n; i++)
	{
		mas[i] = rand() % 100 - 50;
		cout << mas[i] << " " ;
	}
	cout << endl;
	//~~~~~~~~~~~~~~~~~~
	ShellSort(mas, n);  //Сортировка Шелла
	//~~~~~~~~~~~~~~~~~~
	cout << endl << "Массив, упорядоченный сортировкой Шелла: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	//~~~~~~~~~~~~~~~~~~
}

int CreateStepsArray(int* step, int n) //Формируем массив шагов используя формулы 
{
	int i = -1;
	do
	{
		i++;
		if (i % 2 == 0) step[i] = 9 * pow(2, i) - 9 * pow(2, i / 2) + 1;
		else step[i] = 8 * pow(2, i) - 6 * pow(2, (i + 1) / 2) + 1;
	} while (3 * step[i] < n);
	return i;
}
void ShellSort(int* a, int n)	//Алгоритм сортировки
{
	int step[100]; int p, i, q, j, x, m;
	m = CreateStepsArray(step, n);	//Вызываем функцию для создания массива шагов, так же узнаем номер
									//Последнего элемента этого массива(начиная с 0)
	
	for (p = m - 1; p >= 0; p--)
	{
		q = 0;
		if (q < step[p])						//Если выполняется данное условие, то начинаем сортировку массива следующего		
		{										//Вида: a[q]; a[q+step[p]]; a[q+2*step[p]]...
			j = q + step[p];					//Методом прямой вставки
			while (j < n)
			{
				i = j - step[p]; x = a[j];
				while (i >= 0 && a[i] > x)
				{
					a[i + step[p]] = a[i];
					i -= step[p];
				}
				a[i + step[p]] = x;
				j += step[p];
			}
			q++;
		}
	}
}

