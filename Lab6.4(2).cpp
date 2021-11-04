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
int maxInt(const int* a, int size)
{
	if (size == 1)
	{
		return 0;
	}
	int max = maxInt(a + 1, size - 1) + 1;
	return a[max] > *a ? max : 0;
}

/*int FindNull(int* a, const int size, int i, int Inull1, int Inull2, int d = 1)
{
	if (a[i] == 0 && a[Inull1]!=0)
	{
		Inull1 = i;
		return FindNull(a, size, i + 1, Inull1, Inull2);
	}
	if (a[i] == 0 && a[Inull2] != 0)
	{
		Inull2 = i;
		return FindNull(a, size, Inull1 + 1, Inull1, Inull2);
	}
	if (i < Inull2)
	{
		int i = Inull1 + 1;
		d *= a[i];
	return FindNull(a, size, i+1 , Inull1, Inull2 ,d);
	}
}*/
/*void SortArray(int* a, int* b, const int size, int j, int i)
{
	if ((i % 2) == 0)
	{
		b[j] = a[i];
		j + 1;
		if (i < size)
			return SortArray(a, b, size , j , i + 1);
	}
		if ((i % 2) != 0)
		{
			j + 1;
			b[j] = a[i];
			if (i < size)

				return SortArray(a, b, size , j 1, i + 1);
		}
	
}*/
int main()
{
	srand((unsigned)time(NULL));
	int n;
	int i;
	cout << "n = "; cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	int Low;
	cout << "Low= "; cin >> Low;
	int High;
	cout << "High = "; cin >> High;
	Create(a, n, Low, High,0);
	Print(a, n,0);
	int max = -1;
	int imax = 0;
	cout << "Imax = " << maxInt(a, n) << endl;
	//cout << "a*b = " << FindNull(a, n,0,0,0,1) << endl;
	//SortArray(a, b, n,0,0);
	//Print(b, n,0);
	delete[] a;
	delete[] b;
	return 0;
}