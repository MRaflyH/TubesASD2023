#include "mesinfile.h"

boolean FileExists(char *fname) {
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return true;
    }
    return false;
}

void IgnoreBlanksF() {
   while (CurrentChar == Blank || CurrentChar == NewLine || CurrentChar == Mark) {
      Adv();
   }
}

void StartFileF(char *FileName) {
   StartF(FileName);
   IgnoreBlanksF();
   if (CurrentChar == NewLine) {
      EndWord = true;
   }
   else {
      EndWord = false;
      CopyLineF();
   }
   IgnoreBlanksF();
}

void AdvWordF() {
   IgnoreBlanksF();
   if (CurrentChar == Blank) {
      EndWord = true; 
   }
   else {
      CopyWordF();
   }
   IgnoreBlanksF();
}

void AdvLineF() {
   IgnoreBlanksF();
   if (CurrentChar == NewLine) {
      EndWord = true; 
   }
   else {
      CopyLineF();
   }
   IgnoreBlanksF();
}

void AdvMarkF() {
   IgnoreBlanksF();
   if (CurrentChar == Mark) {
      EndWord = true; 
   }
   else {
      CopyMarkF();
   }
   Adv();
   IgnoreBlanksF();
}

void CopyWordF() {
   int i = 0;
   while (CurrentChar != EOF && CurrentChar != Blank && !IsEOP()) {
      CurrentWord.Content[i] = CurrentChar;
      Adv();
      i += 1;
   }

   if (i < MaxChar) {
      CurrentWord.Length = i;
   }
   else {
      CurrentWord.Length = MaxChar;
   }
} 

void CopyLineF() {
   int i = 0;
   while (CurrentChar != EOF && CurrentChar != NewLine && !IsEOP()) {
      CurrentWord.Content[i] = CurrentChar;
      Adv();
      i += 1;
   }

   if (i < MaxChar) {
      CurrentWord.Length = i;
   }
   else {
      CurrentWord.Length = MaxChar;
   }
} 

void CopyMarkF() {
   int i = 0;
   while (CurrentChar != EOF && CurrentChar != Mark && !IsEOP()) {
      CurrentWord.Content[i] = CurrentChar;
      Adv();
      i += 1;
   }

   if (i < MaxChar) {
      CurrentWord.Length = i;
   }
   else {
      CurrentWord.Length = MaxChar;
   }
}

void AdvWriteWord(Word w) {
   for (int i = 0; i < w.Length; i++) {
      AdvWrite(w.Content[i]);
   }
}
