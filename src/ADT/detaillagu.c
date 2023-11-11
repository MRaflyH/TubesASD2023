#include "detaillagu.h"

void CreateD(Detail *d, Word penyanyi, Word album, Word lagu) {
    PasteWord(penyanyi, &(*d).Penyanyi);
    PasteWord(album, &(*d).Album);
    PasteWord(lagu, &(*d).Lagu);
}

void PasteD(Detail source, Detail *dest) {
    PasteWord(source.Penyanyi, &(*dest).Penyanyi);
    PasteWord(source.Album, &(*dest).Album);
    PasteWord(source.Lagu, &(*dest).Lagu);
}

void DisplayD(Detail d) {
    DisplayWordSpace(d.Penyanyi);
    printf(" - ");
    DisplayWordSpace(d.Album);
    printf(" - ");
    DisplayWordSpace(d.Lagu);
    printf("\n");
}
