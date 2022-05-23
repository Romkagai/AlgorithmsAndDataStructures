#define UI unsigned int
#include "romkagaiLib.h"

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