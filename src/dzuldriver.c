#include "dzul.h"

int main() {
    EndProgram = false;
    DaftarPenyanyi = CreateLS();
    DaftarPlaylist = CreateLD();
    CreateQ(&QueueLagu);
    CreateS(&RiwayatLagu);
    CreateM(&AlbumPenyanyi);
    CreateM(&LaguAlbum);

    Word WordDisplay;

    LoadWords();
    CreateWord(7, "DISPLAY", &WordDisplay);

    while (!EndProgram) {
        StartWordI();
        if (IsWordSame(CurrentWord, WordLOAD)) {
            AdvWordI();
            LOAD();
        }
        else if (IsWordSame(CurrentWord, WordPLAYLIST)) {
            AdvWordI();
            if (IsWordSame(CurrentWord, WordCREATE)) {
                PLAYLISTCREATE();
            }
        }
        else if (IsWordSame(CurrentWord, WordDisplay)) {
            DISPLAY();
        }
        else if (IsWordSame(CurrentWord, WordQUIT)) {
            EndProgram = true;
        }
        printf("\n");
    }
    return 0;
}