#ifndef COMMAND_H
#define COMMAND_H

void Start();
// START merupakan salah satu command yang dimasukkan pertama kali dalam WayangWave.Setelah menekan
// Enter, dibaca file konfigurasi default yang berisi daftar penyanyi serta album yang dimiliki.
// >> START;
// File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.
// 1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111

void Load();

void List();

void Play();

void Queue();

void Song();

void Playlist();

void Status();

void Save();

void Quit();

void Help();

void InvalidCommand();


#endif