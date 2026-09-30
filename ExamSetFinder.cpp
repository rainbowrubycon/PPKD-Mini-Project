#include <iostream>
#include <string>
using namespace std;

// Struct untuk menyimpan data ujian
struct DataUjian {
    int nomorUjian;
    string nama;
    string mataKuliah;
    string ruangan;
    string waktu;
    int baris;
    int kolom;
};

// Function untuk menampilkan menu
void tampilkanMenu() {
    cout << "\n====================================\n";
    cout << "         EXAM SEAT FINDER\n";
    cout << "====================================\n";
    cout << "1. Cari Informasi Ujian\n";
    cout << "2. Tampilkan Seluruh Data\n";
    cout << "3. Keluar\n";
    cout << "====================================\n";
}

// Function untuk mencari data berdasarkan nomor ujian
void cariData(DataUjian data[], int jumlahData) {
    int nomor;
    bool ditemukan = false;

    cout << "\nMasukkan nomor ujian: ";
    cin >> nomor;

    // Looping untuk mencari data
    for (int i = 0; i < jumlahData; i++) {

        if (data[i].nomorUjian == nomor) {
            cout << "\n===== HASIL PENCARIAN =====\n";
            cout << "Nomor Ujian  : " << data[i].nomorUjian << endl;
            cout << "Nama         : " << data[i].nama << endl;
            cout << "Mata Kuliah  : " << data[i].mataKuliah << endl;
            cout << "Ruangan      : " << data[i].ruangan << endl;
            cout << "Waktu        : " << data[i].waktu << endl;
            cout << "Posisi Duduk : Baris " << data[i].baris
                 << ", Kolom " << data[i].kolom << endl;

            ditemukan = true;
            break;
        }
    }

    // Jika data tidak ditemukan
    if (!ditemukan) {
        cout << "\nData dengan nomor ujian "
             << nomor << " tidak ditemukan.\n";
    }
}

// Function untuk menampilkan seluruh data
void tampilkanSemuaData(DataUjian data[], int jumlahData) {

    cout << "\n========== SELURUH DATA UJIAN ==========\n";

    for (int i = 0; i < jumlahData; i++) {

        cout << "\nData ke-" << i + 1 << endl;
        cout << "Nomor Ujian  : " << data[i].nomorUjian << endl;
        cout << "Nama         : " << data[i].nama << endl;
        cout << "Mata Kuliah  : " << data[i].mataKuliah << endl;
        cout << "Ruangan      : " << data[i].ruangan << endl;
        cout << "Waktu        : " << data[i].waktu << endl;
        cout << "Posisi Duduk : Baris " << data[i].baris
             << ", Kolom " << data[i].kolom << endl;

        cout << "-----------------------------------------\n";
    }
}

int main() {

    // Array of struct
    DataUjian data[4] = {

        {1001, "Naura Fauziyaturrohmah",
         "Pemrograman Komputer", "Lab 1",
         "08.00 - 10.00", 1, 1},

        {1002, "Aliyya Nafisa",
         "Pemrograman Komputer", "Lab 1",
         "08.00 - 10.00", 1, 2},

        {1003, "Aulia Rahma",
         "Matematika Teknik", "Lab 2",
         "10.00 - 12.00", 2, 1},

        {1004, "Nabila Putri",
         "Matematika Teknik", "Lab 2",
         "10.00 - 12.00", 2, 2}
    };

    int jumlahData = 4;
    int pilihan;

    // Looping menu
    do {

        tampilkanMenu();

        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        // Switch case untuk pilihan menu
        switch (pilihan) {

            case 1:
                cariData(data, jumlahData);
                break;

            case 2:
                tampilkanSemuaData(data, jumlahData);
                break;

            case 3:
                cout << "\nTerima kasih telah menggunakan ";
                cout << "Exam Seat Finder!\n";
                break;

            default:
                cout << "\nPilihan tidak tersedia.\n";
                cout << "Silakan pilih menu 1-3.\n";
        }

    } while (pilihan != 3);

    return 0;
}