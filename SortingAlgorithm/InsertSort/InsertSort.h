#pragma once
#ifndef INSERTSORT_H
#define INSERTSORT_H
#include<iostream>
using namespace std;
class InsertSort {
public:
	InsertSort(int);
	~InsertSort();
	void insertsort();
	void DisplayElements(int, int) const;
private:
	int size;
	int *arr;
};
#endif