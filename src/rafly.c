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

    char * file_name = "data.txt";
    StartFileF(file_name);
    int NPenyanyi = 0;
    for (int i = 0; i < CurrentWord.Length; i++) {
        NPenyanyi = NPenyanyi * 10 + (CurrentWord.Content[i] - '0');
    }

    for (int i = 0; i < NPenyanyi; i++) {
        // printf("Penyanyi %d : ", i+1);
        AdvWordF();
        int NAlbum = 0;
        for (int j = 0; j < CurrentWord.Length; j++) {
            NAlbum = NAlbum * 10 + (CurrentWord.Content[j] - '0');
        }
        AdvLineF();
        PasteWord(CurrentWord, &tempPenyanyi);
        InsertLS(&DaftarPenyanyi, tempPenyanyi);
        CreateSet(&tempSetAlbum);
        // DisplayWord(CurrentWord);

        for (int j = 0; j < NAlbum; j++) {
            // printf("  Album %d : ", j+1);
            AdvWordF();
            int NLagu = 0;
            for (int k = 0; k < CurrentWord.Length; k++) {
                NLagu = NLagu * 10 + (CurrentWord.Content[k] - '0');
            }
            AdvLineF();
            PasteWord(CurrentWord, &tempAlbum);
            AddSet(&tempSetAlbum, tempAlbum);
            CreateSet(&tempSetLagu);
            // DisplayWord(CurrentWord);

            for (int k = 0; k < NLagu; k++) {
                // printf("    Lagu %d : ", k+1);
                AdvLineF();
                // DisplayWord(CurrentWord);
                PasteWord(CurrentWord, &tempLagu);
                AddSet(&tempSetLagu, tempLagu);
            }

            InsertM(&LaguAlbum, tempAlbum, tempSetLagu);
        }

        InsertM(&AlbumPenyanyi, tempPenyanyi, tempSetAlbum);
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
