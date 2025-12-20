#ifndef REGISTRASI_H
#define REGISTRASI_H

#include <iostream>
#include <string>
using namespace std;

// Struktur MataKuliah
struct MataKuliah {
    string kode;
    string nama;
    int sks;
    int tingkat;
    int jumlahPeminat;
    MataKuliah* next;
};

// Struktur Relasi (menghubungkan Mahasiswa dan MataKuliah)
struct Relasi {
    MataKuliah* mataKuliah;
    string semester;
    Relasi* next;
};

// Struktur Mahasiswa
struct Mahasiswa {
    string nim;
    string nama;
    string jurusan;
    Relasi* relasiHead;
    Mahasiswa* next;
};

// Deklarasi fungsi-fungsi
void initMahasiswa(Mahasiswa*& head);
void initMataKuliah(MataKuliah*& head);

// Fungsi untuk Mahasiswa
void tambahMahasiswa(Mahasiswa*& head, string nim, string nama, string jurusan);
void hapusMahasiswa(Mahasiswa*& head, string nim);
Mahasiswa* cariMahasiswa(Mahasiswa* head, string nim);
void tampilkanSemuaMahasiswa(Mahasiswa* head);
void tampilkanMahasiswaByMataKuliah(Mahasiswa* head, string kodeMataKuliah);

// Fungsi untuk MataKuliah
void tambahMataKuliah(MataKuliah*& head, string kode, string nama, int sks, int tingkat);
void hapusMataKuliah(Mahasiswa*& headMahasiswa, MataKuliah*& headMataKuliah, string kode);
MataKuliah* cariMataKuliah(MataKuliah* head, string kode);
void tampilkanSemuaMataKuliah(MataKuliah* head);

// Fungsi untuk Relasi
void tambahRelasi(Mahasiswa* headMahasiswa, MataKuliah* headMataKuliah, 
                  string nim, string kodeMataKuliah, string semester);
void tampilkanMataKuliahByMahasiswa(Mahasiswa* head, string nim);
void tampilkanStatistikPeminat(MataKuliah* head);

#endif