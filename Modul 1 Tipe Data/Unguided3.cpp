#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, string> daftarKontak; // Map untuk menyimpan nama dan nomor telepon

    // Memasukkan beberapa kontak awal ke dalam map
    daftarKontak["kevin"] = "123456";
    daftarKontak["fajar"] = "987654";
    daftarKontak["ikram"] = "555777";

    string nama;
    cout << "Masukkan nama kontak untuk mencari nomor telepon: ";
    getline(cin, nama);

    // Mencari nomor telepon berdasarkan nama kontak
    auto iter = daftarKontak.find(nama);
    if (iter != daftarKontak.end()) {
        cout << "Nomor telepon untuk " << nama << ": " << iter->second << endl;
    } else {
        cout << "Kontak dengan nama '" << nama << "' tidak ditemukan." << endl;
    }

    return 0;
}
