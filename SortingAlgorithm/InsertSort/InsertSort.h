#pragma once
#ifndef INSERTSORT_H
#define INSERTSORT_H
/*
�������򣺽�һ����¼���뵽������õ�������У��Ӷ��õ�һ���£���¼����1�������
�����Ƚ����еĵ�1����¼������һ������������У�Ȼ��ӵ�2����¼������в��룬ֱ��������������Ϊֹ��
Ҫ�㣺�����ڱ�����Ϊ��ʱ�洢���ж�����߽�֮�á�
���ȶ��������㷨
*/
#include<iostream>
using namespace std;
class InsertSort {
public:
	InsertSort(int);
	~InsertSort();
	void insertsort();
	void insertsort2();
	void DisplayElements(int, int) const;
private:
	int size;
	int *arr;
};
#endif