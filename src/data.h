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

void LoadData();

#endif