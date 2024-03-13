#include <iostream>

using namespace std;

// Fungsi untuk menjumlahkan dua bilangan bulat
int tambah(int a, int b) {
    return a + b;
}

// Fungsi untuk mengalikan dua bilangan bulat
int kali(int a, int b) {
    return a * b;
}

int main() {
    int angka1, angka2;

    // Meminta pengguna untuk memasukkan dua angka bulat
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    // Menampilkan hasil penjumlahan dan perkalian
    cout << "Hasil penjumlahan: " << tambah(angka1, angka2) << endl;
    cout << "Hasil perkalian: " << kali(angka1, angka2) << endl;

    return 0;
}