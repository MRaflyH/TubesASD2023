#ifndef KATA_H
#define KATA_H

#include "../../src/boolean.h"
#include <stdio.h>

#define MaxChar 100
#define Blank ' '

typedef struct {
   char Content[MaxChar];
   int Length;
} Word;

extern boolean EndWord;
extern Word CurrentWord;

void CreateWord(int length, char * string, Word * w);

boolean IsWordSame(Word w, Word v);

void PasteWord(Word source, Word * dest);

void DisplayWord(Word w);

void DisplayWordSpace(Word w);

int WordToInt(Word w);

void IntToWord(int i, Word * w);

char *WordtoFileName(Word w);

#endif