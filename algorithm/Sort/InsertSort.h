#pragma once

#include <algorithm>
#include <vector>

namespace SortAlgorithm
{
	template <typename T>
	static int _findFirstGreater(const std::vector<T>& v, int last, const T& key)
	{
		if (last >= (int)v.size())
			return -1;

		if (v[last] <= key)
			return -1;

		int left = 0;
		int right = last;

		while (left <= right) {
			int mid = (left + right) / 2;
			if (v[mid] > key) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
	}


	template <typename T>
	static void InsertSort(std::vector<T>& v)
	{
		if (v.size() <= 1)
			return;
		for (size_t i = 1; i < v.size(); ++i)
		{
			int j = i - 1;
			int firstGreater = _findFirstGreater(v, j, v[i]);
			if (firstGreater != -1)
			{
				T key = std::move(v[i]);
				while (firstGreater <= j)
				{
					v[j + 1] = v[j];
					--j;
				}
				v[firstGreater] = std::move(key);
			}

		}
	}





	
}

