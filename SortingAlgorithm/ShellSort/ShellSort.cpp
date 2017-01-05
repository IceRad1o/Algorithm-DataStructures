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
	cout << "��ʼ��������:  " ;
	DisplayElements(0, size);
	int incr = size / 3 + 1;//��ʼ������
	while (incr>=1)
	{
		int temp = 0;
		if (incr == 1) { temp++; }
	
		for (int i = incr;i < size;i++)//��ÿ������ĵڶ���Ԫ�ؿ�ʼ�������
		{
			
			if (data[i] < data[i - incr])
			{
				int index = data[i];//���ú��ڱ�
			    int j = i - incr;//����������һ���� ����
				while ((j>=0)&&(index < data[j]))//���С�ھͱȽ���ȥ
				{
					data[j + incr] = data[j];
					j -= incr;
				}
				data[j + incr] = index;
			}
			//��Ԫ�ز�������
		}
		DisplayElements(0, size);
		incr = incr / 3 + 1;//�����𽥼���
		
		if (temp == 1) { break; }
	}
}
//���������ڱ��Ĳ�������,��Ҫע��ĵط���j>=0���ж�
void ShellSort::DisplayElements(int low, int high) const
{
	for (int i = low;i < high;i++)
	{
		cout << " " << data[i];
	}
	cout << endl;
}