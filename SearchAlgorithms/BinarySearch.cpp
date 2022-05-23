#define UI unsigned int
#include "romkagaiLib.h"

// �������� ����� � ������������� ������������ �������
int BinarySearch(int* a, int n, int k)
{
	int L = 0, R = n - 1;
	int m = (L + R) / 2;
	while (L <= R && a[m] != k)
	{
		m = (L + R) / 2;
		if (a[m] == k) return m;
		if (a[m] > k) R = m - 1;
		else L = m + 1;
	}
	if (L > R) return (-1);
}
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int n,k;

	puts("������� ���������� ��������� �������:");
	
	scanf_s("%d", &n);
	int* A = new int[n];
	puts("�������� �������:");

	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 100 + 1;
		printf("[%.d] ", A[i]);         //��������� ������ n ���������� ������� �� 1 �� 100
	}

	puts("\n������ �� �����������:");   //����������� � ������� ������
	InsertionSort(A, n);

	puts("\n������� ������� �������:"); // ���� �������� ��������
	scanf_s("%d", &k);

	int result = BinarySearch(A, n, k)+1;  // ���������� �������� ��������� ������
	if (result != 0) printf("������� ���������� �� %d-�� ����� �������", result);
	else puts("������! �������� ��� � �������");
	
}