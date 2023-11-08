#include "strukturberkait.h"

int main() {
    StrukBerkait s;
    Word w1, w2, w3;
    Detail w;
    CreateSB(&s);

    CreateWord(5, "rafly", &w1);
    CreateWord(5, "ylfar", &w2);
    CreateWord(5, "faryl", &w3);
    CreateD(&w, w1, w2, w3);
    InsertSB(&s, w, 0);
    CreateWord(5, "zahra", &w1);
    CreateWord(5, "arazh", &w2);
    CreateWord(5, "azhar", &w3);
    CreateD(&w, w1, w2, w3);
    InsertSB(&s, w, 0);
    CreateWord(6, "wildan", &w1);
    CreateWord(6, "danwil", &w2);
    CreateWord(6, "nalwid", &w3);
    CreateD(&w, w1, w2, w3);
    InsertSB(&s, w, 2);

    DisplaySB(s);

    return 0;
}