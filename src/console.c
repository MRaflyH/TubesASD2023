#include "console.h"

void START() {
    char * file_name = "../save/config.txt";

    Word tempPenyanyi, tempAlbum, tempLagu, tempPlayist;
    Set tempSetAlbum, tempSetLagu;

    DaftarPenyanyi = CreateLS();
    DaftarPlaylist = CreateLD();
    CreateQ(&QueueLagu);
    CreateS(&RiwayatLagu);
    CreateM(&AlbumPenyanyi);
    CreateM(&LaguAlbum);

    int NPenyanyi, NAlbum, NLagu, NQueue, NRiwayat, NPlaylist;
    Detail DLagu;

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

    printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
    LoggedIn = true;
}

void LOAD() {
    char * file_name = WordtoFileName(CurrentWord);

    if (FileExists(file_name)) {
        Word tempPenyanyi, tempAlbum, tempLagu, tempPlayist;
        Set tempSetAlbum, tempSetLagu;

        DaftarPenyanyi = CreateLS();
        DaftarPlaylist = CreateLD();
        CreateQ(&QueueLagu);
        CreateS(&RiwayatLagu);
        CreateM(&AlbumPenyanyi);
        CreateM(&LaguAlbum);

        int NPenyanyi, NAlbum, NLagu, NQueue, NRiwayat, NPlaylist;
        Detail DLagu;

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
            PushFirstS(&RiwayatLagu, DLagu);
        }

        AdvLineF();

        NPlaylist = 0;
        for (int i = 0; i < CurrentWord.Length; i++) {
            NPlaylist = NPlaylist * 10 + (CurrentWord.Content[i] - '0');
        }

        for (int i = 0; i < NPlaylist; i++) {
            AdvWordF();
            NLagu = 0;
            for (int j = 0; j < CurrentWord.Length; j++) {
                NLagu = NLagu * 10 + (CurrentWord.Content[j] - '0');
            }

            AdvLineF();
            PasteWord(CurrentWord, &tempPlayist);
            InsertLD(&DaftarPlaylist, tempPlayist, i);

            for (int j = 0; j < NLagu; j++) {
                AdvMarkF();
                PasteWord(CurrentWord, &tempPenyanyi);
                AdvMarkF();
                PasteWord(CurrentWord, &tempAlbum);
                AdvLineF();
                PasteWord(CurrentWord, &tempLagu);
                CreateD(&DLagu, tempPenyanyi, tempAlbum, tempLagu);
                InsertSB(&DaftarPlaylist.Content[i], DLagu, j);
            }
        }
        printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");
        LoggedIn = true;
    }
    else {
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n");
    }
}

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

void PLAYLISTCREATE()
{
    printf("Masukkan nama playlist yang ingin dibuat : ");
    StartLineI(); // Mulai membaca kata
    printf("\n");
    // Memeriksa apakah nama playlist valid (minimal 3 karakter non-whitespace)
    int count = 0;
    for (int i = 0; i < CurrentWord.Length; i++) {
        if (CurrentWord.Content[i] != Blank) {
            count++;
        }
    }

    if (count < 3) {
        printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n");
    } else {
        // Menambahkan playlist baru ke ListDinamik
        InsertLD(&DaftarPlaylist, CurrentWord, DaftarPlaylist.Neff);
        printf("Playlist ");
        DisplayWordSpace(CurrentWord);
        printf(" berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n");        
    }
}

void PLAYLISTADDSONG() {
    printf("Daftar Penyanyi :\n");
    DisplayLS(DaftarPenyanyi);
    printf("\n");

    printf("Masukkan Nama Penyanyi yang dipilih : ");
    StartLineI(); // Mulai membaca kata
    printf("\n");
    Word penyanyi = CurrentWord;

    if (SearchLS(DaftarPenyanyi, penyanyi)) {
        printf("Daftar Album oleh ");
        DisplayWordSpace(penyanyi);
        printf(" :\n");
        DisplayValueM(AlbumPenyanyi, penyanyi);
        printf("\n");

        printf("Masukkan Judul Album yang dipilih : ");
        StartLineI(); // Mulai membaca kata
        printf("\n");
        Word album = CurrentWord;
        
        if (IsMemberSet(ValueM(AlbumPenyanyi, penyanyi), album)) {
            printf("Daftar Lagu Album ");
            DisplayWordSpace(album);
            printf(" oleh ");
            DisplayWordSpace(penyanyi);
            printf(" :\n");

            DisplayValueM(LaguAlbum, album);
            printf("\n");

            printf("Masukkan ID Lagu yang dipilih : ");
            StartLineI(); // Mulai membaca kata
            printf("\n");
            int id_lagu = WordToInt(CurrentWord) - 1;

            if (IsIdxValidSet(ValueM(LaguAlbum, album), id_lagu)) {
                Word lagu;
                PasteWord(ValueM(LaguAlbum, album).Content[id_lagu], &lagu);
                printf("Daftar Playlist Pengguna :\n");
                DisplayLD(DaftarPlaylist);
                printf("\n");

                printf("Masukkan ID Playlist yang dipilih : ");
                StartWordI(); // Mulai membaca kata
                printf("\n");
                int id_playlist = WordToInt(CurrentWord) - 1;
                
                if (IsIdxValidLD(DaftarPlaylist, id_playlist)) {
                    Word playlist;
                    Detail d;
                    PasteWord(Title(DaftarPlaylist.Content[id_playlist]), &playlist);
                    
                    CreateD(&d, penyanyi, album, lagu);
                    InsertSB(&DaftarPlaylist.Content[id_playlist], d, LengthSB(DaftarPlaylist.Content[id_playlist]));
                    
                    printf("Lagu dengan judul “");
                    DisplayWordSpace(lagu);
                    printf("” pada album ");
                    DisplayWordSpace(album);
                    printf(" oleh penyanyi \n");
                    DisplayWordSpace(penyanyi);
                    printf(" berhasil ditambahkan ke dalam playlist ");
                    DisplayWordSpace(playlist);
                    printf(".\n");
                }
                else {
                    printf("ID Playlist %d tidak ada dalam daftar. Silakan coba lagi.\n", id_playlist + 1);
                }
            }
            else {
                printf("ID Lagu %d tidak ada dalam daftar. Silakan coba lagi.\n", id_lagu + 1);
            }
        }
        else {
            printf("Album ");
            DisplayWordSpace(album);
            printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        }
    }
    else {
        printf("Penyanyi ");
        DisplayWordSpace(penyanyi);
        printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
    }
}

void PLAYLISTADDALBUM(){
    printf("Daftar Penyanyi :\n");
    DisplayLS(DaftarPenyanyi);
    printf("\n");

    printf("Masukkan Nama Penyanyi yang dipilih : ");
    StartLineI(); // Mulai membaca kata
    printf("\n");
    Word penyanyi = CurrentWord;

    if (SearchLS(DaftarPenyanyi, penyanyi)) {
        printf("Daftar Album oleh ");
        DisplayWordSpace(penyanyi);
        printf(" :\n");
        DisplayValueM(AlbumPenyanyi, penyanyi);
        printf("\n");

        printf("Masukkan Judul Album yang dipilih : ");
        StartLineI(); // Mulai membaca kata
        printf("\n");
        Word album = CurrentWord;
        
        if (IsMemberSet(ValueM(AlbumPenyanyi, penyanyi), album)) {

            printf("Daftar Playlist Pengguna :\n");
            DisplayLD(DaftarPlaylist);
            printf("\n");

            printf("Masukkan ID Playlist yang dipilih : ");
            StartWordI(); // Mulai membaca kata
            printf("\n");
            int id_playlist = WordToInt(CurrentWord) - 1;

            if (IsIdxValidLD(DaftarPlaylist, id_playlist)) {
                Word playlist;
                Detail d;
                PasteWord(Title(DaftarPlaylist.Content[id_playlist]), &playlist);

                Word lagu;
                for (int i = 0; i < ValueM(LaguAlbum, album).Length; i++) {
                    PasteWord(ValueM(LaguAlbum, album).Content[i], &lagu);
                    CreateD(&d, penyanyi, album, lagu);
                    InsertSB(&DaftarPlaylist.Content[id_playlist], d, LengthSB(DaftarPlaylist.Content[id_playlist]));
                }
                
                printf("Album dengan judul “");
                DisplayWordSpace(album);
                printf("” berhasil ditambahkan ke dalam playlist pengguna “");
                DisplayWordSpace(playlist);
                printf("”.\n");
            }
            else {
                printf("ID Playlist %d tidak ada dalam daftar. Silakan coba lagi.\n", id_playlist + 1);
            }
        }
        else {
            printf("Album ");
            DisplayWordSpace(album);
            printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        }
    }
    else {
        printf("Penyanyi ");
        DisplayWordSpace(penyanyi);
        printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
    }
}

void PLAYLISTSWAP(){
    int id, x, y;
    AdvWordI();
    id = WordToInt(CurrentWord)-1;
    AdvWordI();
    x = WordToInt(CurrentWord)-1;
    AdvWordI();
    y = WordToInt(CurrentWord)-1;

    if (id < 0 || id >= DaftarPlaylist.Neff) {
        printf("Tidak ada playlist dengan playlist ID %d\n", id+1);
        return;
    }
    else {
        StrukBerkait playlist = DaftarPlaylist.Content[id];
        
        if (x < 0 || x >= LengthSB(playlist) || y < 0 || y >= LengthSB(playlist)) {
            printf("Tidak ada lagu dengan urutan %d atau %d di playlist\n", x+1, y+1);
        }
        else {
            // Menukar lagu pada urutan x dan y
            Detail tempx, tempy;
            GetSB(&DaftarPlaylist.Content[id], &tempx, x);
            GetSB(&DaftarPlaylist.Content[id], &tempy, y);
            SetSB(&DaftarPlaylist.Content[id], tempy, x);
            SetSB(&DaftarPlaylist.Content[id], tempx, y);

            printf("Berhasil menukar lagu dengan nama “");
            DisplayWordSpace(tempx.Lagu);
            printf("” dengan “");
            DisplayWordSpace(tempy.Lagu);
            printf("” di playlist “");
            DisplayWordSpace(Title(DaftarPlaylist.Content[id]));
            printf("”\n");
        }
    }
}
void PLAYLISTREMOVE() {
    int id, n;
    AdvWordI();
    id = WordToInt(CurrentWord)-1;
    AdvWordI();
    n = WordToInt(CurrentWord)-1;
    if (id < 0 || id >= DaftarPlaylist.Neff) {
        printf("Tidak ada playlist dengan playlist ID %d\n", id+1);
    }
    else {
        StrukBerkait playlist = DaftarPlaylist.Content[id];
        if (n < 0 || n >= LengthSB(playlist)) {
            printf("Tidak ada lagu dengan urutan %d di playlist\n", n+1);
        }
        else {
            Detail lagu;
            DeleteSB(&playlist, &lagu, n);

            printf("Lagu “");
            DisplayWordSpace(lagu.Lagu);
            printf("” oleh “");
            DisplayWordSpace(lagu.Penyanyi);
            printf("” telah dihapus dari playlist “");
            DisplayWordSpace(Title(playlist));
            printf("”!\n");
        }
    }
}

void PLAYLISTDELETE() {
    printf("Daftar Playlist Pengguna :\n");
    DisplayLD(DaftarPlaylist);
    printf("\n");
    // Tampilkan daftar playlist
    // ...

    printf("Masukkan ID Playlist yang dipilih : ");
    StartLineI(); // Mulai membaca kata
    printf("\n");
    int id = WordToInt(CurrentWord) - 1; // Mengubah Word ke integer

    if (id < 0 || id >= DaftarPlaylist.Neff) {
        printf("Tidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.\n", id+1);
    }
    else {
        // Hapus playlist dengan ID yang diberikan
        ElType playlist;
        playlist = GetLD(DaftarPlaylist, id);
        DeleteLD(&DaftarPlaylist, id);
        printf("Playlist ID %d dengan judul ”", id+1);
        DisplayWordSpace(playlist);
        printf("” berhasil dihapus.\n");
    }
}

void STATUS();
void SAVE();
void QUIT();
void HELP();

void INVALIDCOMMAND() {
    if (!ValidCommand) {
        printf("Command tidak bisa dieksekusi!\n");
        ValidCommand = true;
    }
    else {
        printf("Command tidak diketahui!\n");
        KnownCommand = true;
    }
}

void DISPLAY() {
    printf("INI DAFTAR PENYANYI\n");
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
    DisplaySemuaLD(DaftarPlaylist);
}