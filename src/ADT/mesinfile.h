#ifndef MESIN_FILE_H
#define MESIN_FILE_H

#include "mesinkarakter.h"
#include "kata.h"

boolean FileExists(char *fname);

void IgnoreBlanksF();
/* Mengabaikan satu atau beberapa Blank dan Mark
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ Blank atau currentChar = Mark */

void StartFileF(char *FileName);
/* I.S. : FileName adalah string terdefinisi
   F.S. : File FileName dibuka
          EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata sampai Blank atau NewLine yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void AdvWordF();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin NewLine
          Jika currentChar = EOF, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyWordI */

void AdvLineF();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, pasti NewLine
          Jika currentChar = EOF, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyLineI */

void AdvMarkF();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, pasti MARK
          Jika currentChar = EOF, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyLineI */

void CopyWordF();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = Newline atau currentChar = EOF;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopyLineF();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = NewLine atau EOF;
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopyMarkF();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = MARK;
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void AdvWriteWord(Word w);
/* Menulis isi w ke dalam file
   I.S. : w terdefinisi dan file terbuka
   F.S. : ditulis isi w dalam file; */

#endif