#ifndef STRUKTUR_BERKAIT_H
#define STRUKTUR_BERKAIT_H

#include "kata.h"
#include "detaillagu.h"
#include <stdlib.h>

#define Nil NULL

typedef struct node* Address;

typedef struct node { 
    Detail Info;
    Address Next;
} Node;

typedef struct {
    Word Title;
    Address First;
} StrukBerkait;

#define Next(q) (q)->Next
#define Info(q) (q)->Info
#define First(sb) ((sb).First)
#define Title(sb) ((sb).Title)

Address NewNodeSB(Detail x);

boolean IsIdxValidSB(StrukBerkait *s, int i);

void CreateSB(StrukBerkait *s);
/* I.S. sembarang */
/* F.S. Sebuah sb kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah sb kosong */

/* ********** Pemeriksa Status StrukBerkait ********** */
boolean IsEmptySB(StrukBerkait s);
/* Mengirim true jika sb kosong: lihat definisi di atas */

int LengthSB(StrukBerkait s);
/* Mengirimkan banyaknya elemen StrukBerkait. Mengirimkan 0 jika sb kosong. */

void SetSB(StrukBerkait *s, ElType x, int i);

void InsertSB(StrukBerkait *s, Detail x, int i);

void DeleteSB(StrukBerkait *s, Detail *x, int i);

/* ********** Display StrukBerkait ********** */
void DisplaySB(StrukBerkait s);
/* Proses : Menuliskan isi StrukBerkait dengan traversal, StrukBerkait ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. sb boleh kosong */
/* F.S. Jika sb tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika StrukBerkait kosong : menulis [] */
#endif