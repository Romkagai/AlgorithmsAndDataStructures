#include <iostream>
#include <math.h>
using namespace std;

int MaxRank(int *arr, int n)
{
    int k = 1;
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if(arr[i] > max) max = arr[i];
    }
    int mask = pow(2,32)-1;
    do
    {
        max >>= 1;
        k++;
    } while((mask & max) != 1);
        
    return k;
}

void BitSort(int* a, int l, int r, int k)
{
    if ((l >= r) || (k < 0)) return;
        else
        {
            int i = l;
            int j = r;
            int mask = 1;
            mask <<= k;
            while (i < j)
            {
                while ((i < j) && ((a[i] & mask) == 0)) {
                    i++;
                }
                while ((i < j) && ((a[j] & mask) != 0)) {
                    j--;
                }
                if (i < j) {
                    swap(a[i], a[j]);
                }
            }
            if ((a[r] & mask) == 0) {
                j++;
            }
            if (l < j) {
                BitSort(a, l, j - 1, k - 1);
            }
            if (i < r) {
                BitSort(a, i, r, k - 1);
            }
        }
}


int main ()
{
    setlocale(LC_ALL, "russian");
    srand( static_cast<unsigned int>(time(nullptr)));
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Неотсортированный массив:";
    
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    int k = MaxRank(arr, n);
    BitSort(arr, 0, n-1, k);
    
    cout << endl << "Отсортированный массив:";
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    
}
