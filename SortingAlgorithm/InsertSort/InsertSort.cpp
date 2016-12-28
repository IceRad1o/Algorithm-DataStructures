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
				/*这是插入时调换元素大小，但是每次不匹配都要进行两次交换
				我们可以通过设置哨兵，来减少交换次数,把要插入的值设成哨兵即可,也就是插入的元素只要插入一次,
				而原数组每次给后一位赋值，直到找到合适的插入位置
				*/
			}
		}
		DisplayElements(0, size);
	}
}
void InsertSort::insertsort2() {
	//设置哨兵的插入排序
	DisplayElements(0, size);
	for (int i = 1;i < size;i++)
	{
		if (arr[i] < arr[i - 1])
		{
			int x = arr[i];//设置哨兵
			arr[i] = arr[i - 1];//把前面一个数组的最后一个后移(因为前面肯定要插入一个)
			int j = i - 1;
			while (x < arr[j])
			{
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = x;
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

