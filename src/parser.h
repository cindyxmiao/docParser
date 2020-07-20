#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "element.h"

class Parser
{
private:
    std::vector<Element> m_document_elements;

public:
    void writeToFile(std::ofstream& outfile);
    static void trim(std::string& s);
    void convertFile();
    bool getFile(std::ifstream& infile, std::string& file_name);
    void readFile(std::ifstream& infile);
};