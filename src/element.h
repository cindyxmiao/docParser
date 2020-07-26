#include <string>

enum eTYPE
{
    PARAGRAPH,
    HEADER,
    BULLET
};

class Element
{
private:
    eTYPE m_type;
    std::string m_text;
public:

    eTYPE getType();
    std::string getText();

    Element(eTYPE type, std::string text);
};
