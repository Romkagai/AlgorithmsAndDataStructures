#define UI unsigned int
#include "romkagaiLib.h"

//Ñîðòèðîâêà ìàññèâà ìåòîäîì ïðÿìîé âñòàâêè è ìåòîäîì ïðÿìîé âñòàâêè ñ áèíàðíûì ïîèñêîì 

int main() {

	clock_t start, stop; double T;
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int* mas1, * mas2, * mas3, * mas4, *mas5;
	int n;
	cout << "Ââåäèòå êîëè÷åñòâî ýëåìåíòîâ ìàññèâà\n";
	cin >> n;

	mas1 = new int[n]; mas2 = new int[n];
	mas3 = new int[n]; mas4 = new int[n];
	mas5 = new int[n];

	if (n < 51) cout << "Èñõîäíûé ìàññèâ\n";
	for (int i = 0; i < n; i++)
	{
		mas1[i] = rand() % 100 + 1;			
		if (n<51) cout << mas1[i] << " ";				
	}
	

	//Ñîðòèðîâêà âñòàâêàìè
	for (int i = 0; i < n; i++) { mas2[i] = mas1[i];}
	start = clock();
	InsertionSort(mas2, n);
	stop = clock();
	T = (stop - start + .0) / CLOCKS_PER_SEC;
	if (n < 51)  
	{
		cout << "\n\nÌàññèâ: ñîðòèðîâêà âñòàâêîé\n";
		for (int i = 0; i < n; i++) cout << mas2[i] << " ";
	}
	cout << "\nÂðåìÿ âûïîëíåíèÿ ñîðòèðîâêè âñòàâêàìè íà " << n << " ýëåìåíòîâ = " << T << endl;
	delete[] mas2;

	//Ñîðòèðîâêà âñòàâêàìè ñ áèíàðíûì ïîèñêîì 
	for (int i = 0; i < n; i++) { mas3[i] = mas1[i];}
	start = clock();
	InsertionBinarySort(mas3[], n);
	stop = clock();
	T = (stop - start + .0) / CLOCKS_PER_SEC;
	if (n < 51)
	{
		cout << "\nÌàññèâ: ñîðòèðîâêà âñòàâêîé ñ áèíàðíûì ïîèñêîì\n";
		for (int i = 0; i < n; i++) cout << mas3[i] << " ";
	}
	cout <<"\nÂðåìÿ âûïîëíåíèÿ ñîðòèðîâêè âñòàâêàìè c áèíàðíûì ïîèñêîì íà " << n << " ýëåìåíòîâ = "  << T << endl;
	delete[] mas3;

	//Ñîðòèðîâêà ïóçûðüêîì
	for (int i = 0; i < n; i++) {mas4[i] = mas1[i];}
	start = clock();
	BubbleSort(mas4, n);
	stop = clock();
	T = (stop - start + .0) / CLOCKS_PER_SEC;
	if (n < 51)
	{
		cout << "\nÌàññèâ: ñîðòèðîâêà ïóçûðüêîì\n";
		for (int i = 0; i < n; i++) cout << mas4[i] << " ";
	}
	cout << "\nÂðåìÿ âûïîëíåíèÿ ñîðòèðîâêè ïóçûðüêîì íà " << n << " ýëåìåíòîâ = " << T << endl;
	delete[] mas4;

	//Ñîðòèðîâêà øåéêåðîì
	for (int i = 0; i < n; i++) { mas5[i] = mas1[i];}
	start = clock();
	ShakerSort(mas5, n);
	stop = clock();
	T = (stop - start + .0) / CLOCKS_PER_SEC;
	if (n < 51)
	{
		cout << "\nÌàññèâ: ñîðòèðîâêà øåéêåðîì\n";
		for (int i = 0; i < n; i++) cout << mas5[i] << " ";
	}
	cout << "\nÂðåìÿ âûïîëíåíèÿ ñîðòèðîâêè øåéêåðîì íà " << n << " ýëåìåíòîâ = "  << T << endl;
	delete[] mas5;
}
