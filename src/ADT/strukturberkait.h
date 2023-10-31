// AKU UDAH BIKIN TAPI TERNYATA GA KEPAKE

#ifndef STRUKTUR_BERKAIT_H
#define STRUKTUR_BERKAIT_H

#include "boolean.h"
#include <stdlib.h>

#define Nil NULL

typedef int ElType;
typedef struct node* Address;

typedef struct node { 
  ElType Info;
  Address Next;
} Node;

typedef struct {
  Address AddrHead;
  Address AddrTail;
} Queue;

#define Next(q) (q)->Next
#define Info(q) (q)->Info

#define AddrHead(q) (q).AddrHead
#define AddrTail(q) (q).AddrTail
#define Head(q) (q).AddrHead->Info

Address NewNode(ElType x);

boolean IsIdxValidQueue(Queue *q, int i);

boolean IsIdxValidQueue(Queue *q, int i);

void CreateQueue(Queue *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********** Pemeriksa Status Queue ********** */
boolean IsEmpty(Queue q);
/* Mengirim true jika q kosong: lihat definisi di atas */

int Length(Queue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* ********** Primitif Add/Delete ********** */
void Enqueue(Queue *q, ElType x);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void Dequeue(Queue *q, ElType *x);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* ********** Display Queue ********** */
void DisplayQueue(Queue q);
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
#endif