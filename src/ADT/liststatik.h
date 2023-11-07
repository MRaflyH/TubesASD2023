#ifndef LIST_STATIK_H
#define LIST_STATIK_H

#include "kata.h"

#define MaxCapacity 100
#define IdxUndef -1

typedef int IdxType;
typedef Word ElType ;

typedef struct {
	ElType Content[MaxCapacity];
	int Neff;
} ListStatik;

ListStatik CreateLS();
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

boolean IsEmptyLS(ListStatik l);
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

boolean SearchLS(ListStatik l, ElType x);
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

void InsertLS(ListStatik *l, ElType x);
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

void DisplayLS(ListStatik l);
// Mungkin kosong = "Kosong\n"
// 1. New Jeans
// 2. BLACKPINK
// 3. Central Cee
// 4. Rich Brian
// 5. Denny Caknan
// 6. Via Vallen

#endif