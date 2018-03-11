#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "Sort/InsertSort.h"
#include "Sort/QuickSort.h"
#include "Util/ContentCreator.h"

using namespace SortAlgorithm;

namespace GTest
{		
	TEST_CLASS(TestInsertSort)
	{
	public:
		
		TEST_METHOD(Test_findFirstGreater)
		{
			vector<int> v = { 1, 2, 2, 3, 3, 5, 5 };
			//                0  1  2  3  4  5  6
			
			int last = int(v.size() - 1);
			int i = _findFirstGreater(v, last, 4);
			Assert::AreEqual( i, 5);

			i = _findFirstGreater(v, last, 5);
			Assert::AreEqual(i, -1);

			i = _findFirstGreater(v, last, 3);
			Assert::AreEqual(i, 5);

			i = _findFirstGreater(v, last, 1);
			Assert::AreEqual(i, 1);

			i = _findFirstGreater(v, last, 2);
			Assert::AreEqual(i, 3);

			i = _findFirstGreater(v, last, 0);
			Assert::AreEqual(i, 0);
		}


		TEST_METHOD(Test_InsertSort)
		{
			auto toSort = Util::CreateUnsortStrings();
			InsertSort(toSort);
			Assert::IsTrue(std::is_sorted(toSort.begin(), toSort.end()));
		}


	};

	TEST_CLASS(TestQuickSort)
	{
	public:

		TEST_METHOD(Test_QuickSort)
		{
			auto toSort = Util::CreateUnsortStrings();
			QuickSort(toSort);
			Assert::IsTrue(std::is_sorted(toSort.begin(), toSort.end()));
		}


	};
}