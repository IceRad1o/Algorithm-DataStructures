#include"BubbleSort.h"
#include<iostream>
#include<ctime>
using namespace std;
BubbleSort::BubbleSort(int arraysize) {
	size = (arraysize > 0 ? arraysize : 10);
	srand(time(0));
	for (int i = 0;i < size;i++)
	{
		data.push_back(rand() % 100 + 1);
	}
}
void BubbleSort::bubblesort() {
	static int temp = 0;
	for (int j = 0;j <size-1;j++) {
		for (int i = 0;i < size-1-j ;i++)
		{
			if (data[i] > data[i + 1])
			{
				int x = data[i];
				data[i] = data[i + 1];
				data[i + 1] = x;
			}
			DisplayElements(0, size);
			temp++;
		}
		cout << "iterator: " << temp<< endl;
	}
}

void BubbleSort::DisplayElements(int low, int high) const
{
	for (int i = low;i < high;i++)
	{
		cout << " " << data[i];
	}
	cout << endl;
}