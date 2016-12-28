#include<iostream>
#include"InsertSort.h"
using namespace std;
int main() {
	InsertSort test(10);

	test.insertsort();
	cout << "-----------------------------------------------" << endl;
	cout << "这是分割线:下面是设置了哨兵的插入排序" << endl;
	test.insertsort2();

	system("pause");
}