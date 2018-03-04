#pragma once

#include <vector>
#include <stdafx.h>

namespace Util
{
	std::vector<string> CreateUnsortStrings()
	{
		vector<string> v = { "zip", "yes" , "xiexie", "vitim", "unused", "time", "sell", "roll" };
		return std::move(v);
	}

	template< typename T>
	void MyPrint(const vector<T>& c)
	{
		std::for_each(c.begin(), c.end(), [](const T& n) { cout << n << " "; });
		cout << endl;
	}

}