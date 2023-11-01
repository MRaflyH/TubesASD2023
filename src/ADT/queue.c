#include <stdio.h>
#include "queue.h"

void CreateQ(Queue *q)
{
    IDX_HEAD (*q) = IdxUndef;
    IDX_TAIL (*q) = IdxUndef;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********** Pemeriksa Status Queue ********** */
boolean IsEmptyQ(Queue q)
{
    return (IDX_HEAD(q) == IdxUndef) && (IDX_TAIL(q) == IdxUndef);
}
/* Mengirim true jika q kosong: lihat definisi di atas */

boolean IsIdxValidQ(Queue *q, int i)
{
    return (i >= 0 && i < MaxCapacity);
}
/* Mengirim true jika index i adalah valid */

/* ********** Primitif Add/Delete ********** */
void EnqueueQ(Queue *q, ElType x)
{
    if (IsEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else {
        if (IDX_TAIL(*q) == MaxCapacity-1) {
            IDX_TAIL(*q) = 0;
        } else {
            IDX_TAIL(*q)++;
        }
    }
    TAIL(*q) = x;
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void EnqueueFirstQ(Queue *q, ElType x)
{
    if (IsEmptyQ(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else if (IDX_HEAD(*q) == 0) {
        IDX_HEAD(*q) = MaxCapacity - 1;
    } else {
        IDX_HEAD(*q)--;
    }
    HEAD(*q) = x;
}
/* Proses: Menambahkan val pada q dengan aturan LIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi HEAD yang baru, IDX_HEAD "naik" ke posisi pertama buffer
dan IDX_HEAD tidak berubah apabila buffer sudah penuh. */

void DequeueQ(Queue *q, ElType *x)
{
     ElType x = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
        IDX_HEAD(*q) = IdxUndef;
        IDX_TAIL(*q) = IdxUndef;
    } else {
        if (IDX_HEAD(*q) == MaxCapacity-1) {
            IDX_HEAD(*q) = 0;
        } else {
            IDX_HEAD(*q)++;
        }
    }
    return x;
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

void SwapQ(Queue *q, IdxType i, IdxType j)
{
    ElType temp = (*q).Content[i];
    (*q).Content[i] = (*q).Content[j];
    (*q).Content[j] = temp;
}
/* Proses: Melakukan swap antara element di index i dan element di index j */
/* I.S. q tidak mungkin kosong */
/* F.S. Element di index i berubah menjadi isinya sama dengan element di index j,
sedangkan element di index j berubah menjadi isinya sama dengan element di index i */

void DeleteQ(Queue *q, IdxType i)
{
    for(IdxType j =i; j!= IDX_TAIL(*q); j= (j+1)%MaxCapacity){
        (*q).Content[j] = (*q).Content[(j+1)%MaxCapacity];
    }
    if (IDX_HEAD(*q) == IDX_TAIL(*q)){
        IDX_HEAD(*q) = IdxUndef;
        IDX_TAIL(*q) = IdxUndef;
    }else if (IDX_TAIL(*q) == 0) {
        IDX_TAIL(*q) = MaxCapacity-1;
    }else{
        IDX_TAIL(*q)--;
    }
}
/* Proses: Menghapus element pada indeks i dari queue */
/* I.S. q tidak mungkin kosong */
/* F.S. Elemen yg ada di indeks i tersebut telah dihapus,
dan semua indeks selain i masih tetap */

/* ********** Display Queue ********** */
void DisplayQ(Queue q)
{
    if (IsEmpty(q)) {
        printf("[]\n");
    } else {
        int i = IDX_HEAD(q);
        printf("[");
        while (i != IDX_TAIL(q)) {
            printf("%d,", q.Content[i]);
            if (i == MaxCapacity-1) {
                i = 0;
            } else {
                i++;
            }
        }
        printf("%d]\n", q.Content[i]);
    }
}
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */