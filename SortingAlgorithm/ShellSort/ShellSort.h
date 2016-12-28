#pragma once
#ifndef SHELLSORT_H
#define SHELLSORT_H
/*
shell sort是插入排序的改进
又可以称为缩小增量排序
只要最后一次增量为1，增量大小的选择对shellsort的正确性没有印象
但是有的增量选择要比另一些更有效
一个比较好的选择是从incr=n/3+1开始按incr=incr/3+1减少增量
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

