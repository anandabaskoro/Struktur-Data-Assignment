//Ananda Baskoro Putra
//2311102187

#include <iostream>
#include <cctype> // Untuk fungsi tolower

using namespace std;

// Fungsi untuk menghitung huruf vokal dalam sebuah kalimat
int count_vowels(const string& sentence) {
    int vowel_count = 0;
    string vowels = "aeiou";

    for (char c : sentence) {
        // Mengubah huruf menjadi huruf kecil
        c = tolower(c);

        // Memeriksa apakah huruf adalah vokal
        if (vowels.find(c) != string::npos) {
            vowel_count++;
        }
    }

    return vowel_count;
}

int main() {
    string kalimat;

    // Meminta input kalimat dari pengguna
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    // Menghitung jumlah huruf vokal
    int jumlah_vokal = count_vowels(kalimat);

    // Menampilkan hasil
    cout << "Jumlah huruf vokal dalam kalimat: " << jumlah_vokal << endl;

    return 0;
}
