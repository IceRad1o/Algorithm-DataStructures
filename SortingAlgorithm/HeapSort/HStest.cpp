#include<iostream>
#include<vector>
#include"HeapSort.h"
using namespace wjl;
using namespace std;
int main()
{
	int test[11] = { 0,26,5,77,1,61,11,59,15,48,19 };
	HeapSort<int> hp;
	hp.heapsort(test,10);
	system("pause");
}