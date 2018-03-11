#pragma once

#include <algorithm>
#include <vector>

using namespace std;

namespace SortAlgorithm
{
	const int npos = -1;

	template <typename T>
	int _findFirstGreater(const vector<T>& v, int last, const T& key)
	{
		if (last >= (int)v.size())
			return npos;

		if (v[last] <= key)
			return npos;

		int left = 0, right = last;

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
	void InsertSort(std::vector<T>& v)
	{
		if (v.size() <= 1)
			return;
		for (int i = 1; i < (int)v.size(); ++i)
		{
			int j = i - 1;
			int firstGreater = _findFirstGreater(v, j, v[i]);
			if (firstGreater != npos)
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

