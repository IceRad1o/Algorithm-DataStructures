#pragma once
#ifndef SELECTION_H
#define SELECTION_H
#include<iostream>
#include<vector>
using namespace std;
class SelectionSort {
public:
	SelectionSort(int);
	void selectionsort();
	void DisplayElements(int, int) const;
private:
	int size;
	vector<int> data;
};
#endif