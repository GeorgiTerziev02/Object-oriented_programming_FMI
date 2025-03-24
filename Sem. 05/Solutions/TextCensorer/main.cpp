#include "TextCensorer/TextCensorer.h"
#include "Text/Text.h"

int main() {
    TextCensorer c1;
    c1.addLetter('e');
    Text t1(c1, "hello");
    Text t2(c1, "eeeeee");

    t1.print();
    t2.print();

    // What happens if we make c1 dynamic, delete it here and then call t1.print()? 
}