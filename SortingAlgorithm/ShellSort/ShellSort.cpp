#include<iostream>
#include<ctime>
#include"ShellSort.h"
using namespace std;
ShellSort::ShellSort(int arraysize) {
	size = (arraysize > 0 ? arraysize : 10);
	srand(time(0));
	for (int i = 0;i < size;i++)
	{
		data.push_back(rand() % 100 + 1);
	}
}

void ShellSort::shellsort()
{
	cout << "初始化数据是:  " ;
	DisplayElements(0, size);
	int incr = size / 3 + 1;//初始化增量
	while (incr>=1)
	{
		int temp = 0;
		if (incr == 1) { temp++; }
	
		for (int i = incr;i < size;i++)//从每个数组的第二个元素开始往后遍历
		{
			
			if (data[i] < data[i - incr])
			{
				int index = data[i];//设置好哨兵
			    int j = i - incr;//保存好数组第一个的 索引
				while ((j>=0)&&(index < data[j]))//如果小于就比较下去
				{
					data[j + incr] = data[j];
					j -= incr;
				}
				data[j + incr] = index;
			}
			//对元素插入排序
		}
		DisplayElements(0, size);
		incr = incr / 3 + 1;//增量逐渐减少
		
		if (temp == 1) { break; }
	}
}
//用了设置哨兵的插入排序,需要注意的地方有j>=0的判定
void ShellSort::DisplayElements(int low, int high) const
{
	for (int i = low;i < high;i++)
	{
		cout << " " << data[i];
	}
	cout << endl;
}