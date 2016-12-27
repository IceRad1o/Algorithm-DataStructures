#pragma once
#ifndef BUBBLESORT_H
#define BUBBLESORT_H
/* 数据结构 ---------- 数组
 最差时间复杂度 ---- O(n^2)
 最优时间复杂度 ---- 如果能在内部循环第一次运行时,使用一个旗标来表示有无需要交换的可能,可以把最优时间复杂度降低到O(n)
 平均时间复杂度 ---- O(n^2)
 所需辅助空间 ------ O(1)
 稳定性 ------------ 稳定
 */
#include<iostream>
#include<vector>
using namespace std;
class BubbleSort {
public:
	BubbleSort(int);
	void bubblesort();
	void DisplayElements(int, int) const;
private:
	int size;
	vector<int> data;
};
#endif
