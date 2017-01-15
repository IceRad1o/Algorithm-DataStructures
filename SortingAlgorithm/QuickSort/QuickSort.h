#pragma once
#ifndef QUICKSORT_H
#define QUICKSORT_H
namespace wjlquicksort {
	template<class T>
	class QuickSort {
	public:
		void Quicksort(T *, const int, const int);
		void display(T *, const int n);
	private:
		void swap(T *, const int&, const int&);
	};

#endif // !QUICKSORT_H

	/*
	implements of methods
	left快排取(这里取最左端)为一个Pivot标准
	比pivot小的放在左侧而把比pivot大的放在右侧
	这里的等号要注意
	这段代码的快排需要改进,结构分明一点会更好
	*/
	template<class T>
	void QuickSort<T>::Quicksort(T *tree, const int left, const int right)
	{
		if (left < right)
		{
			T pivot = tree[left];
			int i = left + 1, j = right;
			while (i <= j)
			{
				while (pivot > tree[i]) i++;
				while (pivot < tree[j]) j--;
				if (i < j) swap(tree, i, j);
			}
			swap(tree, left, j);//把pivot换到中间
			//display(tree,right+1);
			Quicksort(tree, left, j - 1);
			Quicksort(tree, j + 1, right);
		}
	}

	template<class T>
	void QuickSort<T>::swap(T *tree, const int &left, const int &right)
	{
		T temp = tree[left];
		tree[left] = tree[right];
		tree[right] = temp;
	}

	template<class T>
	void QuickSort<T>::display(T *tree, const int n)
	{
		for (int i = 0;i < n;i++)
		{
			cout << tree[i] << "  ";
		}
		cout << endl;
	}
}