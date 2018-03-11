#pragma once


#include <vector>
#include <algorithm>

namespace SortAlgorithm
{
	template <typename T>
	size_t Partition(std::vector<T>& v, int low, int high)
	{
		T& mark = v[high];
		int i = low - 1;	// i is the last one smaller or equal mark
		for (int j = low; j < high; ++j)
		{
			if (v[j] <= mark)
			{
				++i;
				std::swap(v[i], v[j]);
			}
		}
		std::swap(v[i + 1], mark);
		return i + 1;
	}


	template <typename T>
	void _quickSort(std::vector<T>& v, int low, int high)
	{
		if (low < high)
		{
			int mid = Partition(v, low, high);
			_quickSort(v, low, mid - 1);
			_quickSort(v, mid + 1, high);
		}
	}

	template <typename T>
	void QuickSort(std::vector<T>& v)
	{
		_quickSort(v, 0, v.size() - 1);
	}
}