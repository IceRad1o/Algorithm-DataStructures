#include<iostream>
#include"MergeSort.h"
using namespace std;
int main()
{
	MergeSort sortVector(10);
	cout << "unsorted vector:" << endl;
	sortVector.DisplayElements();
	cout << endl << endl;
	sortVector.mergesort();

	cout << "sorted vector:  " << endl;
	sortVector.DisplayElements();
	cout << endl;
	system("pause");
}