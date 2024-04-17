#include "MyString.h"
#include <utility>

void swap(MyString& l, MyString& r) {
    MyString temp = std::move(l);
    l = std::move(r);
    r = std::move(l);
}