#include "detaillagu.h"

void CreateD(Detail *d, Word penyanyi, Word album, Word lagu) {
    PasteWord(penyanyi, &(*d).Penyanyi);
    PasteWord(album, &(*d).Album);
    PasteWord(lagu, &(*d).Lagu);
}

boolean IsEmptyD(Detail d) {
    return d.Penyanyi.Length == 0 && d.Album.Length == 0 && d.Lagu.Length == 0;
}

void PasteD(Detail source, Detail *dest) {
    PasteWord(source.Penyanyi, &(*dest).Penyanyi);
    PasteWord(source.Album, &(*dest).Album);
    PasteWord(source.Lagu, &(*dest).Lagu);
}

void DisplayD(Detail d) {
    if (IsEmptyD(d)) {
        printf("Kosong\n");
    }
    else {
        DisplayWord(d.Penyanyi);
        printf(" - ");
        DisplayWord(d.Album);
        printf(" - ");
        DisplayWord(d.Lagu);
        printf("\n");
    }
}

boolean IsDSame(Detail d1, Detail d2) {
    return (IsWordSame(d1.Penyanyi, d2.Penyanyi) && IsWordSame(d1.Album, d2.Album) && IsWordSame(d1.Lagu, d2.Lagu));
}
