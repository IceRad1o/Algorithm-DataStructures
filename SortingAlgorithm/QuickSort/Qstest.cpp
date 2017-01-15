#include<iostream>
#include"QuickSort.h"
using namespace wjlquicksort;
using namespace std;
int main()
{

	  int a[10] = { 3,1,5,7,2,4,9,6,10,8 };
	  //int a[10] = { 26,5,77,1,61,11,59,15,48,19 };
	  //int a[3] = { 4,5};
      cout << "³õÊ¼Öµ£º";
	  QuickSort<int> qs;
	  qs.Quicksort(a, 0, 9);
	  qs.display(a,10);
	  system("pause");
	  return 0;
}