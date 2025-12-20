#include "regmhs.h"

void menu() {
    cout << "\n=== Sistem Registrasi Mahasiswa ===\n";
    cout << "1 Tambah data mahasiswa\n";
    cout << "2 tambah data mata kuliah\n";
    cout << "3 Tambah relasi (mahasiswa mengambil mata kuliah)\n";
    cout << "4 Hapus data mahasiswa\n";
    cout << "5 Hapus data mata kuliah\n";
    cout << "6 Tampilkan semua mahasiswa\n";
    cout << "7 Tampilkan semua mata kuliah\n";
    cout << "8 Tampilkan mahasiswa berdasarkan mata kuliah\n";
    cout << "9 Tampilkan mata kuliah berdasarkan mahasiswa\n";
    cout << "10 Tampilkan statistik peminat\n";
    cout << "11 Keluar\n";
    cout << "Pilih menu (1-11): ";
}

int main() {
    Mahasiswa* headMahasiswa = nullptr;
    MataKuliah* headMataKuliah = nullptr;
    
    initMahasiswa(headMahasiswa);
    initMataKuliah(headMataKuliah);
    
    // dummy data
    tambahMahasiswa(headMahasiswa, "20251", "Setyo", "Informatika");
    tambahMahasiswa(headMahasiswa, "20252", "Nugroho", "Sistem Informasi");
    tambahMahasiswa(headMahasiswa, "20253", "Afiya", "Teknik Komputer");
    tambahMahasiswa(headMahasiswa, "20254", "Nadifa", "RPL");
    
    tambahMataKuliah(headMataKuliah, "mk1", "Algoritma Pemrograman", 3, 1);
    tambahMataKuliah(headMataKuliah, "mk2", "Struktur Data", 3, 2);
    tambahMataKuliah(headMataKuliah, "mk3", "Basis Data", 3, 2);
    tambahMataKuliah(headMataKuliah, "mk4", "Jaringan Komputer", 3, 3);
    
    tambahRelasi(headMahasiswa, headMataKuliah, "20251", "mk1", "2023/2024 Ganjil");
    tambahRelasi(headMahasiswa, headMataKuliah, "20251", "mk2", "2023/2024 Genap");
    tambahRelasi(headMahasiswa, headMataKuliah, "20252", "mk3", "2024/2025 Ganjil");
    tambahRelasi(headMahasiswa, headMataKuliah, "20252", "mk4", "2023/2024 Genap");
    tambahRelasi(headMahasiswa, headMataKuliah, "20253", "mk5", "2024/2025 Ganjil");
    
    int pilihan;
    string nim, nama, jurusan, kode, semester;
    int sks, tingkat;
    
    do {
        menu();
        cin >> pilihan;
        cin.ignore();
        
        switch(pilihan) {
            case 1:
                cout << "\n++++ Tambah data mahasiswa ++++\n";
                cout << "NIM: ";
                getline(cin, nim);
                cout << "Nama: ";
                getline(cin, nama);
                cout << "Jurusan: ";
                getline(cin, jurusan);
                tambahMahasiswa(headMahasiswa, nim, nama, jurusan);
                break;
                
            case 2:
                cout << "\n++++ Tambah data mata kuliah ++++\n";
                cout << "Kode: ";
                getline(cin, kode);
                cout << "Nama: ";
                getline(cin, nama);
                cout << "SKS: ";
                cin >> sks;
                cout << "Tingkat (1-4): ";
                cin >> tingkat;
                cin.ignore();
                tambahMataKuliah(headMataKuliah, kode, nama, sks, tingkat);
                break;
                
            case 3:
                cout << "\n++++ Tambah relasi ++++\n";
                cout << "NIM Mahasiswa: ";
                getline(cin, nim);
                cout << "Kode Mata Kuliah: ";
                getline(cin, kode);
                cout << "Semester (contoh: 2024/2025 Ganjil): ";
                getline(cin, semester);
                tambahRelasi(headMahasiswa, headMataKuliah, nim, kode, semester);
                break;
                
            case 4:
                cout << "\n--- Hapus data mahasiswa ---\n";
                cout << "Nim mahasiswa yang akan dihapus: ";
                getline(cin, nim);
                hapusMahasiswa(headMahasiswa, nim);
                break;
                
            case 5:
                cout << "\n--- Hapus data mata kuliah ---\n";
                cout << "Kode mata kuliah yang akan dihapus: ";
                getline(cin, kode);
                hapusMataKuliah(headMahasiswa, headMataKuliah, kode);
                break;
                
            case 6:
                tampilkanSemuaMahasiswa(headMahasiswa);
                break;
                
            case 7:
                tampilkanSemuaMataKuliah(headMataKuliah);
                break;
                
            case 8:
                cout << "\n--- Cari mahasiswa berdasarkan mata kuliah ---\n";
                cout << "Kode mata kuliah: ";
                getline(cin, kode);
                tampilkanMahasiswaByMataKuliah(headMahasiswa, kode);
                break;
                
            case 9:
                cout << "\n--- Cari mata kuliah berdasarkan mahasiswa ---\n";
                cout << "Nim Mahasiswa: ";
                getline(cin, nim);
                tampilkanMataKuliahByMahasiswa(headMahasiswa, nim);
                break;
                
            case 10:
                tampilkanStatistikPeminat(headMataKuliah);
                break;
                
            case 11:
                cout << "\nTerima kasih telah menggunakan sistem kami :)\n";
                break;
                
            default:
                cout << "\nPilihan tidak valid, silakan pilih 1-11!!\n";
        }
        
    } while (pilihan != 11);

    return 0;
}