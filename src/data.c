#include "data.h"

ListStatik DaftarPenyanyi;
ListStatik DaftarPenyanyi;
ListDinamik DaftarPlaylist;
Queue QueueLagu;
Stack RiwayatLagu;
Map AlbumPenyanyi;
Map LaguAlbum;
StrukBerkait Playlist;
Word CurrentLagu;


void LoadData() {
    Word tempPenyanyi, tempAlbum, tempLagu;
    Set tempSetAlbum, tempSetLagu;

    DaftarPenyanyi = CreateLS();
    DaftarPlaylist = CreateLD();
    CreateQ(&QueueLagu);
    CreateS(&RiwayatLagu);
    CreateM(&AlbumPenyanyi);
    CreateM(&LaguAlbum);
    CreateSB(&Playlist);

    CreateWord(9, "BLACKPINK", &tempPenyanyi);
    InsertLS(&DaftarPenyanyi, tempPenyanyi);
    CreateSet(&tempSetAlbum);

        CreateWord(9, "BORN PINK", &tempAlbum);
        AddSet(&tempSetAlbum, tempAlbum);
        CreateSet(&tempSetLagu);
            CreateWord(10, "Pink Venom", &tempLagu);
            AddSet(&tempSetLagu, tempLagu);
            CreateWord(9, "Shut Down", &tempLagu);
            AddSet(&tempSetLagu, tempLagu);
            CreateWord(9, "Typa Girl", &tempLagu);
            AddSet(&tempSetLagu, tempLagu);
            CreateWord(14, "Ready For Love", &tempLagu);
            AddSet(&tempSetLagu, tempLagu);
        InsertM(&LaguAlbum, tempAlbum, tempSetLagu);

        CreateWord(9, "THE ALBUM", &tempAlbum);
        AddSet(&tempSetAlbum, tempAlbum);
        CreateSet(&tempSetLagu);
            CreateWord(17, "How You Like That", &tempLagu);
            AddSet(&tempSetLagu, tempLagu);
            CreateWord(29, "Ice Cream (with Selena Gomez)", &tempLagu);
            AddSet(&tempSetLagu, tempLagu);
            CreateWord(29, "Bet You Wanna (Feat. Cardi B)", &tempLagu);
            AddSet(&tempSetLagu, tempLagu);
        InsertM(&LaguAlbum, tempAlbum, tempSetLagu);
    
    InsertM(&AlbumPenyanyi, tempPenyanyi, tempSetAlbum);

    CreateWord(14, "Arctic Monkeys", &tempPenyanyi);
    InsertLS(&DaftarPenyanyi, tempPenyanyi);
    CreateSet(&tempSetAlbum);

        CreateWord(25, "Favourite Worst Nightmare", &tempAlbum);
        AddSet(&tempSetAlbum, tempAlbum);
        CreateSet(&tempSetLagu);
            CreateWord(10, "Brianstorm", &tempLagu);
            AddSet(&tempSetLagu, tempLagu);
            CreateWord(12, "Teddy Picker", &tempLagu);
            AddSet(&tempSetLagu, tempLagu);
            CreateWord(22, "Fluorescent Adolescent", &tempLagu);
            AddSet(&tempSetLagu, tempLagu);
            CreateWord(17, "Old Yellow Bricks", &tempLagu);
            AddSet(&tempSetLagu, tempLagu);
            CreateWord(3, "505", &tempLagu);
            AddSet(&tempSetLagu, tempLagu);
        InsertM(&LaguAlbum, tempAlbum, tempSetLagu);

        CreateWord(6, "Humbug", &tempAlbum);
        AddSet(&tempSetAlbum, tempAlbum);
        CreateSet(&tempSetLagu);
            CreateWord(12, "My Propeller", &tempLagu);
            AddSet(&tempSetLagu, tempLagu);
            CreateWord(18, "Crying Lightning", &tempLagu);
            AddSet(&tempSetLagu, tempLagu);
            CreateWord(11, "Secret Door", &tempLagu);
            AddSet(&tempSetLagu, tempLagu);
            CreateWord(15, "Pretty Visitors", &tempLagu);
            AddSet(&tempSetLagu, tempLagu);
        InsertM(&LaguAlbum, tempAlbum, tempSetLagu);
    
        CreateWord(2, "AM", &tempAlbum);
        AddSet(&tempSetAlbum, tempAlbum);
        CreateSet(&tempSetLagu);
            CreateWord(16, "Do I Wanna Know?", &tempLagu);
            AddSet(&tempSetLagu, tempLagu);
            CreateWord(9, "R U Mine?", &tempLagu);
            AddSet(&tempSetLagu, tempLagu);
            CreateWord(8, "Arabella", &tempLagu);
            AddSet(&tempSetLagu, tempLagu);
        InsertM(&LaguAlbum, tempAlbum, tempSetLagu);

    InsertM(&AlbumPenyanyi, tempPenyanyi, tempSetAlbum);

}
