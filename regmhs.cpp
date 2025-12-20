#include "regmhs.h"
#include <iomanip>

void initMahasiswa(Mahasiswa*& head) {
    head = nullptr;
}

void initMataKuliah(MataKuliah*& head) {
    head = nullptr;
}

void tambahMahasiswa(Mahasiswa*& head, string nim, string nama, string jurusan) {
    Mahasiswa* baru = new Mahasiswa;
    baru->nim = nim;
    baru->nama = nama;
    baru->jurusan = jurusan;
    baru->relasiHead = nullptr;
    baru->next = nullptr;
    
    if (head == nullptr) {
        head = baru;
    } else {
        Mahasiswa* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    
    cout << "Mahasiswa " << nama << " (" << nim << ") berhasil ditambahkan.\n";
}

Mahasiswa* cariMahasiswa(Mahasiswa* head, string nim) {
    Mahasiswa* temp = head;
    while (temp != nullptr) {
        if (temp->nim == nim) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void hapusMahasiswa(Mahasiswa*& head, string nim) {
    if (head == nullptr) {
        cout << "Data mahasiswa kosong.\n";
        return;
    }
    
    Mahasiswa* hapus = nullptr;
    
    // jika yang dihapus adalah head
    if (head->nim == nim) {
        hapus = head;
        head = head->next;
    } else {
        Mahasiswa* temp = head;
        while (temp->next != nullptr && temp->next->nim != nim) {
            temp = temp->next;
        }
        
        if (temp->next == nullptr) {
            cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
            return;
        }
        
        hapus = temp->next;
        temp->next = hapus->next;
    }
    
    // delete semmua relasi mhs
    Relasi* relTemp = hapus->relasiHead;
    while (relTemp != nullptr) {
        Relasi* hapusRel = relTemp;
        relTemp = relTemp->next;
        delete hapusRel;
    }
    
    delete hapus;
    cout << "Mahasiswa dengan NIM " << nim << " berhasil dihapus.\n";
}

void tambahMataKuliah(MataKuliah*& head, string kode, string nama, int sks, int tingkat) {
    MataKuliah* baru = new MataKuliah;
    baru->kode = kode;
    baru->nama = nama;
    baru->sks = sks;
    baru->tingkat = tingkat;
    baru->jumlahPeminat = 0;
    baru->next = nullptr;
    
    if (head == nullptr) {
        head = baru;
    } else {
        MataKuliah* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    
    cout << "Mata kuliah " << nama << " (" << kode << ") berhasil ditambahkan.\n";
}

MataKuliah* cariMataKuliah(MataKuliah* head, string kode) {
    MataKuliah* temp = head;
    while (temp != nullptr) {
        if (temp->kode == kode) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void hapusMataKuliah(Mahasiswa*& headMahasiswa, MataKuliah*& headMataKuliah, string kode) {
    if (headMataKuliah == nullptr) {
        cout << "Data mata kuliah kosong.\n";
        return;
    }
    
    MataKuliah* hapus = nullptr;
    
    // jika yang dihapus adalah head
    if (headMataKuliah->kode == kode) {
        hapus = headMataKuliah;
        headMataKuliah = headMataKuliah->next;
    } else {
        MataKuliah* temp = headMataKuliah;
        while (temp->next != nullptr && temp->next->kode != kode) {
            temp = temp->next;
        }
        
        if (temp->next == nullptr) {
            cout << "Mata kuliah dengan kode " << kode << " tidak ditemukan.\n";
            return;
        }
        
        hapus = temp->next;
        temp->next = hapus->next;
    }
    
    // hapus relasi di semua mahasiswa yang mengambil mata kuliah ini
    Mahasiswa* mhsTemp = headMahasiswa;
    while (mhsTemp != nullptr) {
        Relasi* rel = mhsTemp->relasiHead;
        Relasi* prev = nullptr;
        
        while (rel != nullptr) {
            if (rel->mataKuliah->kode == kode) {
                if (prev == nullptr) {
                    mhsTemp->relasiHead = rel->next;
                } else {
                    prev->next = rel->next;
                }
                
                Relasi* hapusRel = rel;
                rel = rel->next;
                delete hapusRel;
            } else {
                prev = rel;
                rel = rel->next;
            }
        }
        mhsTemp = mhsTemp->next;
    }
    
    delete hapus;
    cout << "Mata kuliah dengan kode " << kode << " berhasil dihapus.\n";
}

void tambahRelasi(Mahasiswa* headMahasiswa, MataKuliah* headMataKuliah, 
                  string nim, string kodeMataKuliah, string semester) {
    
    Mahasiswa* mhs = cariMahasiswa(headMahasiswa, nim);
    MataKuliah* mk = cariMataKuliah(headMataKuliah, kodeMataKuliah);
    
    if (mhs == nullptr) {
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
        return;
    }
    
    if (mk == nullptr) {
        cout << "Mata kuliah dengan kode " << kodeMataKuliah << " tidak ditemukan.\n";
        return;
    }
    
    //cek apakah relasi sudah ada
    Relasi* relTemp = mhs->relasiHead;
    while (relTemp != nullptr) {
        if (relTemp->mataKuliah->kode == kodeMataKuliah) {
            cout << "Mahasiswa " << mhs->nama << " sudah mengambil mata kuliah " << mk->nama << ".\n";
            return;
        }
        relTemp = relTemp->next;
    }
    
    // tambah relasi baru
    Relasi* baru = new Relasi;
    baru->mataKuliah = mk;
    baru->semester = semester;
    baru->next = nullptr;
    
    if (mhs->relasiHead == nullptr) {
        mhs->relasiHead = baru;
    } else {
        Relasi* temp = mhs->relasiHead;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    
    mk->jumlahPeminat++;
    cout << "Mahasiswa " << mhs->nama << " berhasil ditambahkan ke mata kuliah " << mk->nama << ".\n";
}

void tampilkanSemuaMahasiswa(Mahasiswa* head) {
    if (head == nullptr) {
        cout << "Data mahasiswa kosong.\n";
        return;
    }
    
    cout << "\n=== Data Mahasiswa ===\n";
    cout << "=====================================================================================\n";
    cout << setw(15) << left << "NIM" 
         << setw(25) << left << "Nama" 
         << setw(20) << left << "Jurusan" 
         << setw(20) << left << "Jumlah Mata Kuliah" << endl;
    cout << "=====================================================================================\n";
    
    Mahasiswa* temp = head;
    while (temp != nullptr) {
        int jumlahMK = 0;
        Relasi* relTemp = temp->relasiHead;
        while (relTemp != nullptr) {
            jumlahMK++;
            relTemp = relTemp->next;
        }
        
        cout << setw(15) << left << temp->nim
             << setw(25) << left << temp->nama
             << setw(20) << left << temp->jurusan
             << setw(20) << left << jumlahMK << endl;
        temp = temp->next;
    }
    cout << "=====================================================================================\n";
}

void tampilkanSemuaMataKuliah(MataKuliah* head) {
    if (head == nullptr) {
        cout << "Data matkul kosong\n";
        return;
    }
    
    cout << "\n=== Data Semua Mata Kuliah ===\n";
    cout << "=====================================================================================\n";
    cout << setw(10) << left << "Kode" 
         << setw(30) << left << "Nama Mata Kuliah" 
         << setw(8) << left << "SKS" 
         << setw(10) << left << "Tingkat" 
         << setw(15) << left << "Jumlah Peminat" << endl;
    cout << "=====================================================================================\n";
    
    MataKuliah* temp = head;
    while (temp != nullptr) {
        cout << setw(10) << left << temp->kode
             << setw(30) << left << temp->nama
             << setw(8) << left << temp->sks
             << setw(10) << left << temp->tingkat
             << setw(15) << left << temp->jumlahPeminat << endl;
        temp = temp->next;
    }
    cout << "=====================================================================================\n";
}

void tampilkanMahasiswaByMataKuliah(Mahasiswa* head, string kodeMataKuliah) {
    bool found = false;
    
    cout << "\n=== Mahasiswa yang mengambil mata kuliah " << kodeMataKuliah << " ===\n";
    cout << "=================================================================\n";
    cout << setw(15) << left << "NIM" 
         << setw(25) << left << "Nama" 
         << setw(20) << left << "Jurusan" << endl;
    cout << "=================================================================\n";
    
    Mahasiswa* mhsTemp = head;
    while (mhsTemp != nullptr) {
        Relasi* relTemp = mhsTemp->relasiHead;
        while (relTemp != nullptr) {
            if (relTemp->mataKuliah->kode == kodeMataKuliah) {
                cout << setw(15) << left << mhsTemp->nim
                     << setw(25) << left << mhsTemp->nama
                     << setw(20) << left << mhsTemp->jurusan << endl;
                found = true;
                break;
            }
            relTemp = relTemp->next;
        }
        mhsTemp = mhsTemp->next;
    }
    
    if (!found) {
        cout << "Tidak ada mahasiswa yang mengambil mata kuliah ini\n";
    }
    cout << "=================================================================\n";
}

void tampilkanMataKuliahByMahasiswa(Mahasiswa* head, string nim) {
    Mahasiswa* mhs = cariMahasiswa(head, nim);
    
    if (mhs == nullptr) {
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
        return;
    }
    
    cout << "\n=== Mata kuliah yang diambil oleh " << mhs->nama << " (" << nim << ") ===\n";
    cout << "=========================================================================\n";
    cout << setw(10) << left << "Kode" 
         << setw(30) << left << "Nama Mata Kuliah" 
         << setw(8) << left << "SKS" 
         << setw(10) << left << "Tingkat" 
         << setw(12) << left << "Semester" << endl;
    cout << "=========================================================================\n";
    
    Relasi* relTemp = mhs->relasiHead;
    if (relTemp == nullptr) {
        cout << "\"" << mhs->nama << "\"" << " belum mengambil mata kuliah apapun\n";
    } else {
        while (relTemp != nullptr) {
            MataKuliah* mk = relTemp->mataKuliah;
            cout << setw(10) << left << mk->kode
                 << setw(30) << left << mk->nama
                 << setw(8) << left << mk->sks
                 << setw(10) << left << mk->tingkat
                 << setw(12) << left << relTemp->semester << endl;
            relTemp = relTemp->next;
        }
    }
    cout << "=========================================================================\n";
}

void tampilkanStatistikPeminat(MataKuliah* head) {
    if (head == nullptr) {
        cout << "data mata kuliah kosong\n";
        return;
    }
    
    MataKuliah* temp = head;
    MataKuliah* terbanyak = head;
    MataKuliah* tersedikit = head;
    
    while (temp != nullptr) {
        if (temp->jumlahPeminat > terbanyak->jumlahPeminat) {
            terbanyak = temp;
        }
        if (temp->jumlahPeminat < tersedikit->jumlahPeminat) {
            tersedikit = temp;
        }
        temp = temp->next;
    }
    
    cout << "\n=== statistik mata kuliah ===\n";
    cout << "Mata kuliah dengan peminat terbanyak:\n";
    cout << "Kode     : " << terbanyak->kode << endl;
    cout << "Nama     : " << terbanyak->nama << endl;
    cout << "Jumlah   : " << terbanyak->jumlahPeminat << " mahasiswa\n";
    
    cout << "\nMata kuliah dengan peminat sedikit:\n";
    cout << "Kode     : " << tersedikit->kode << endl;
    cout << "Nama     : " << tersedikit->nama << endl;
    cout << "Jumlah   : " << tersedikit->jumlahPeminat << " mahasiswa\n";
}