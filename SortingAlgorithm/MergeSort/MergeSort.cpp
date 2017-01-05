#include"MergeSort.h"
#include<ctime>
#include<iostream>
using namespace std;
MergeSort::MergeSort(int arraysize)
{
	size = (arraysize > 0 ? arraysize : 10);
	srand(time(0));
	for(int i=0;i<size;i++)
	{
		data.push_back(rand() % 100 + 1);
	}
}
void MergeSort::mergesort()
{
	sortSubVector(0, size - 1);
}
//recursive function to sort subvectors
void MergeSort::sortSubVector(int low, int high)
{
	if((high - low) >= 1)
	{
		int middle1 = (low + high) / 2;
		int middle2 = middle1 + 1;
		cout << "split:    ";
		displaySubVector(low, high);
		cout << endl << "        ";
		displaySubVector(low, middle1);
		cout << endl << "          ";
		displaySubVector(middle2, high);
		cout << endl << endl;
		sortSubVector(low, middle1);
		sortSubVector(middle2, high);
		merge(low, middle1, middle2, high);
		//理解好递归的过程
	}
}

//非递归的过程？
void MergeSort::sortSubVectorNotrec(int low, int high){}

void MergeSort::merge(int left, int middle1, int middle2, int right)//merge two sorted subvectors into one sorted subvector
{
	int leftIndex = left;
	int rightIndex = middle2;
	int combinedIndex = left;
	vector<int> combined(size);

	cout << "merge:    ";
	displaySubVector(left, middle1);
	cout << endl << "          ";
	displaySubVector(middle2, right);
	cout << endl;

	while ((leftIndex <= middle1) && (rightIndex <= right))
	{
		if(data[leftIndex]<=data[rightIndex])
		{
			combined[combinedIndex++] = data[leftIndex++];
		}
		else
		{
			combined[combinedIndex++] = data[rightIndex++];
		}
	}//end while
	if (leftIndex == middle2)
	{
		while (rightIndex <= right)
			combined[combinedIndex++] = data[rightIndex++];
	}
	else
	{
		while (leftIndex <= middle1)
			combined[combinedIndex++] = data[leftIndex++];
	}
	/*值得一提的是我们这里可以设置哨兵来避免涉及到哪个数组先跑完的问题
	归并的两个数组，把数组新增最后一个数并设为无穷大即可
	(因为未跑完的数组和无穷大比较肯定先放入最后的结果数组)
	
	*/
	for (int i = left;i <= right;i++)
		data[i] = combined[i];
	cout << "          ";
	displaySubVector(left, right);
	cout << endl << endl;
}
void MergeSort::displaySubVector(int low, int high) const
{
	for (int i = 0;i < low;i++)
	{
		cout<<"  ";
	}
	for (int i = low;i <= high;i++)
	{
		cout << " " << data[i];
	}
}
void MergeSort::DisplayElements()const
{
	displaySubVector(0, size - 1);
}