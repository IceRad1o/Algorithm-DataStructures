#pragma once
#ifndef HEAPSORT_H
#define HEAPSORT_H
namespace wjl {
	template<class T>
	class HeapSort
	{
	public:
		void heapsort(T *list, const int n);
		void buildheap(T *list, const int n);
		void heapadjust(T *tree, const int root, const int n);
		/*

		*/
	};
#endif // !HEAPSORT_H


	/*
	implement of methods;
	*/
	template<class T>
	void HeapSort<T>::heapadjust(T *tree, const int root, const int n)//堆调整：转化为最大堆
	{
		T e = tree[root];
		int j = 0;
		for (j = 2 * root;j <= n;j *= 2)
		{
			if (j < n)
			{
				if (tree[j] < tree[j + 1]) j++;
			}
			if (e >= tree[j]) break;
			tree[j / 2] = tree[j];//节点上移
		}
		tree[j / 2] = e;
	}
	template<class T>
	void HeapSort<T>::buildheap(T *list, const int n)
	{
		for (size_t i = n / 2;i >= 1;i--)
		{
			heapadjust(list, i, n);
		}//build the maxheap
	}

	template<class T>
	void HeapSort<T>::heapsort(T *list, const int n)
	{
		buildheap(list, n);
		for (int i = 1;i <= n;i++)
		{
			cout << list[i] << "  ";
		}
		cout << endl;
		for (int i = n - 1;i >= 1;i--)
		{
			T t = list[i + 1];
			list[i + 1] = list[1];
			list[1] = t;
			heapadjust(list, 1, i);

			for (int i = 1;i <= n;i++)//打印每一步的调整结果
			{
				cout << list[i] << "  ";
			}
			cout << endl;
		}
		
	}


}

