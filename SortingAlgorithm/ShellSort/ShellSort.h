#pragma once
#ifndef SHELLSORT_H
#define SHELLSORT_H
/*
shell sort�ǲ�������ĸĽ�
�ֿ��Գ�Ϊ��С��������
ֻҪ���һ������Ϊ1��������С��ѡ���shellsort����ȷ��û��ӡ��
�����е�����ѡ��Ҫ����һЩ����Ч
һ���ȽϺõ�ѡ���Ǵ�incr=n/3+1��ʼ��incr=incr/3+1��������
*/
#include<iostream>
#include<vector>
using namespace std;
class ShellSort {
public:
	ShellSort(int);
	//void insertsort(int*);
	void shellsort();
	void DisplayElements(int,int) const;
private:
	int size;
	vector<int> data;
};
#endif // !SHELLSORT_H

