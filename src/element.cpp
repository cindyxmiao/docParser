#include "element.h"
#include <string>

using namespace std;

Element::Element(eTYPE type, string text) {
	this->m_type = type;
	this->m_text = text;
}

eTYPE Element::getType() {
    return m_type;
}

string Element::getText() {
    return m_text;
}