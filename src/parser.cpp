#include <algorithm> 
#include <cctype>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>

#include "parser.h"

using namespace std;

//TO-DI add integration tests and parsing unit tests
//TO-DO add logging
//TO-DO add clang somehow

void Parser::writeToFile(ofstream& outfile) {
	
	auto it = begin(m_document_elements);
	while (it != end(m_document_elements)) {
		if (it->getType() == HEADER) {
			outfile << "<h3>" << it->getText()<< "</h3>" << endl;
		}
		else if (it->getType() == PARAGRAPH) {
			outfile << "<p>" << it->getText() << "</p>" << endl;
		}
		else if(it->getType() == BULLET){
			writeBulletList(outfile, it);
			continue;
		}
		it++;
	}
}
void Parser::writeBulletList(ofstream& outfile, vector<Element>::iterator& it){
	outfile << "<ul>" << endl;
	do {
		outfile << "<li>" << it->getText() << "</li>" << endl;
		it++;
	}
	while (it != end(m_document_elements) && it->getType() == BULLET);
	outfile << "</ul>" << endl;
}

/*
 * Trims leading and trailing whitespace if present
 * from https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
 *
 */
void Parser::trim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));

	s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

/**
 * Checks if file exists, and is a text file
 * @param   file_name  the name of the file as specified by the user. Can be with or without file extension
 * @return			   true if the file exists and is a text file, and false otherwise
 */
bool Parser::getFile(ifstream& infile, string& file_name) {

	cout << "Enter the name of the text file to be converted (do not include .txt):";
	cin >> file_name;

	infile.open(file_name + ".txt");
	if (!infile.is_open()) {
		cout << "Error opening file...terminating..." << endl;
		return false;
	}
	cout << file_name + " is being parsed... " << endl;
	return true;
}

void Parser::readFile(ifstream& infile) {

	string line;
	while (infile.good())
	{
		getline(infile, line);
		trim(line);
		cout << "reading line: " + line << endl;
		if (line.empty()) {
			cout << "Empty line" << endl;
		}
		else if (line.at(0) == '-') {
			line.erase(line.begin());
			trim(line);
			m_document_elements.push_back(Element(BULLET, line));
		}
		else if (line.length() < 100 || !ispunct(line.at(line.length() - 1))) {
			m_document_elements.push_back(Element(HEADER, line));
		}
		else {
			m_document_elements.push_back(Element(PARAGRAPH, line));
		}
	}
}

void Parser::convertFile(){

	/*input file*/
	ifstream infile;
	string file_name;

	if (!getFile(infile, file_name)) {
		//return false?
	}

	readFile(infile);
	infile.close();

	/*output file*/
	ofstream outfile;
	outfile.open(file_name + ".html");
	
	writeToFile(outfile);
	outfile.close();
}
