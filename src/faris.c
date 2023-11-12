#include <stdio.h>
#include "faris.h"
#include "stdlib.h"

void playSong(){
    printf("Daftar Penyanyi :\n");
    DisplayLS(DaftarPenyanyi);

    printf("Masukkan Nama Penyanyi yang dipilih : ");
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
                Word lagu;
                PasteWord(ValueM(LaguAlbum, album).Content[id_lagu], &lagu);
                printf("Memutar lagu “");
                DisplayWordSpace(lagu);
                printf("” oleh “");
                DisplayWordSpace(penyanyi);
                printf("”.\n");
                
                Detail temp;
                while (!IsEmptyQ(QueueLagu)){
                    DequeueQ(&QueueLagu, &temp);
                }
                
                while (!IsEmptyS(RiwayatLagu)){
                    PopS(&RiwayatLagu, &temp);
                }

            }else{
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


void playPlaylist(){
    printf("Masukkan ID Playlist : ");
    StartWordI();
    int id_playlist = WordToInt(CurrentWord) - 1;

    if (IsIdValidLD(DaftarPlaylist, id_playlist)) {
        Word playlist;
        PasteWord(Title(DaftarPlaylist.Content[id_playlist]), &playlist);
        printf("Memutar playlist “");
        DisplayWordSpace(playlist);
        printf("”.\n");
                
        Detail temp;
        while (!IsEmptyQ(QueueLagu)){
            DequeueQ(&QueueLagu, &temp);
        }
                
        while (!IsEmptyS(RiwayatLagu)){
            PopS(&RiwayatLagu, &temp);
        }

        Address p = First(DaftarPlaylist.Content[id_playlist]);
        while (p != Nil){
            EnqueueQ(&QueueLagu, Info(p));
            PushS(&RiwayatLagu, Info(p));
            p = Next(p);
        }
    }
    else{
        printf("ID Playlist %d tidak ada dalam daftar. Silakan coba lagi.\n", id_playlist + 1);
    }
}


void songNext(){
    Detail temp;
    DequeueQ(&QueueLagu, &temp);
    PushS(&RiwayatLagu, temp);

    if (IsEmptyQ(QueueLagu)){
        printf("Queue kosong, memutar kembali lagu\n");
        DisplayWordSpace(temp.Lagu);
        printf("” oleh “");
        DisplayWordSpace(temp.Penyanyi);
        printf("”\n");
    }
    else{
        printf("Memutar lagu selanjutnya\n");
        DisplayWordSpace(HEAD(QueueLagu).Lagu);
        printf("” oleh “");
        DisplayWordSpace(HEAD(QueueLagu).Penyanyi);
        printf("”\n");
    }
}


void songPrevious(){
    if (IsEmptyS(RiwayatLagu)){
        printf("Riwayat lagu kosong, memutar kembali lagu\n");
    }
    else{
        EnqueueFirstQ(&QueueLagu, InfoTop(RiwayatLagu));
        printf("Memutar lagu sebelumnya\n");
    }
    
    DisplayWordSpace(HEAD(QueueLagu).Lagu);
    printf("” oleh “");
    DisplayWordSpace(HEAD(QueueLagu).Penyanyi);
    printf("”\n");
}

