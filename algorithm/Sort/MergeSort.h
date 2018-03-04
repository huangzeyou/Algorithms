#pragma once

#include <algorithm>
#include <vector>

namespace SortAlgorithm
{
	template <typename T>
	void _mergeArray(std::vector<T>& v, int first, int mid, int last, std::vector<T>& tmp)
	{
		int i = first, j = mid + 1;
		int m = mid, n = last;
		int k = 0;

		while (i <= m && j <= n)
			tmp[k++] = v[v[i] <= v[j] ? i++ : j++];

		while (i <= m)
			tmp[k++] = v[i++];

		while (j <= n)
			tmp[k++] = v[j++];

		for (i = 0; i < k; i++)
			v[first + i] = tmp[i];
	}

	template <typename T>
	void _mergeSort(std::vector<T>& v, int first, int last, std::vector<T>& tmp)
	{
		if (first < last)
		{
			int mid = (first + last) / 2;
			_mergeSort(v, first, mid, tmp);
			_mergeSort(v, mid + 1, last, tmp);
			_mergeArray(v, first, mid, last, tmp);
		}
	}


	template <typename T>
	void MergeSort( std::vector<T>& v)
	{
		if (v.size() <= 1)
			return;

		std::vector<T> tmp;
		tmp.resize(v.size());

		_mergeSort(v, 0, v.size() - 1, tmp);

		

	}
}