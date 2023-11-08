#ifndef DETAIL_LAGU_H
#define DETAIL_LAGU_H

#include "kata.h"

typedef Word ElType;
typedef int IdxType;

typedef struct {
    ElType Penyanyi;
    ElType Album;
    ElType Name;
} Detail;


void CreateD(Detail *d, Word penyanyi, Word album, Word lagu);

void PasteD(Detail source, Detail *dest);

void DisplayD(Detail d);

#endif