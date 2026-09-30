#include <iostream>
#include <string>
using namespace std;

int main() {

    // ==============================
    // INISIALISASI DATA
    // ==============================

    string nama[] = {
        "Alvin",
        "Budi",
        "Cahya",
        "Dewi",
        "Eka"
    };

    string kelas[] = {
        "AA-A1",
        "AA-A2",
        "BB-B1",
        "BB-B2",
        "BB-B2",
    
    };

    string mataKuliah[] = {
        "Pemrograman Komputer Dasar",
        "Metematika Diskrit",
        "Algoritma dan Struktur Data",
        "Matematika Teknik",
        "Statistika"
    };

    int baris[] = {
        1,
        1,
        2,
        2,
        1
    };

    int kolom[] = {
        1,
        2,
        1,
        2,
        3
    };

    int jumlahData = 5;
    int pilihan;

    // ==============================
    // MENU UTAMA
    // ==============================

    do {
        cout << "\n========================================\n";
        cout << "        SISTEM INFORMASI UJIAN\n";
        cout << "========================================\n";
        cout << "1. Cari Informasi Ujian\n";
        cout << "2. Tampilkan Seluruh Data\n";
        cout << "3. Keluar\n";
        cout << "========================================\n";

        cout << "Input Pilihan : ";
        cin >> pilihan;

        // ==============================
        // SWITCH CASE PILIHAN
        // ==============================

        switch (pilihan) {

            // --------------------------------
            // CASE 1 : CARI INFORMASI UJIAN
            // --------------------------------
            case 1: {
                string cariNama;

                cout << "\n========================================\n";
                cout << "       CARI INFORMASI UJIAN\n";
                cout << "========================================\n";

                cout << "Masukkan nama mahasiswa : ";
                cin.ignore();
                getline(cin, cariNama);

                bool ditemukan = false;

                for (int i = 0; i < jumlahData; i++) {

                    if (nama[i] == cariNama) {

                        cout << "\nData Ditemukan!\n";
                        cout << "Nama          : " << nama[i] << endl;
                        cout << "Kelas         : " << kelas[i] << endl;
                        cout << "Mata Kuliah   : " << mataKuliah[i] << endl;
                        cout << "Tempat Duduk  : Baris "
                             << baris[i]
                             << ", Kolom "
                             << kolom[i] << endl;

                        ditemukan = true;
                        break;
                    }
                }

                if (!ditemukan) {
                    cout << "\nData mahasiswa tidak ditemukan.\n";
                }

                break;
            }

            // --------------------------------
            // CASE 2 : TAMPILKAN SELURUH DATA
            // --------------------------------
            case 2: {

                cout << "\n===============================================================\n";
                cout << "                    SELURUH DATA UJIAN\n";
                cout << "===============================================================\n";

                cout << "No\tNama\t\tKelas\tMata Kuliah\tTempat Duduk\n";
                cout << "---------------------------------------------------------------\n";

                for (int i = 0; i < jumlahData; i++) {

                    cout << i + 1 << "\t"
                         << nama[i] << "\t"
                         << kelas[i] << "\t"
                         << mataKuliah[i] << "\t"
                         << "Baris " << baris[i]
                         << ", Kolom " << kolom[i]
                         << endl;
                }

                break;
            }

            // --------------------------------
            // CASE 3 : KELUAR
            // --------------------------------
            case 3:

                cout << "\nTerima kasih telah menggunakan Exam Seat Finder.\n";
                break;

            // --------------------------------
            // DEFAULT
            // --------------------------------
            default:

                cout << "\nPilihan tidak tersedia.\n";
                break;
        }

    } while (pilihan != 3);

    return 0;
}