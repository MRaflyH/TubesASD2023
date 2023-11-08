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
void EnqueueQ(Queue *q, Detail x)
{
    if (IsEmptyQ(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else {
        if (IDX_TAIL(*q) == MaxCapacity-1) {
            IDX_TAIL(*q) = 0;
        } else {
            IDX_TAIL(*q)++;
        }
    }
    PasteD(x, &TAIL(*q));
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void EnqueueFirstQ(Queue *q, Detail x)
{
    if (IsEmptyQ(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else if (IDX_HEAD(*q) == 0) {
        IDX_HEAD(*q) = MaxCapacity - 1;
    } else {
        IDX_HEAD(*q)--;
    }
    PasteD(x, &HEAD(*q));
}
/* Proses: Menambahkan val pada q dengan aturan LIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi HEAD yang baru, IDX_HEAD "naik" ke posisi pertama buffer
dan IDX_HEAD tidak berubah apabila buffer sudah penuh. */

void DequeueQ(Queue *q, Detail *x)
{
    PasteD(HEAD(*q), &(*x));
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
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

void SwapQ(Queue *q, IdxType i, IdxType j)
{
    Detail temp;
    PasteD((*q).Content[i], &temp);
    PasteD((*q).Content[j], &(*q).Content[i]);
    PasteD(temp, &(*q).Content[j]);
}
/* Proses: Melakukan swap antara element di index i dan element di index j */
/* I.S. q tidak mungkin kosong */
/* F.S. Element di index i berubah menjadi isinya sama dengan element di index j,
sedangkan element di index j berubah menjadi isinya sama dengan element di index i */

void DeleteQ(Queue *q, IdxType i)
{
    for(IdxType j =i; j!= IDX_TAIL(*q); j= (j+1)%MaxCapacity){
        PasteD((*q).Content[(j+1)%MaxCapacity], &(*q).Content[j]);
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
    if (IsEmptyQ(q)) {
        printf("Kosong\n");
    } else {
        int i = IDX_HEAD(q);
        while (i != IDX_TAIL(q)) {
            printf("%d. ", i+1);
            DisplayD(q.Content[i]);
            i++;
        }
        printf("%d. ", i+1);
        DisplayD(q.Content[i]);
    }
}
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */