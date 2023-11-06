#include "listdinamik.h"

int main() {
    Word w;
    ListDinamik l;

    l = CreateLD();
    CreateWord(4, "bana", &w);

    for (int i = 0; i < 16; i++) {
        InsertLD(&l, w, i);
    }

    DisplayLD(l);
    printf("%d\n\n", l.Capacity);

    CreateWord(4, "sasa", &w);
    InsertLD(&l, w, 4);

    DisplayLD(l);
    printf("%d\n\n", l.Capacity);

    for (int i = 0; i < 8; i++) {
        DeleteLD(&l, 0);
    }

    DisplayLD(l);
    printf("%d\n\n", l.Capacity);

    return 0;
}