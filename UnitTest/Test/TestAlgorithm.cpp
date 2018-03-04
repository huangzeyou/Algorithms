#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "Sort/InsertSort.h"
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
			
			int i = _findFirstGreater(v, v.size() - 1, 4);
			Assert::AreEqual( i, 5);

			i = _findFirstGreater(v, v.size() - 1, 5);
			Assert::AreEqual(i, -1);

			i = _findFirstGreater(v, v.size() - 1, 3);
			Assert::AreEqual(i, 5);

			i = _findFirstGreater(v, v.size() - 1, 1);
			Assert::AreEqual(i, 1);

			i = _findFirstGreater(v, v.size() - 1, 0);
			Assert::AreEqual(i, 0);
		}


		TEST_METHOD(Test_InsertSort)
		{
			auto toSort = Util::CreateUnsortStrings();
			InsertSort(toSort);
			Assert::IsTrue(std::is_sorted(toSort.begin(), toSort.end()));
		}


	};
}