#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_08.1rec.cpp"
#define _CRT_SECURE_NO_WARNINGS
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(RecursiveTests)
	{
	public:

		TEST_METHOD(TestCountStars_Recursive)
		{
			Assert::AreEqual(1, CountStarsRecursively("abc***def", 0));
			Assert::AreEqual(1, CountStarsRecursively("abc**def***gh", 0));
			Assert::AreEqual(2, CountStarsRecursively("***abc***", 0));
			Assert::AreEqual(0, CountStarsRecursively("abc", 0));
			Assert::AreEqual(3, CountStarsRecursively("***abc***def***", 0));
		}
	};
}
