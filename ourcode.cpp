#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int TINGGI_MIN = 50;   // [BARU] cm
const int TINGGI_MAX = 250;  // [BARU] cm

struct Siswa {
    string nama;
    int tinggi; // dalam cm
};

// [BARU] validasi data siswa
bool validasi(const vector<Siswa>& barisan, string& pesan) {
    if (barisan.empty()) {
        pesan = "Barisan kosong, tidak ada yang diurutkan.";
        return false;
    }
    for (const auto& s : barisan) {
        if (s.tinggi < TINGGI_MIN || s.tinggi > TINGGI_MAX) {
            pesan = "Tinggi tidak valid untuk " + s.nama + " (" + to_string(s.tinggi) +
                    " cm). Harus " + to_string(TINGGI_MIN) + "-" + to_string(TINGGI_MAX) + " cm.";
            return false;
        }
    }
    return true;
}

void bubbleSortSiswa(vector<Siswa>& barisan) {
    int n = barisan.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (barisan[j].tinggi > barisan[j + 1].tinggi) {
                swap(barisan[j], barisan[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void tampilkan(const vector<Siswa>& barisan) {
    for (const auto& s : barisan)
        cout << s.nama << " (" << s.tinggi << " cm)" << endl;
}

void jalankan(string kode, string judul, vector<Siswa> b) {
    cout << "[" << kode << "] " << judul << endl;
    string pesan;
    if (!validasi(b, pesan)) {          // [BARU] cek dulu sebelum sorting
        cout << "ERROR: " << pesan << endl << endl;
        return;
    }
    bubbleSortSiswa(b);
    tampilkan(b);
    cout << endl;
}

int main() {
    cout << "===== KODE BARU =====" << endl << endl;
    jalankan("P1", "Data acak", {{"Budi",165},{"Siti",150},{"Andi",172},{"Dewi",158},{"Rina",145}});
    jalankan("P2", "Sudah terurut", {{"Rina",145},{"Siti",150},{"Dewi",158},{"Budi",165},{"Andi",172}});
    jalankan("P3", "Urutan terbalik", {{"Andi",172},{"Budi",165},{"Dewi",158},{"Siti",150},{"Rina",145}});
    jalankan("N1", "Tinggi negatif", {{"Budi",-165},{"Siti",150},{"Andi",172}});
    jalankan("N2", "Tinggi nol", {{"Budi",165},{"Siti",0},{"Andi",172}});
    jalankan("N3", "Tinggi tidak masuk akal", {{"Budi",165},{"Siti",150},{"Andi",500}});
    jalankan("A1", "Barisan kosong", {});
    jalankan("A2", "Hanya 1 siswa", {{"Budi",165}});
    jalankan("A3", "Semua tinggi sama", {{"Budi",160},{"Siti",160},{"Andi",160},{"Dewi",160}});
    return 0;
}