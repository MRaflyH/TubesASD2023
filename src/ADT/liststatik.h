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
/**
 * print element isi list statik
 * jika kosong print "Kosong"
 * 
 *     1. {Element 1}
 *     2. {Element 2}
 *     3. {Element 3}
 *     4. {Element 4}
 * 
 * berakhir akhir dengan '\n'
*/

#endif