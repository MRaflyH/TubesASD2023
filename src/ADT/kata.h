#ifndef KATA_H
#define KATA_H

#include "boolean.h"
#include <stdio.h>

#define MaxChar 100
#define Blank ' '

typedef struct {
   char Content[MaxChar];
   int Length;
} Word;

void CreateWord(int length, char * string, Word * w);

boolean IsWordSame(Word w, Word v);

void PasteWord(Word source, Word * dest);

void DisplayWord(Word w);

void DisplayWordSpace(Word w);

int WordToInt(Word w);

#endif