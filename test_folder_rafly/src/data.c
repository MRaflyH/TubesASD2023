#include "data.h"

ListStatik DaftarPenyanyi;

void load() {
    Word temp;
    DaftarPenyanyi = CreateLS();

    CreateWord(9, "BLACKPINK", &temp);
    InsertLastLS(&DaftarPenyanyi, temp);
    CreateWord(14, "Arctic Monkeys", &temp);
    InsertLastLS(&DaftarPenyanyi, temp);
}
