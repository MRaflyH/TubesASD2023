#ifndef DATA_H
#define DATA_H

#include "ADT/listdinamik.h"
#include "ADT/liststatik.h"
#include "ADT/map.h"
#include "ADT/queue.h"
#include "ADT/set.h"
#include "ADT/stack.h"
#include "ADT/strukturberkait.h"

extern ListStatik DaftarPenyanyi;
extern ListDinamik DaftarPlaylist;
extern Queue QueueLagu;
extern Stack RiwayatLagu;
extern Map AlbumPenyanyi;
extern Map LaguAlbum;
extern Word CurrentLagu;
extern boolean EndProgram;
extern boolean IsLoggedIn;

extern Word WordSTART;
extern Word WordLOAD;
extern Word WordLIST;
extern Word WordDEFAULT;
extern Word WordPLAYLIST;
extern Word WordPLAY;
extern Word WordSONG;
extern Word WordQUEUE;
extern Word WordSWAP;
extern Word WordREMOVE;
extern Word WordCLEAR;
extern Word WordNEXT;
extern Word WordPREVIOUS;
extern Word WordCREATE;
extern Word WordADD;
extern Word WordALBUM;
extern Word WordDELETE;
extern Word WordSTATUS;
extern Word WordSAVE;
extern Word WordQUIT;
extern Word WordY;
extern Word WordN;
extern Word WordHELP;

void LoadWords();

#endif