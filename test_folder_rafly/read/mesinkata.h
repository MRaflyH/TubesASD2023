#ifndef MESIN_KATA_H
#define MESIN_KATA_H

#include "mesinkarakter.h"

#define MaxChar 100
#define Blank ' '
#define NewLine '\n'

typedef struct {
   char Content[MaxChar];
   int Length;
} Word;

extern boolean EndWord;
extern Word CurrentWord;

void IgnoreBlanksI();

void IgnoreNewLines();

void StartWordI();

void StartLine();

void AdvWordI();

void AdvLine();

void CopyWordI();

void CopyLine();

void Display();

boolean IsWordSame(Word w, Word v);

#endif