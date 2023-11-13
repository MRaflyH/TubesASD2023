#ifndef QUEUE_H
#define QUEUE_H

#include "detaillagu.h"

#define MaxCapacity 100
#define IdxUndef -1

typedef struct {
    Detail Content[MaxCapacity];
    IdxType IdxHead;
    IdxType IdxTail;
} Queue;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).IdxHead
#define IDX_TAIL(q) (q).IdxTail
#define HEAD(q) (q).Content[(q).IdxHead]
#define TAIL(q) (q).Content[(q).IdxTail]

void CreateQ(Queue *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********** Pemeriksa Status Queue ********** */
boolean IsEmptyQ(Queue q);
/* Mengirim true jika q kosong */

boolean IsIdxValidQ(Queue *q, int i);
/* Mengirim true i adalah id valid dalam q */

int LengthQ(Queue q);
/* Mengirim panjang q */

/* ********** Primitif Add/Delete ********** */
void EnqueueQ(Queue *q, Detail x);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void EnqueueFirstQ(Queue *q, Detail x);

void DequeueQ(Queue *q, Detail *x);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

void SwapQ(Queue *q, IdxType i, IdxType j);

void DeleteQ(Queue *q, IdxType i);

/* ********** Display Queue ********** */
void DisplayQ(Queue q);
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: */
/*     1. {Top Element}
 *     2. {Element Selanjutnya}
 *     3. {Element Selanjutnya}
 *     4. {Element Selanjutnya} */ 
/* Jika Queue kosong : menulis "Kosong" */

#endif