#include "Text.h"
#include <cstring>

void Text::setBuffer(const char *val) {
    if (strlen(val) > TextConstants::BUFF_SIZE) {
        return;
    }
    strcpy(buff, val);
}

Text::Text(TextCensorer &textCensorer, const char *buff) 
    : censorer(textCensorer) 
{
    setBuffer(buff);
}

void Text::print() const {
    censorer.print(buff);
}