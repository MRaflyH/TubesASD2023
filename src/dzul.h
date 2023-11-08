#ifndef DZUL_H
#define DZUL_H

#include "rafly.h"
#include "data.h"
#include "ADT/mesinfile.h"
#include "ADT/mesininput.h"

void PlaylistCreate(ListDinamik *l);

void PlaylistAddSong();

void PlaylistAddAlbums();

void PlaylistSwap(ListDinamik *l, int id, int x, int y);

void PlaylistRemove(ListDinamik *l, int id, int n);

void PlaylistDelete(ListDinamik *l);

#endif