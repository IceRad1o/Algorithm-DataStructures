#pragma once
//µ›πÈ µœ÷
#include<vector>
using namespace std;
class MergeSort {
public:
	MergeSort(int);
	void mergesort();
	void DisplayElements()const;
private:
	void sortSubVectorNotrec(int, int);
	void sortSubVector(int, int);
	void merge(int,int,int,int);
	void displaySubVector(int, int) const;
	int size;
	vector<int> data;
};















