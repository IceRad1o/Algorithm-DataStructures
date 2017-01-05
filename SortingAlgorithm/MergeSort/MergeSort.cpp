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
		//���õݹ�Ĺ���
	}
}

//�ǵݹ�Ĺ��̣�
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
	/*ֵ��һ���������������������ڱ��������漰���ĸ����������������
	�鲢���������飬�������������һ��������Ϊ����󼴿�
	(��Ϊδ���������������ȽϿ϶��ȷ������Ľ������)
	
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