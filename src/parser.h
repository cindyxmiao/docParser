#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "element.h"

class Parser
{
private:
    std::vector<Element> document_elements;

public:
    void writeParagraph(std::ofstream& outfile, std::string paragraph);
    void writeHeader(std::ofstream& outfile, std::string header);
    static void trim(std::string& s);
    std::string helloWorld(); 
    void isVailidFile(std::string file_name);
};