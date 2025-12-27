# 🎓 Data Registrasi Mahasiswa

## 📋 Deskripsi Proyek
Sistem Registrasi Mahasiswa adalah aplikasi berbasis C++ yang mengimplementasikan konsep **Multi Linked List** untuk memodelkan hubungan many-to-many antara mahasiswa dan mata kuliah. Sistem ini dirancang sebagai solusi digital untuk administrasi akademik di lingkungan perguruan tinggi.

## ✨ Fitur Utama
- **Dua Jenis Linked List**: Implementasi Single Linked List (SLL) untuk data mahasiswa dan Double Linked List (DLL) untuk data mata kuliah
- **Relasi Many-to-Many**: Seorang mahasiswa dapat mengambil banyak mata kuliah, dan satu mata kuliah dapat diambil oleh banyak mahasiswa
- **Auto-Cleanup**: Sistem otomatis membersihkan relasi saat data mahasiswa atau mata kuliah dihapus
- **11 Menu Interaktif**: Antarmuka pengguna yang lengkap dan mudah digunakan

## 🎯 Tujuan Pembelajaran
Proyek ini berhasil mendemonstrasikan:
1. Pemahaman mendalam tentang linked list (SLL vs DLL)
2. Implementasi hubungan many-to-many dalam struktur data
3. Manajemen memori dan pointer yang efektif
4. Pengembangan sistem yang modular dan maintainable
5. Pemenuhan spesifikasi teknis yang kompleks secara lengkap

## 🏗️ Struktur Data

### 1. Mahasiswa (Single Linked List - SLL)
```cpp
struct Mahasiswa {
    string nim;          // NIM mahasiswa
    string nama;         // Nama lengkap
    string jurusan;      // Program studi
    int angkatan;        // Tahun masuk
    Mahasiswa* next;     // Pointer ke node berikutnya (SLL)
    Relasi* relasiHead;  // Pointer ke list relasi
};
```
- **Insert Strategy**: `Insert First` - data baru ditambahkan di depan
- **Delete Strategy**: `Delete Last` - data lama dihapus dari belakang

### 2. Mata Kuliah (Double Linked List - DLL)
```cpp
struct MataKuliah {
    string kode;          // Kode mata kuliah
    string nama;          // Nama mata kuliah
    int sks;              // Jumlah SKS
    int tingkat;          // Tingkat/kelas (1-4)
    int jumlahPeminat;    // Counter jumlah peminat
    MataKuliah* next;     // Pointer ke node berikutnya
};
```
- **Insert Strategy**: `Insert Last` - data baru ditambahkan di belakang
- **Delete Strategy**: `Delete First` - data lama dihapus dari depan

### 3. Relasi (Child Data)
```cpp
struct Relasi {
    MataKuliah* mataKuliah;  // Pointer ke mata kuliah
    string semester;         // Semester pengambilan
    Relasi* next;           // Pointer ke relasi berikutnya
};
```

## 📂 Struktur File Proyek
```
📁 Registrasi-Mahasiswa/
│
├── 📄 main.cpp                    // Program utama dengan menu interaktif
├── 📄 regmhs.cpp                  // Implementasi semua fungsi sistem
├── 📄 regmhs.h                    // Header file (deklarasi struktur dan fungsi)
├── 📄 README.md                   // Dokumentasi utama ini
├── 📄 PENELASAN code baru.txt     // Dokumentasi khusus berisi penjelasan mendetail kode
└── 📁 compare code lama/          // Folder arsip berisi versi kode sebelumnya
```


## 🚀 Cara Menggunakan

### Kompilasi Program
```bash
g++ regmhs.cpp main.cpp -o regmhs.exe
atau
g++ main.cpp regmhs.cpp -o main
```

### Menjalankan Program
```bash
./regmhs.exe
atau
./main
```

### Menu yang Tersedia
```
=== DATA REGISTRASI MAHASISWA ===
1.  Tambah Data Mahasiswa
2.  Tambah Data Mata Kuliah
3.  Tambah Relasi (Mahasiswa Ambil Mata Kuliah)
4.  Hapus Data Mata Kuliah
5.  Hapus Data Mahasiswa
6.  Tampilkan Mahasiswa dengan Mata Kuliahnya
7.  Tampilkan Mahasiswa yang Mengambil Mata Kuliah Tertentu
8.  Tampilkan Mata Kuliah yang Diambil Mahasiswa Tertentu
9.  Statistik Peminat Mata Kuliah
10. Tampilkan Semua Mahasiswa
11. Tampilkan Semua Mata Kuliah
0.  Keluar
```

## ✅ Pemenuhan Spesifikasi Tugas

### A. Spesifikasi Struktur Data (100% Terpenuhi)
| No. | Spesifikasi | Status | Implementasi |
|-----|------------|--------|--------------|
| A1 | Dua jenis list berbeda (SLL dan DLL) | ✅ | Mahasiswa (SLL), Mata Kuliah (DLL) |
| A2 | Insert/Delete berbeda | ✅ | MHS: Insert First/Delete Last, MK: Insert Last/Delete First |
| A3 | Tipe bentukan 3+ atribut dengan integer | ✅ | MHS: 3 string + 1 int, MK: 2 string + 3 int |
| A4 | Data child minimal pointer | ✅ | Relasi memiliki `MataKuliah* mataKuliah` |

### B. 12 Fungsionalitas M ke N (100% Terpenuhi)
| No. | Fungsionalitas | Menu | Status |
|-----|---------------|------|--------|
| B1 | Insert parent depan/belakang | 1 & 2 | ✅ |
| B2 | Show all parent | 10 & 11 | ✅ |
| B3 | Hapus parent beserta relasi | 4 & 5 | ✅ |
| B4 | Cari parent | Terintegrasi | ✅ |
| B5 | Cari child | 7 & 8 | ✅ |
| B6 | Tambah data child | 2 | ✅ |
| B7 | Hubungkan parent ke child | 3 | ✅ |
| B8 | Tampilkan parent beserta child | 6 | ✅ |
| B9 | Cari child pada parent tertentu | 7 & 8 | ✅ |
| B10 | Hapus child pada parent tertentu | Terintegrasi di 4 & 5 | ✅ |
| B11 | Hitung jumlah child | 9 | ✅ |
| B12 | Main program lengkap | Semua menu | ✅ |

### C. Fungsionalitas Spesifik Judul (100% Terpenuhi)
| Fungsi | Deskripsi | Menu | Status |
|--------|-----------|------|--------|
| C(a) | Penambahan data mahasiswa | 1 | ✅ |
| C(b) | Penambahan data matakuliah | 2 | ✅ |
| C(c) | Penentuan relasi | 3 | ✅ |
| C(d) | Menghapus data matakuliah | 4 | ✅ |
| C(e) | Menghapus data mahasiswa | 5 | ✅ |
| C(f) | Tampilkan semua mahasiswa dengan matakuliahnya | 6 | ✅ |
| C(g) | Tampilkan mahasiswa yang mengambil matakuliah tertentu | 7 | ✅ |
| C(h) | Tampilkan matakuliah yang diambil mahasiswa tertentu | 8 | ✅ |
| C(i) | Statistik peminat | 9 | ✅ |

## 🧠 Konsep Kunci Implementasi

### 1. Dual-List Strategy
Sistem menggunakan dua filosofi penyimpanan berbeda:
- **SLL untuk data dinamis** (Mahasiswa): Data baru diprioritaskan (depan), data lama dihapus (belakang)
- **DLL untuk data katalog** (Mata Kuliah): Data baru ditambahkan berurutan (belakang), data usang dihapus (depan)

### 2. Auto-Cleanup Mechanism
```cpp
// Contoh auto-cleanup saat menghapus mahasiswa
void deleteLastMhs(...) {
    // 1. Hapus semua relasi milik mahasiswa
    // 2. Hapus node mahasiswa dari list
    // 3. Memory dibersihkan otomatis
}
```

### 3. Many-to-Many Relationship
Setiap mahasiswa memiliki pointer ke list relasi, dan setiap relasi menunjuk ke mata kuliah. Ini memungkinkan hubungan kompleks dengan integritas data terjaga.

## 📊 Contoh Data Dummy
Program telah dilengkapi dengan data dummy untuk testing:
- 4 Mahasiswa: Setyo, Nugroho, Afiya, Nadifa
- 4 Mata Kuliah: Algoritma, Struktur Data, Basis Data, Jaringan Komputer
- 5 Relasi: Hubungan antara mahasiswa dan mata kuliah

## 🔧 Teknologi yang Digunakan
- **Bahasa Pemrograman**: C++ (Standard 11)
- **Compiler**: GCC/g++
- **IDE**: Visual Studio Code / Code::Blocks
- **Struktur Data**: Single Linked List, Double Linked List
- **Konsep**: Abstract Data Type (ADT), Pointers, Memory Management

## 👥 Kontributor
- Afiya Nadifa (103072400036) - Pengembangan dan implementasi sistem
- Setyo Nugroho (103072400045) - Pembuatan code .h .cpp

## 📝 Catatan Penting
1. Program mengimplementasikan **Abstract Data Type (ADT)** dengan pemisahan antara deklarasi (.h) dan implementasi (.cpp)
2. **Memory management** dilakukan dengan hati-hati untuk mencegah memory leak
3. **Validasi input** dasar telah diimplementasikan pada menu utama
4. Sistem siap untuk **diperluas** dengan fitur tambahan seperti penyimpanan ke file


