#include "liststatik.h"

int main() {
    ListStatik ls;
    Word w;

    ls = CreateLS();

    CreateWord(6, "pisang", &w);
    InsertLastLS(&ls, w);
    CreateWord(6, "banana", &w);
    InsertLastLS(&ls, w);
    CreateWord(4, "sapi", &w);
    InsertLastLS(&ls, w);
    CreateWord(4, "ayam", &w);
    InsertLastLS(&ls, w);

    DisplayLS(ls);

    return 0;
}