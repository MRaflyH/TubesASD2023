#include "liststatik.h"

int main() {
    ListStatik ls;
    Word w;

    ls = CreateLS();
    printf("IsEmptyLS : %d\n", IsEmptyLS(ls));

    CreateWord(6, "pisang", &w);
    InsertLS(&ls, w);
    CreateWord(6, "banana", &w);
    InsertLS(&ls, w);
    CreateWord(4, "sapi", &w);
    InsertLS(&ls, w);
    CreateWord(4, "ayam", &w);
    InsertLS(&ls, w);

    printf("Search ayam : %d\n", SearchLS(ls, w));

    DisplayLS(ls);

    return 0;
}