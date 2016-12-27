#include<iostream>
#include<ctime>
#include<iomanip>
#include"InsertSort.h"
using namespace std;
//initialization
InsertSort::InsertSort(int arraysize) {
	cout << "constructor" << endl;
	size = (arraysize > 0 ? arraysize : 10);
	srand(time(0));
	arr = new int[size];
	for (int counter = 0;counter < size;counter++)
	{
		arr[counter] = rand() % 100 + 1;

	}
}
//small->big
void InsertSort::insertsort() {
	DisplayElements(0, size);
	int x = 0;
	for (int i = 1; i < size;i++)
	{
		for (int j = i;j>0;j--)
		{
			if (arr[j] < arr[j - 1])
			{
				x = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = x;
			}
		}
		DisplayElements(0, size);
	}
}

void InsertSort::DisplayElements(int low, int high) const
{
	for (int i = low;i < high;i++)
	{
		cout << " " << arr[i];
	}
	cout << endl;
}
InsertSort::~InsertSort() {
	delete[] arr;
	cout << "destructor " << endl;
}

