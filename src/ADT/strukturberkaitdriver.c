#include "strukturberkait.h"

int main() {
    StrukBerkait s;
    Word w;

    CreateSB(&s);

    CreateWord(5, "rafly", &w);
    InsertSB(&s, w, 0);
    CreateWord(5, "zahra", &w);
    InsertSB(&s, w, 0);
    CreateWord(6, "wildan", &w);
    InsertSB(&s, w, 2);

    DisplaySB(s);

    return 0;
}