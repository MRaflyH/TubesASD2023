#include "set.h"

int main() {
    Set s;
    Word w;
    CreateSet(&s);

    CreateWord(4, "test", &w);
    AddSet(&s, w);
    AddSet(&s, w);
    CreateWord(6, "pisang", &w);
    AddSet(&s, w);

    DisplaySet(s);

    return 0;
}