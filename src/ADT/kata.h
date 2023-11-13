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
/* I.S. w sembarang. length adalah panjang string dan string terdefinisi. */
/* F.S. w diisi dengan string dan length w menjadi length. */

boolean IsWordSame(Word w, Word v);
/* Fungsi untuk mengecek jika isi w dan v sama */
/* Prekondisi w dan v terdefinisi. */

void PasteWord(Word source, Word * dest);
/* I.S. source terdefinisi, dest sembarang. */
/* F.S. mengisi dest dengan isi source. */

void DisplayWordNewLine(Word w);
/* I.S. w terdefinisi. */
/* F.S. menampilkan isi w yang berakhir dengan '\n'. */

void DisplayWord(Word w);
/* I.S. w terdefinisi. */
/* F.S. menampilkan isi w. */

int WordToInt(Word w);
/* Fungsi untuk mengubah w menjadi integer */
/* Prekondisi w berisi 1 kata dan isinya hanya character angka. */

void IntToWord(int i, Word * w);
/* Fungsi untuk mengubah i menjadi integer */
/* Prekondisi i adalah integer positif. */

char *WordtoFileName(Word w);
/* Fungsi untuk mengubah suatu word dengan isi filename.txt menjadi string "../save/filename.txt"  */
/* Prekondisi w terdefinisi dan ada isinya. */

#endif