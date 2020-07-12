#include <iostream>
#include <gmock/gmock.h>
#include <fstream>
using namespace testing;
using namespace std;


//void writeParagraph(ofstream outfile, string paragraph) {
//	outfile << "<p>";
//	outfile << paragraph << endl;
//	outfile << "</p>";
//}
//
//void writeHeader(ofstream outfile, string header) {
//	outfile << "<h3>";
//	outfile << header << endl;
//	outfile << "</h3>";
//}


std::string helloWorld (){

	/*input file*/
	ifstream infile;
	string fileName;
	string line;

	/*output file*/
	ofstream outfile;
	outfile.open(fileName + ".html");


	cout << "Enter the name of the text file to be converted (do not include .txt):";
	//TO-DO: can be entered with or without txt, throw exception if file is not of the correct type
	cin >> fileName;

	infile.open(fileName + ".txt");
	if (!infile.is_open()) {
		cout << "Error opening file...terminating..." << endl;
		//TO-DO: print error message if file name is invalid, or not in directory?
	}
	cout << fileName + " is being parsed.... "<< endl;

	while (infile.good())
	{
		getline(infile, line);
		cout << "reading line: " + line << endl;
		if (line.empty()) {
			cout << "Empty line" << endl;
			//don't do anything
		}
		else if (line.at(line.length()- 1) == '.'){
			cout << "This is a paragraph" << endl;
			/*writeParagraph(outfile, line);*/
		}
		else {
			cout << "This is a header" << endl;
			/*writeHeader(outfile, line);*/
		}
	}

	//if 4 spaces, header
	//else paragraph element, get the entire paragraph
	
	string s = "Writing this to a file.";
	string t = "Hello there!";

	outfile.close();
	return s + t;
}
/*int main(int argc, const char * argv []){
	std::cout << helloWorld() <<std::endl;
	return 0;
}*/

TEST( BlobParserBasics, test1 )
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
	EXPECT_THAT(1+1, 2);
}
