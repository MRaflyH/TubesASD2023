#include <stdio.h>
#include "stdlib.h"
#include "yoga.h"

void QueueSong() {
    printf("Daftar Penyanyi :\n");
    DisplayLS(DaftarPenyanyi);

    printf("Masukkan Nama Penyanyi : ");
    StartWordI();
    Word penyanyi = CurrentWord;

    if (SearchLS(DaftarPenyanyi, penyanyi)) {
        printf("Daftar Album oleh ");
        DisplayWordSpace(penyanyi);
        printf(" :\n");
        DisplayValueM(AlbumPenyanyi, penyanyi);

        printf("Masukkan Judul Album yang dipilih : ");
        StartWordI();
        Word album = CurrentWord;
        
        if (IsMemberSet(ValueM(AlbumPenyanyi, penyanyi), album)) {
            printf("Daftar Lagu Album ");
            DisplayWordSpace(album);
            printf(" oleh ");
            DisplayWordSpace(penyanyi);
            printf(" :\n");

            DisplayValueM(LaguAlbum, album);

            printf("Masukkan ID Lagu yang dipilih : ");
            StartWordI();
            int id_lagu = WordToInt(CurrentWord) - 1;

            if (IsIdxValidSet(ValueM(LaguAlbum, album), id_lagu)){
                Queue QueueLagu;
                Detail temp;
                EnqueueQ(&QueueLagu, &temp);
                printf("Berhasil menambahkan lagu “");
                DisplayWordSpace(lagu);
                printf("” oleh “");
                DisplayWordSpace(penyanyi);
                printf("” ke queue.\n");
            } 
            
            else {
                printf("ID Lagu %d tidak ada dalam daftar. Silakan coba lagi.\n", id_lagu + 1);
            }
        } 
        
        else {
            printf("Album ");
            DisplayWordSpace(album);
            printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        } 
    } 
    
    else {
        printf("Penyanyi ");
        DisplayWordSpace(penyanyi);
        printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
    }
}

void QueuePlaylist() {
    printf("Masukkan ID Playlist : ");
    StartWordI();
    int id_playlist = WordToInt(CurrentWord) - 1;

    if (IsIdValidLD(DaftarPlaylist, id_playlist)) {
        Queue QueueLagu;
        Detail temp;
        EnqueueQ(&QueueLagu, &temp);
        printf("Berhasil menambahkan playlist “");
        DisplayWord(playlist);
        printf("” ke queue.\n");
    } 
    
    else {
        printf("ID Playlist %d tidak ada dalam daftar. Silakan coba lagi.\n", id_playlist + 1);
    }
}

void QueueSwap(int x, int y) {
    if (x < 0 || x >= l->Neff || y < 0 || y >= l->Neff) {
        printf("Lagu dengan urutan ke %d atau %d tidak terdapat dalam queue!\n", x, y);
        return;
    }

    Queue QueueLagu;
    SwapQ(QueueLagu, x, y);

    printf("Lagu “%s” berhasil ditukar dengan “%s”\n", x.judul, y.judul);
}

void QueueRemove(int id) {
    if (id < 0 || id >= l->Neff) {
        printf("Lagu dengan urutan ke %d tidak ada.\n", id);
        return;
    }

    Queue QueueLagu;
    DeleteQ(QueueLagu, id);

    printf("Lagu “%s” oleh “%s” telah dihapus dari queue!\n", id.judul, id.penyanyi);
}

void QueueClear() {
    Queue QueueLagu;
    Detail temp;
    while (!IsEmptyQ(QueueLagu)) {
        DequeueQ(&QueueLagu, &temp)
    }

    printf("Queue berhasil dikosongkan.\n")
}