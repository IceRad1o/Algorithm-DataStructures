#include<iostream>
#include"InsertSort.h"
using namespace std;
int main() {
	InsertSort test(10);

	test.insertsort();
	cout << "-----------------------------------------------" << endl;
	cout << "���Ƿָ���:�������������ڱ��Ĳ�������" << endl;
	test.insertsort2();

	system("pause");
}