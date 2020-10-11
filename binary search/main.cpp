#include <Windows.h>
#include <iostream>
#include <clocale>

using namespace std;


void input_array(int* a, int n)
{
	cout << "Введите массив: " << endl;
	for(int i = 0; i<n; i++)
	{
		cin >> a[i];
	}
}


void output_array(int *a, int n)
{
	for(int i = 0; i<n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}


void bubble_sort(int*a , int n)
{
	int temp = 0;
	for(int i =0 ; i<n-1; i++)
	{
		bool flag = true;
		for(int j =0; j<n-i-1; j++)
		{
			if(a[j] > a[j+1])
			{
				flag = false;
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
			if (flag)
				break;
		}
	}
}



int binary_search(int*a, int n, int item)
{
	int low = 0;
	int hight = n;

	int mid = 0; 
	int guess = 0;

	while(low <= hight)
	{
		mid = (low + hight)/2;
		guess = a[mid];
		if(guess == item)
			return mid;
		if(guess > item)
			low = mid + 1;
		else 
			hight = mid - 1;
	}
	return mid;
}





int main()
{
	setlocale(0, "");

	int n;
	cout << "Ведите количество элементов в массиве: ";
	cin >> n;

	int *a = new int[n];

	input_array(a, n);
	cout << "Массив: " << endl;
	output_array(a, n);

	bubble_sort(a, n);

	cout << "Отсортированный массив: " << endl;
	output_array(a, n);

	int item;
	cout << "Введите элемент, который хотите найти : " << endl;
	cin >> item;

	cout << "Индекс искомого элемента: " << binary_search(a, n , item) << endl;

	

	delete[] a;
	
	system("pause");
	return 0;
}

