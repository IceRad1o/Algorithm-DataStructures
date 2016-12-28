#pragma once
#ifndef INSERTSORT_H
#define INSERTSORT_H
/*
插入排序：将一个记录插入到已排序好的有序表中，从而得到一个新，记录数增1的有序表。
即：先将序列的第1个记录看成是一个有序的子序列，然后从第2个记录逐个进行插入，直至整个序列有序为止。
要点：设立哨兵，作为临时存储和判断数组边界之用。
是稳定的排序算法
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