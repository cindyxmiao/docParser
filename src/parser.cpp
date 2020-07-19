#include <algorithm> 
#include <cctype>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>

#include "parser.h"
using namespace std;

//TO-DO add logging
//TO-DO add clang somehow
//TO-DO put parser into a class

/**
 * Adds paragrah tags to a string and writes to output file
 */
void Parser::writeParagraph(ofstream& outfile, string paragraph) {
	cout << "This is a paragraph" << endl;
	outfile << "<p>" << paragraph << "</p>" << endl;
}

/**
 * Adds header tags to a string and writes to output file 
 */
void Parser::writeHeader(ofstream& outfile, string header) {
	cout << "This is a header" << endl;
	outfile << "<h3>" << header << "</h3>" << endl;
}

/**
 * Trims leading and trailing whitespace if present
 */
void Parser::trim(string& s) { // from https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
	s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
		return !std::isspace(ch);
	}).base(), s.end());
}

/**
 * Checks if file exists, and is a text file
 * @param   file_name  the name of the file as specified by the user. Can be with or without file extension
 * @return			   true if the file exists and is a text file, and false otherwise
 */
void Parser::isVailidFile(string file_name) {
	
}



string Parser::helloWorld (){

	/*input file*/
	ifstream infile;
	string file_name;
	string line;


	cout << "Enter the name of the text file to be converted (do not include .txt):";
	cin >> file_name;
	//TO-DO: can be entered with or without txt, throw exception if file is not of the correct type

	infile.open(file_name + ".txt");
	if (!infile.is_open()) {
		cout << "Error opening file...terminating..." << endl;
		//TO-DO: print error message if file name is invalid, or not in directory?
	}
	cout << file_name + " is being parsed... "<< endl;

	/*output file*/
	ofstream outfile;
	outfile.open(file_name + ".html");

	while (infile.good())
	{
		getline(infile, line);
		trim(line);
		cout << "reading line: " + line << endl;
		if (line.empty()) {
			cout << "Empty line" << endl;
			//don't do anything
		}
		else if (line.length() < 100 || !ispunct(line.at(line.length() - 1)) ) {
			writeHeader(outfile, line);
		}
		else{
			writeParagraph(outfile, line);
		}
	}
	
	string s = "Writing this to a file.";
	string t = "Hello there!";

	outfile.close();
	return s + t;
}
