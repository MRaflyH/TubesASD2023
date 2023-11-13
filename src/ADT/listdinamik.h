#ifndef LIST_DINAMIK_H
#define LIST_DINAMIK_H

#include "strukturberkait.h"
#include <stdlib.h>

#define InitialCapacity 16

typedef int IdxType;

typedef struct {
    StrukBerkait *Content;
    int Capacity;
    int Neff;
} ListDinamik;

ListDinamik CreateLD();
/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialCapacity
 */

void DeallocateLD(ListDinamik *l);
/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */

boolean IsEmptyLD(ListDinamik l);
/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */

boolean IsFullLD(ListDinamik l);
/**
 * Fungsi untuk mengetahui apakah suatu array penuh.
 * Prekondisi: array terdefinisi
 */

boolean IsIdxValidLD(ListDinamik l, IdxType i);
/**
 * Fungsi untuk mengetahui apakah suatu id valid dalam array.
 * Prekondisi: array terdefinisi dan i terdefinisi
 */

ElType GetLD(ListDinamik l, IdxType i);
/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */

void InsertLD(ListDinamik *l, ElType x, IdxType i);
/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */

void DeleteLD(ListDinamik *l, IdxType i);
/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */

void DisplayLD(ListDinamik l);
/**
 * print judul semua element dalam list dinamik
 * jika kosong print "Kosong"
 * 
 *     1. {Judul 1}
 *     2. {Judul 2}
 *     3. {Judul 3}
 *     4. {Judul 4}
 * 
 * berakhir akhir dengan '\n'
*/

void DisplayIsiLD(ListDinamik l, ElType x);
/**
 * print isi element suatu struktur berkait dengan judul x dalam list dinamik
 * jika kosong print "Kosong"
 * 
 *     1. {Element 1 Judul x}
 *     2. {Element 2 Judul x}
 *     3. {Element 3 Judul x}
 *     4. {Element 4 Judul x}
 * 
 * berakhir akhir dengan '\n'
 * Prekondisi: x adalah member dari l
*/

void DisplaySemuaLD(ListDinamik l);
/**
 * print dan judul playlist dan isinya dalam list dinamik
 * jika kosong print "Kosong"
 * 
 * Judul 1: {Judul A}
 *     1. {Element 1 Judul A}
 *     2. {Element 2 Judul A}
 *     3. {Element 3 Judul A}
 *     4. {Element 4 Judul A}
 * Judul 2: {Judul B}
 * Kosong
 * 
 * berakhir akhir dengan '\n'
*/

#endif