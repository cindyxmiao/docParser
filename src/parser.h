#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "element.h"

class Parser
{
private:
    std::vector<Element> m_document_elements;

    bool getFile(std::ifstream& infile, std::string& file_name);
    void readFile(std::ifstream& infile);
    void writeBulletList(std::ofstream& outfile, std::vector<Element>::iterator& it);
    void trim(std::string& s);
    void writeToFile(std::ofstream& outfile);

public:
    void convertFile();
};
