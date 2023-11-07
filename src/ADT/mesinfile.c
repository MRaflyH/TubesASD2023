#include "mesinfile.h"

boolean EndWord;
Word CurrentWord;

void IgnoreBlanksF() {
   while (CurrentChar == Blank || CurrentChar == NewLine) {
      Adv();
   }
}

void StartFileF(char *FileName) {
   StartF(FileName);
   IgnoreBlanksF();
   if (CurrentChar == Mark) {
      EndWord = true;
   }
   else {
      EndWord = false;
      CopyWordF();
   }
   IgnoreBlanksF();
}

void AdvWordF() {
   IgnoreBlanksF();
   if (CurrentChar == Mark) {
      EndWord = true; 
   }
   else {
      CopyWordF();
   }
   IgnoreBlanksF();
}

void AdvLineF() {
   IgnoreBlanksF();
   if (CurrentChar == Mark) {
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
   IgnoreBlanksF();
}

void CopyWordF() {
   int i = 0;
   while (CurrentChar != EOF && CurrentChar != Blank) {
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
   while (CurrentChar != EOF && CurrentChar != NewLine) {
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
   while (CurrentChar != EOF && CurrentChar != Mark) {
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