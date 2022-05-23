#define UI unsigned int
//Сортировка прямой вставкой
void InsertionSort(int* a, int n)
{
	int i, j;
	int temp = 0;
	for (i = 1; i < n; i++)
	{
		temp = a[i];
		for (j = i - 1; j >= 0 && a[j] > temp; j--)
			a[j + 1] = a[j];
		a[j + 1] = temp;
	}
}

//Сортировка прямой вставкой с бинарным поиском
void InsertionBinarySort(int a[], int n)
{
	int i, j, temp = 0, L, R, m;
	for (i = 1; i < n; i++)
	{
		temp = a[i]; L = 0; R = i;
		while (L < R)
		{
			m = (L + R) / 2;
			if (temp < a[m]) { R = m; }
			else { L = m + 1; }

		}
		for (j = i - 1; j >= R; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
}

//Сортировка пузырек
void BubbleSort(int* a, int n)
{
	int temp = 0;
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

}

//Сортировка шейкер
void ShakerSort(int* a, int n)
{
	int temp = 0;
	int left = 0, right = n - 1;
	int flag = 1;
	while ((flag == 1) && (left < right))
	{
		flag = 0;
		for (int i = left; i < right; i++)
		{
			if (a[i] > a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				flag = 1;
			}
		}
		right--;
		for (int i = right; i > left; i--)
		{
			if (a[i - 1] > a[i])
			{
				temp = a[i - 1];
				a[i - 1] = a[i];
				a[i] = temp;
				flag = 1;
			}
		}
		left++;
	}
}

//Сортировка массива методом прямой вставки и методом прямой вставки с бинарным поиском 

int main() {

	clock_t start, stop; double T;
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int* mas1, * mas2, * mas3, * mas4, *mas5;
	int n;
	cout << "Введите количество элементов массива\n";
	cin >> n;

	mas1 = new int[n]; mas2 = new int[n];
	mas3 = new int[n]; mas4 = new int[n];
	mas5 = new int[n];

	if (n < 51) cout << "Исходный массив\n";
	for (int i = 0; i < n; i++)
	{
		mas1[i] = rand() % 100 + 1;			
		if (n<51) cout << mas1[i] << " ";				
	}
	

	//Сортировка вставками
	for (int i = 0; i < n; i++) { mas2[i] = mas1[i];}
	start = clock();
	InsertionSort(mas2, n);
	stop = clock();
	T = (stop - start + .0) / CLOCKS_PER_SEC;
	if (n < 51) 
	{
		cout << "\n\nМассив: сортировка вставкой\n";
		for (int i = 0; i < n; i++) cout << mas2[i] << " ";
	}
	cout << "\nВремя выполнения сортировки вставками на " << n << " элементов = " << T << endl;
	delete[] mas2;

	//Сортировка вставками с бинарным поиском 
	for (int i = 0; i < n; i++) { mas3[i] = mas1[i];}
	start = clock();
	InsertionBinarySort(mas3[], n);
	stop = clock();
	T = (stop - start + .0) / CLOCKS_PER_SEC;
	if (n < 51)
	{
		cout << "\nМассив: сортировка вставкой с бинарным поиском\n";
		for (int i = 0; i < n; i++) cout << mas3[i] << " ";
	}
	cout <<"\nВремя выполнения сортировки вставками c бинарным поиском на " << n << " элементов = "  << T << endl;
	delete[] mas3;

	//Сортировка пузырьком
	for (int i = 0; i < n; i++) {mas4[i] = mas1[i];}
	start = clock();
	BubbleSort(mas4, n);
	stop = clock();
	T = (stop - start + .0) / CLOCKS_PER_SEC;
	if (n < 51)
	{
		cout << "\nМассив: сортировка пузырьком\n";
		for (int i = 0; i < n; i++) cout << mas4[i] << " ";
	}
	cout << "\nВремя выполнения сортировки пузырьком на " << n << " элементов = " << T << endl;
	delete[] mas4;

	//Сортировка шейкером
	for (int i = 0; i < n; i++) { mas5[i] = mas1[i];}
	start = clock();
	ShakerSort(mas5, n);
	stop = clock();
	T = (stop - start + .0) / CLOCKS_PER_SEC;
	if (n < 51)
	{
		cout << "\nМассив: сортировка шейкером\n";
		for (int i = 0; i < n; i++) cout << mas5[i] << " ";
	}
	cout << "\nВремя выполнения сортировки шейкером на " << n << " элементов = "  << T << endl;
	delete[] mas5;
}
