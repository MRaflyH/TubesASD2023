#include "dzul.h"

void PlaylistCreate()
{
    printf("Masukkan nama playlist yang ingin dibuat : ");
    StartWordI(); // Mulai membaca kata

    // Memeriksa apakah nama playlist valid (minimal 3 karakter non-whitespace)
    int count = 0;
    for (int i = 0; i < CurrentWord.Length; i++) {
        if (CurrentWord.Content[i] != ' ') {
            count++;
        }
    }

    if (count < 3) {
        printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n");
    } else {
        // Membuat StrukBerkait baru untuk playlist
        ElType newPlaylist;
        ListDinamik *l;
        CreateSB(&newPlaylist);
        // Menambahkan playlist baru ke ListDinamik
        InsertLD(l, newPlaylist, l->Neff);
        printf("Playlist %s berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n", CurrentWord.Content);
    }
}
void PlaylistAddSong(){
    printf("Daftar Penyanyi :\n");
    // Tampilkan daftar penyanyi
    // ...

    printf("Masukkan Nama Penyanyi yang dipilih : ");
    StartWordI(); // Mulai membaca kata
    Word penyanyi = CurrentWord;

    // Cek apakah penyanyi ada dalam daftar
    // ...

    printf("Daftar Album oleh %s :\n", penyanyi.Content);
    // Tampilkan daftar album
    // ...

    printf("Masukkan Judul Album yang dipilih : ");
    StartWordI(); // Mulai membaca kata
    Word album = CurrentWord;

    // Cek apakah album ada dalam daftar
    // ...

    printf("Daftar Lagu Album %s oleh %s :\n", album.Content, penyanyi.Content);
    // Tampilkan daftar lagu
    // ...

    printf("Masukkan ID Lagu yang dipilih : ");
    StartWordI(); // Mulai membaca kata
    Word lagu = CurrentWord;

    // Cek apakah lagu ada dalam daftar
    // ...

    printf("Daftar Playlist Pengguna :\n");
    // Tampilkan daftar playlist
    // ...

    printf("Masukkan ID Playlist yang dipilih : ");
    StartWordI(); // Mulai membaca kata
    Word playlist = CurrentWord;

    // Cek apakah playlist ada dalam daftar
    // ...

    // Tambahkan lagu ke playlist
    // ...

    printf("Lagu dengan judul “%s” pada album %s oleh penyanyi %s berhasil ditambahkan ke dalam playlist %s.\n", lagu.Content, album.Content, penyanyi.Content, playlist.Content);
}
void PlaylistAddAlbum(){
    printf("Daftar Penyanyi :\n");
    // Tampilkan daftar penyanyi
    // ...

    printf("Masukkan Nama Penyanyi yang dipilih : ");
    StartWordI(); // Mulai membaca kata
    Word penyanyi = CurrentWord;

    // Cek apakah penyanyi ada dalam daftar
    // ...

    printf("Daftar Album oleh %s :\n", penyanyi.Content);
    // Tampilkan daftar album
    // ...

    printf("Masukkan Judul Album yang dipilih : ");
    StartWordI(); // Mulai membaca kata
    Word album = CurrentWord;

    // Cek apakah album ada dalam daftar
    // ...

    printf("Daftar Playlist Pengguna :\n");
    // Tampilkan daftar playlist
    // ...

    printf("Masukkan ID Playlist yang dipilih : ");
    StartWordI(); // Mulai membaca kata
    Word playlist = CurrentWord;

    // Cek apakah playlist ada dalam daftar
    // ...

    // Tambahkan semua lagu dalam album ke playlist
    // ...

    printf("Album dengan judul “%s” berhasil ditambahkan ke dalam pada playlist pengguna “%s”.\n", album.Content, playlist.Content);
}
void PlaylistSwap(ListDinamik *l, int id, int x, int y){
    if (id < 0 || id >= l->Neff) {
        printf("Tidak ada playlist dengan playlist ID %d\n", id);
        return;
    }

    StrukBerkait playlist = l->Content[id];
    if (x < 0 || x >= LengthSB(playlist) || y < 0 || y >= LengthSB(playlist)) {
        printf("Tidak ada lagu dengan urutan %d atau %d di playlist\n", x, y);
        return;
    }

    // Menukar lagu pada urutan x dan y
    Detail temp = Info(Elmt(playlist, x));
    Info(Elmt(playlist, x)) = Info(Elmt(playlist, y));
    Info(Elmt(playlist, y)) = temp;

    printf("Berhasil menukar lagu dengan nama “%s” dengan “%s” di playlist “%s”\n", Info(Elmt(playlist, x)).judul, Info(Elmt(playlist, y)).judul, Info(playlist).judul);}
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