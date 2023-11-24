#include "listdinamik.h"

int main() {
    Word w;
    ListDinamik l;
    Detail d;

    l = CreateLD();
    printf("IsEmptyLD : %d\n", IsEmptyLD(l));
    
    CreateWord(4, "bana", &w);

    for (int i = 0; i < 16; i++) {
        InsertLD(&l, w, i);
    }

    printf("IsIdxValidLD 13 : %d\n", IsIdxValidLD(l, 13));
    printf("GetLD 13 : ");    
    DisplayWordNewLine(GetLD(l, 13));
    printf("IsIdxValidLD 20 : %d\n", IsIdxValidLD(l, 20));

    DisplayLD(l);
    printf("%d\n\n", l.Capacity);

    CreateWord(4, "nana", &w);
    InsertLD(&l, w, 4);

    DisplayLD(l);
    printf("%d\n\n", l.Capacity);

    for (int i = 0; i < 8; i++) {
        DeleteLD(&l, 0);
    }

    DisplayLD(l);
    printf("%d\n\n", l.Capacity);

    CreateWord(4, "popo", &w);
    CreateD(&d, w, w, w);
    InsertSB(&l.Content[1], d, 0);
    InsertSB(&l.Content[1], d, 1);
    InsertSB(&l.Content[1], d, 2);

    DisplaySemuaLD(l);
    
    return 0;
}