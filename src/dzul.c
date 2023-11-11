#include "dzul.h"

void PlaylistCreate()
{
    printf("Masukkan nama playlist yang ingin dibuat : ");
    StartLineI(); // Mulai membaca kata

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
        printf("Playlist %s berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n", CurrentWord.Content);
    }
}

void PlaylistAddSong(){
    printf("Daftar Penyanyi :\n");
    DisplayLS(DaftarPenyanyi);

    printf("Masukkan Nama Penyanyi yang dipilih : ");
    StartLineI(); // Mulai membaca kata
    Word penyanyi = CurrentWord;

    if (SearchLS(DaftarPenyanyi, penyanyi)) {
        printf("Daftar Album oleh ");
        DisplayWordSpace(penyanyi);
        printf(" :\n");
        DisplayValueM(AlbumPenyanyi, penyanyi);

        printf("Masukkan Judul Album yang dipilih : ");
        StartLineI(); // Mulai membaca kata
        Word album = CurrentWord;
        
        if (IsMemberSet(ValueM(AlbumPenyanyi, penyanyi), album)) {
            printf("Daftar Lagu Album ");
            DisplayWordSpace(album);
            printf(" oleh ");
            DisplayWordSpace(penyanyi);
            printf(" :\n");

            DisplayValueM(LaguAlbum, album);

            printf("Masukkan ID Lagu yang dipilih : ");
            StartLineI(); // Mulai membaca kata
            int id_lagu = WordToInt(CurrentWord) - 1;

            if (IsIdxValidSet(ValueM(LaguAlbum, album), id_lagu)) {
                Word lagu;
                PasteWord(ValueM(LaguAlbum, album).Content[id_lagu], &lagu);
                printf("Daftar Playlist Pengguna :\n");
                DisplayLD(DaftarPlaylist);

                printf("Masukkan ID Playlist yang dipilih : ");
                StartWordI(); // Mulai membaca kata
                int id_playlist = WordToInt(CurrentWord) - 1;

                if (IsIdValidLD(DaftarPlaylist, id_playlist)) {
                    Word playlist;
                    Detail d;
                    PasteWord(Title(DaftarPlaylist.Content[id_playlist]), &playlist);
                    
                    CreateD(&d, penyanyi, album, lagu);
                    InsertSB(&First(DaftarPlaylist.Content[id_playlist]), d, LengthSB(DaftarPlaylist.Content[id_playlist]));
                    
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

void PlaylistAddAlbum(){
    printf("Daftar Penyanyi :\n");
    DisplayLS(DaftarPenyanyi);

    printf("Masukkan Nama Penyanyi yang dipilih : ");
    StartLineI(); // Mulai membaca kata
    Word penyanyi = CurrentWord;

    if (SearchLS(DaftarPenyanyi, penyanyi)) {
        printf("Daftar Album oleh ");
        DisplayWordSpace(penyanyi);
        printf(" :\n");
        DisplayValueM(AlbumPenyanyi, penyanyi);

        printf("Masukkan Judul Album yang dipilih : ");
        StartLineI(); // Mulai membaca kata
        Word album = CurrentWord;
        
        if (IsMemberSet(ValueM(AlbumPenyanyi, penyanyi), album)) {

            printf("Daftar Playlist Pengguna :\n");
            DisplayLD(DaftarPlaylist);

            printf("Masukkan ID Playlist yang dipilih : ");
            StartWordI(); // Mulai membaca kata
            int id_playlist = WordToInt(CurrentWord) - 1;

            if (IsIdValidLD(DaftarPlaylist, id_playlist)) {
                Word playlist;
                Detail d;
                PasteWord(Title(DaftarPlaylist.Content[id_playlist]), &playlist);

                Word lagu;
                for (int i = 0; i < ValueM(LaguAlbum, album).Length; i++) {
                    PasteWord(ValueM(LaguAlbum, album).Content[i], &lagu);
                    CreateD(&d, penyanyi, album, lagu);
                    InsertSB(&First(DaftarPlaylist.Content[id_playlist]), d, LengthSB(DaftarPlaylist.Content[id_playlist]));
                }
                
                printf("Album dengan judul “");
                DisplayWordSpace(album);
                printf(" berhasil ditambahkan ke dalam playlist pengguna “");
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

void PlaylistSwap(){
    int id, x, y;
    AdvWordI();
    id = WordToInt(CurrentWord)-1;
    AdvWordI();
    x = WordToInt(CurrentWord)-1;
    AdvWordI();
    y = WordToInt(CurrentWord)-1;

    if (id < 0 || id >= DaftarPlaylist.Neff) {
        printf("Tidak ada playlist dengan playlist ID %d\n", id);
        return;
    }
    else {
        StrukBerkait playlist = DaftarPlaylist.Content[id];
        
        if (x < 0 || x >= LengthSB(playlist) || y < 0 || y >= LengthSB(playlist)) {
            printf("Tidak ada lagu dengan urutan %d atau %d di playlist\n", x, y);
        }
        else {
            // Menukar lagu pada urutan x dan y
            Detail tempx, tempy;
            GetSB(DaftarPlaylist.Content, &tempx, x);
            GetSB(DaftarPlaylist.Content, &tempy, y);
            SetSB(DaftarPlaylist.Content, tempy, x);
            SetSB(DaftarPlaylist.Content, tempx, y);

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

void PlaylistRemove(ListDinamik *l, int id, int n){
    if (id < 0 || id >= l->Neff) {
        printf("Tidak ada playlist dengan playlist ID %d\n", id);
        return;
    }

    StrukBerkait playlist = l->Content[id];
    if (n < 0 || n >= LengthSB(playlist)) {
        printf("Tidak ada lagu dengan urutan %d di playlist\n", n);
        return;
    }

    // Hapus lagu pada urutan n
    Detail lagu;
    DeleteSB(&playlist, &lagu, n);

    printf("Lagu “%s” oleh “%s” telah dihapus dari playlist “%s”!\n", lagu.judul, lagu.penyanyi, Info(playlist).judul);
}
void PlaylistDelete(){
    ListDinamik *l; int id;
    printf("Daftar Playlist Pengguna :\n");
    // Tampilkan daftar playlist
    // ...

    printf("Masukkan ID Playlist yang dipilih : ");
    StartWordI(); // Mulai membaca kata
    int id = atoi(CurrentWord.Content); // Mengubah Word ke integer

    if (id < 0 || id >= l->Neff) {
        printf("Tidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.\n", id);
        return;
    }

    // Hapus playlist dengan ID yang diberikan
    DeleteLD(l, id);
    printf("Playlist ID %d berhasil dihapus.\n", id);
}