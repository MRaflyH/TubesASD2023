#ifndef MESIN_FILE_H
#define MESIN_FILE_H

#include "mesinkarakter.h"
#include "kata.h"

extern boolean EndWord;
extern Word CurrentWord;

boolean FileExists(char *fname);

void IgnoreBlanksF();

void StartFileF(char *FileName);

void AdvWordF();

void AdvLineF();

void AdvMarkF();

void CopyWordF();

void CopyLineF();

void CopyMarkF();
#endif