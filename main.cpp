#include <iostream>
#include <gmock/gmock.h>
#include <fstream>
using namespace testing;
using namespace std;

std::string helloWorld (){
	ofstream myfile;
	myfile.open("example.txt");
	string s = "Writing this to a file.";
	string t = "Hello there!";
	myfile << s << endl;
	myfile << t << endl;

	myfile.close();
	return s + t;
}
/*int main(int argc, const char * argv []){
	std::cout << helloWorld() <<std::endl;
	return 0;
}*/

TEST( BlobParserBasics, test1 )
{
	ifstream infile;
	infile.open("example.txt");
	string s = "";

	while (!infile.eof()) // To get you all the lines.
	{
		string curr;
		getline(infile, curr); // Saves the line in STRING.
		cout << "curr is " + curr << endl; // Prints our STRING.
		s += curr;
		cout << "s is" + s << endl;
	}
    EXPECT_THAT(helloWorld(), Eq(s));
}

TEST(BlobParserBasics, test2)
{
	EXPECT_THAT(1+1, 2);
}
