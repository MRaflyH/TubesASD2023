#ifndef MESIN_KATA_H
#define MESIN_KATA_H

#include "mesinkarakter.h"
#include "kata.h"

extern boolean EndWord;
extern Word CurrentWord;

void IgnoreBlanks();

void StartFile(char *FileName);

void StartWord(char *FileName);

void AdvWord();

void AdvLine();

void AdvMark();

void CopyWord();

void CopyLine();

void CopyMark();
#endif