#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int*a , const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
	cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}
void SortArray1(int* arr1, int* arr2, const int size, int i, int& j)
{
	if (i < size)
	{
		if (i % 2 == 0)
		{
			arr2[j] = arr1[i];
			j++;
			SortArray1(arr1, arr2, size, i + 1, j);
		}
		else
			SortArray1(arr1, arr2, size, i + 1, j);
	}
}

void SortArray2(int* arr1, int* arr2, const int size, int i, int& j)
{
	if (i < size)
	{
		if (i % 2 != 0)
		{
			arr2[j] = arr1[i];
			j++;
			SortArray2(arr1, arr2, size, i + 1, j);
		}
		else
			SortArray2(arr1, arr2, size, i + 1, j);
	}
}
void IndexMax(const int* a, int size, int& index, int i)
{
	if (i < size)
	{
		if (a[i] > a[index]) {
			index = i;
		}
		IndexMax(a, size, index, i + 1);
	}
}

int FindNull(int* a, const int size, int i, int Inull1)
{
	if (i < size)
	{
		if (a[i] == 0)
		{
			Inull1 = i;
			return Inull1;
		}
		else
			return FindNull(a, size, i + 1, Inull1);
	}
	else
		return Inull1;
}


int Dobytok(int* a, const int size, int i)
{
	if (i < size)
	{
		return a[i] * Dobytok(a, size, i + 1);
	}
	else
		return 1;
}
int main()
{
	srand((unsigned)time(NULL));
	int n ; 
	int i;
	cout << "n = "; cin >> n;
	int Low;
	cout << "Low= "; cin >> Low;
	int High;
	cout << "High = "; cin >> High;
	int* a = new int[n];
	int* b = new int[n];
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	int index = 0;
	IndexMax(a, n, index, 0);
	cout << index << endl;
	int i1 = FindNull(a, n, 0, -1);
	int i2 = FindNull(a, n, i1 + 1, -1);

	if (i1 == -1 || i2 == -1)
	{
		cout << "nema nyliv" << endl;
		return 0;
	}

	cout << "Dobytok = " << Dobytok(a, i2, i1 + 1) << endl;
	int j = 0;
	for (int i = 0; i <n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	SortArray1(a, b, n, 0, j);
	SortArray2(a, b, n, 0, j);

	for (int i = 0; i <n; i++)
	{
		cout << b[i] << " ";
	}
	delete[] a;
	return 0;
}