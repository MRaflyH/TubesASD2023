#ifndef CONSOLE_H
#define CONSOLE_H

#include "data.h"
#include "ADT/mesinfile.h"
#include "ADT/mesininput.h"
#include <unistd.h>

void START();
void LOAD();
void LISTDEFAULT();
void LISTPLAYLIST();
void PLAYSONG();
void PLAYPLAYLIST();
void QUEUESONG();
void QUEUEPLAYLIST();
void QUEUESWAP();
void QUEUEREMOVE();
void QUEUECLEAR();
void SONGNEXT();
void SONGPREVIOUS();
void PLAYLISTCREATE();
void PLAYLISTADDSONG();
void PLAYLISTADDALBUM();
void PLAYLISTSWAP();
void PLAYLISTREMOVE();
void PLAYLISTDELETE();
void STATUS();
void SAVE();
void QUIT();
void HELP();
void INVALIDCOMMAND();
void DISPLAY();
void PRINTWELCOME();
void PRINTKELUAR();

#endif