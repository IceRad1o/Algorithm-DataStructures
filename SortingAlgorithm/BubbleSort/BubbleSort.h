#pragma once
#ifndef BUBBLESORT_H
#define BUBBLESORT_H
/* ���ݽṹ ---------- ����
 ���ʱ�临�Ӷ� ---- O(n^2)
 ����ʱ�临�Ӷ� ---- ��������ڲ�ѭ����һ������ʱ,ʹ��һ���������ʾ������Ҫ�����Ŀ���,���԰�����ʱ�临�ӶȽ��͵�O(n)
 ƽ��ʱ�临�Ӷ� ---- O(n^2)
 ���踨���ռ� ------ O(1)
 �ȶ��� ------------ �ȶ�
 */
#include<iostream>
#include<vector>
using namespace std;
class BubbleSort {
public:
	BubbleSort(int);
	void bubblesort();
	void DisplayElements(int, int) const;
private:
	int size;
	vector<int> data;
};
#endif
