#include"SelectionSort.h"
#include<iostream>
#include<ctime>
SelectionSort::SelectionSort(int arraysize) {
	size = (arraysize > 0 ? arraysize : 10);
	srand(time(0));
	for (int i = 0;i < size;i++)
	{
		data.push_back(rand() % 100 + 1);
	}
}
void SelectionSort::selectionsort() {
//small->big
	int iterator = 0;
	cout << "initialization: ";
	DisplayElements(0, size - 1);
	cout << endl;
	for (int i = 0;i < size-1;i++)
	{
		int min = i;
		for (int j = i+1;j < size;j++)
		{
			if(data[j]<data[min])
			{
				min = j;
			}
			iterator++;
			cout << "the min is" << data[min] << endl;
		}
		cout << "iterator: " << iterator << endl;
		int temp = data[i];
		data[i] = data[min];
		data[min] = temp;
		DisplayElements(0, size - 1);
	}
}

void SelectionSort::DisplayElements(int low, int high) const
{
	for (int i = low;i < high;i++)
	{
		cout << " " << data[i];
	}
	cout << endl;
}