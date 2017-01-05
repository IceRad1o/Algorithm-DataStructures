#pragma once
#include<vector>
using namespace std;
class HeapSort {
public:
	HeapSort(int);
	void heapsort();
	void DisplayElements()const;
private:
	int size;
	vector<int> data;
};