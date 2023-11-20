#include <stdio.h>
#include "help.h"

void helpbefore()
{
    printf("==============[ Menu Help WayangWave ]==============\n\n");
    printf("1. START    : Untuk masuk sesi baru.\n");
    printf("2. LOAD     : Untuk memulai sesi berdasarkan file konfigurasi.\n");
}
/* I.S sembarang*/
/* F.S untuk mengembalikan output command yang dapat dimasukkan*/

void helpafter()
{
    printf("==============[ Menu Help WayangWave ]==============\n\n");
    printf("1. LIST     : Untuk menampilkan playlist, daftar penyanyi, daftar album dan daftar lagu yang ada di almbum.\n");
    printf("2. PLAY     : Untuk memutar lagu atau playlist yang dipilih.\n");
    printf("3. QUEUE    : Untuk memanipulasi lagu dengan menambahkan, menukar, menghapus atau mengosongkan lagu.\n");
    printf("4. SONG     : Untuk navigasi lagu.\n");
    printf("5. PLAYLIST : Basic command untuk playlist yaitu CREATE, ADD, SWAP, REMOVE dan DELETE.\n");
    printf("6. STATUS   : Untuk menampilkan lagu yang sedang dimainkan .\n");
    printf("7. SAVE     : Untuk menyimpan state aplikasi terbaru ke dalam suatu file.\n");
    printf("8. QUIT     : Untuk keluar dari aplikasi WayangWave.\n");
   
}
/* I.S sembarang*/
/* F.S untuk mengembalikan output command yang dapat dimasukkan*/
