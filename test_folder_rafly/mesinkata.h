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

void IgnoreBlanks();

void IgnoreNewLines();

void StartWord();

void StartLine();

void AdvWord();

void AdvLine();

void CopyWord();

void CopyLine();

void Display();

boolean IsWordSame(Word w, Word v);

#endif