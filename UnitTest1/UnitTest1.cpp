#include "pch.h"
#include "CppUnitTest.h"
#include "../4.2/4.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char fname[1] = { 't' };
			ofstream f(fname);
			string s = "I can ca  l cu      lat ion  !!!";
			while(f << s)
			Assert::IsTrue(Calculation(fname)== 6);
		}
	};
}
