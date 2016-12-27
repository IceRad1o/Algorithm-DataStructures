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

}

void SelectionSort::DisplayElements(int low, int high) const
{
	for (int i = low;i < high;i++)
	{
		cout << " " << data[i];
	}
	cout << endl;
}