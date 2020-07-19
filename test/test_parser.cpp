// Test framework
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "parser.cpp"


using namespace testing;

TEST(BlobParserBasics, test1)
{
	//ifstream infile;
	//infile.open("example.txt");
	string s = "";

	//while (!infile.eof()) // To get you all the lines.
	//{
	//	string curr;
	//	getline(infile, curr); // Saves the line in STRING.
	//	cout << "curr is " + curr << endl; // Prints our STRING.
	//	s += curr;
	//	cout << "s is" + s << endl;
	//}
	EXPECT_THAT(helloWorld(), Eq(s));
}

TEST(BlobParserBasics, test2)
{
	EXPECT_THAT(1 + 1, 2);
}