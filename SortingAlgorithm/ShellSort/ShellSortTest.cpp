#include<iostream>
#include"ShellSort.h"
using namespace std;
int main()
{
	ShellSort shell(10);
	shell.shellsort();
	shell.DisplayElements(0, 10);
	system("pause");
}