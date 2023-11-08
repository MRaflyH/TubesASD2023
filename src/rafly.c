#include "rafly.h"

int LOAD() {
    Word tempPenyanyi, tempAlbum, tempLagu;
    Set tempSetAlbum, tempSetLagu;

    DaftarPenyanyi = CreateLS();
    DaftarPlaylist = CreateLD();
    CreateQ(&QueueLagu);
    CreateS(&RiwayatLagu);
    CreateM(&AlbumPenyanyi);
    CreateM(&LaguAlbum);
    CreateSB(&Playlist);

    int NPenyanyi, NAlbum, NLagu, NQueue, NRiwayat, NPlaylist;
    Detail DLagu;

    char * file_name = "data.txt";
    StartFileF(file_name);

    NPenyanyi = 0;
    for (int i = 0; i < CurrentWord.Length; i++) {
        NPenyanyi = NPenyanyi * 10 + (CurrentWord.Content[i] - '0');
    }

    for (int i = 0; i < NPenyanyi; i++) {
        AdvWordF();
        NAlbum = 0;
        for (int j = 0; j < CurrentWord.Length; j++) {
            NAlbum = NAlbum * 10 + (CurrentWord.Content[j] - '0');
        }
        AdvLineF();
        PasteWord(CurrentWord, &tempPenyanyi);
        InsertLS(&DaftarPenyanyi, tempPenyanyi);
        CreateSet(&tempSetAlbum);

        for (int j = 0; j < NAlbum; j++) {
            AdvWordF();
            NLagu = 0;
            for (int k = 0; k < CurrentWord.Length; k++) {
                NLagu = NLagu * 10 + (CurrentWord.Content[k] - '0');
            }
            AdvLineF();
            PasteWord(CurrentWord, &tempAlbum);
            AddSet(&tempSetAlbum, tempAlbum);
            CreateSet(&tempSetLagu);

            for (int k = 0; k < NLagu; k++) {
                AdvLineF();
                PasteWord(CurrentWord, &tempLagu);
                AddSet(&tempSetLagu, tempLagu);
            }

            InsertM(&LaguAlbum, tempAlbum, tempSetLagu);
        }

        InsertM(&AlbumPenyanyi, tempPenyanyi, tempSetAlbum);
    }

    AdvLineF();

    NQueue = 0;
    for (int i = 0; i < CurrentWord.Length; i++) {
        NQueue = NQueue * 10 + (CurrentWord.Content[i] - '0');
    }

    for (int i = 0; i < NQueue; i++) {
        AdvMarkF();
        PasteWord(CurrentWord, &tempPenyanyi);
        AdvMarkF();
        PasteWord(CurrentWord, &tempAlbum);
        AdvLineF();
        PasteWord(CurrentWord, &tempLagu);
        CreateD(&DLagu, tempPenyanyi, tempAlbum, tempLagu);
        EnqueueQ(&QueueLagu, DLagu);
    }
    
    AdvLineF();

    NRiwayat = 0;
    for (int i = 0; i < CurrentWord.Length; i++) {
        NRiwayat = NRiwayat * 10 + (CurrentWord.Content[i] - '0');
    }

    for (int i = 0; i < NRiwayat; i++) {
        AdvMarkF();
        PasteWord(CurrentWord, &tempPenyanyi);
        AdvMarkF();
        PasteWord(CurrentWord, &tempAlbum);
        AdvLineF();
        PasteWord(CurrentWord, &tempLagu);
        CreateD(&DLagu, tempPenyanyi, tempAlbum, tempLagu);
        PushS(&RiwayatLagu, DLagu);
    }

    printf("\nINI DAFTAR PENYANYI\n");
    DisplayLS(DaftarPenyanyi);
    printf("\nINI DAFTAR PLAYLIST\n");
    DisplayLD(DaftarPlaylist);
    printf("\nINI QUEUE LAGU\n");
    DisplayQ(QueueLagu);
    printf("\nINI RIWAYAT LAGU\n");
    DisplayS(RiwayatLagu);
    printf("\nINI MAP ALBUM : PENYANYI\n");
    DisplayM(AlbumPenyanyi);
    printf("\nINI MAP LAGU : ALBUM\n");
    DisplayM(LaguAlbum);
    printf("\nINI CURRENT LAGU\n");
    DisplayWord(CurrentLagu);
    printf("\nINI ISI PLAYLIST\n");
    DisplaySB(Playlist);
    printf("\n");

    printf("KELAR\n");
     
    return 0;
}
