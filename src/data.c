#include "data.h"

ListStatik DaftarPenyanyi;
ListDinamik DaftarPlaylist;
Queue QueueLagu;
Stack RiwayatLagu;
Map AlbumPenyanyi;
Map LaguAlbum;
Word CurrentLagu;
boolean EndProgram;
boolean LoggedIn;
boolean ValidCommand;
boolean KnownCommand;

Word WordSTART;
Word WordLOAD;
Word WordLIST;
Word WordDEFAULT;
Word WordPLAYLIST;
Word WordPLAY;
Word WordSONG;
Word WordQUEUE;
Word WordSWAP;
Word WordREMOVE;
Word WordCLEAR;
Word WordNEXT;
Word WordPREVIOUS;
Word WordCREATE;
Word WordADD;
Word WordALBUM;
Word WordDELETE;
Word WordSTATUS;
Word WordSAVE;
Word WordQUIT;
Word WordY;
Word WordN;
Word WordHELP;
extern Word WordKOSONG;

void Initiate() {
    EndProgram = false;
    LoggedIn = false;
    ValidCommand = true;
    KnownCommand = true;
    DaftarPenyanyi = CreateLS();
    DaftarPlaylist = CreateLD();
    CreateQ(&QueueLagu);
    CreateS(&RiwayatLagu);
    CreateM(&AlbumPenyanyi);
    CreateM(&LaguAlbum);
    CreateWord(0, "", &CurrentLagu);

    CreateWord(5, "START", &WordSTART);
    CreateWord(4, "LOAD", &WordLOAD);
    CreateWord(4, "LIST", &WordLIST);
    CreateWord(7, "DEFAULT", &WordDEFAULT);
    CreateWord(8, "PLAYLIST", &WordPLAYLIST);
    CreateWord(4, "PLAY", &WordPLAY);
    CreateWord(4, "SONG", &WordSONG);
    CreateWord(5, "QUEUE", &WordQUEUE);
    CreateWord(4, "SWAP", &WordSWAP);
    CreateWord(6, "REMOVE", &WordREMOVE);
    CreateWord(5, "CLEAR", &WordCLEAR);
    CreateWord(4, "NEXT", &WordNEXT);
    CreateWord(8, "PREVIOUS", &WordPREVIOUS);
    CreateWord(6, "CREATE", &WordCREATE);
    CreateWord(3, "ADD", &WordADD);
    CreateWord(5, "ALBUM", &WordALBUM);
    CreateWord(6, "DELETE", &WordDELETE);
    CreateWord(6, "STATUS", &WordSTATUS);
    CreateWord(4, "SAVE", &WordSAVE);
    CreateWord(4, "QUIT", &WordQUIT);
    CreateWord(1, "Y", &WordY);
    CreateWord(1, "N", &WordN);
    CreateWord(4, "HELP", &WordHELP);
    CreateWord(0, "", &WordKOSONG);
}