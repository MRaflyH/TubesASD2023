// INCLUDE H FILE
#include "display.h"

// BOLEH PAKE PARAMETER TAPI MASIH VOID YAA. OUTPUT GAUSAH. SEMUA DATA DI DATA.H ITU UNIVERSAL
void Display() {
    // SEMENTARA UNTUK TEST CASE, HARUS INPUT MANUAL PAKE BERIKUT
    Word LS;
    Word LD;
    Word QUEUE;
    Word STACK;
    Word MAP1;
    Word MAP2;
    Word SB;
    Word CL;
    boolean IsValid = false;

    CreateWord(2, "LS", &LS);
    CreateWord(2, "LD", &LD);
    CreateWord(5, "QUEUE", &QUEUE);
    CreateWord(5, "STACK", &STACK);
    CreateWord(4, "MAP1", &MAP1);
    CreateWord(4, "MAP2", &MAP2);
    CreateWord(2, "SB", &SB);
    CreateWord(2, "CL", &CL);
    
    while (!IsValid) {
        // INPUT BERAKHIR DENGAN ';'
        printf("LS/LD/QUEUE/STACK/MAP1/MAP2/SB/CL:\n");
        StartWordI();
        if (IsWordSame(CurrentWord, LS)) {
            printf("\nINI DAFTAR PENYANYI\n");
            DisplayLS(DaftarPenyanyi);
            IsValid = true;
        }
        else if (IsWordSame(CurrentWord, LD)) {
            printf("\nINI DAFTAR PLAYLIST\n");
            DisplayLD(DaftarPlaylist);
            IsValid = true;
        }
        else if (IsWordSame(CurrentWord, QUEUE)) {
            printf("\nINI QUEUE LAGU\n");
            DisplayQ(QueueLagu);
            IsValid = true;
        }
        else if (IsWordSame(CurrentWord, STACK)) {
            printf("\nINI RIWAYAT LAGU\n");
            DisplayS(RiwayatLagu);
            IsValid = true;
        }
        else if (IsWordSame(CurrentWord, MAP1)) {
            printf("\nINI MAP ALBUM : PENYANYI\n");
            DisplayM(AlbumPenyanyi);
            IsValid = true;
        }
        else if (IsWordSame(CurrentWord, MAP2)) {
            printf("\nINI MAP LAGU : ALBUM\n");
            DisplayM(LaguAlbum);
            IsValid = true;
        }
        else if (IsWordSame(CurrentWord, CL)) {
            printf("\nINI CURRENT LAGU\n");
            DisplayWord(CurrentLagu);
            IsValid = true;
        }
        else if (IsWordSame(CurrentWord, SB)) {
            printf("\nINI ISI PLAYLIST\n");
            DisplaySB(Playlist);
            IsValid = true;
        }
        else {
            printf("Invalid Input\n");
        }
        printf("\n");
    }
}