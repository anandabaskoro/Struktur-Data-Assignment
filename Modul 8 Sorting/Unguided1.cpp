//Ananda Baskoro Putra
//2311102187

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Fungsi Binary Search
int binary_search(const vector<char>& arr, char target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Fungsi untuk mencari huruf dalam kalimat
string search_letter_in_sentence(const string& sentence, char target) {
    vector<char> characters;

    // Menghapus spasi dan memasukkan huruf ke dalam vector
    for (char c : sentence) {
        if (c != ' ') {
            characters.push_back(c);
        }
    }

    // Mengurutkan daftar huruf
    sort(characters.begin(), characters.end());

    // Mencari huruf menggunakan Binary Search
    int index = binary_search(characters, target);

    if (index != -1) {
        return "Huruf '" + string(1, target) + "' ditemukan pada indeks " + to_string(index) + " dalam daftar terurut.";
    } else {
        return "Huruf '" + string(1, target) + "' tidak ditemukan dalam kalimat.";
    }
}

int main() {
    string kalimat;
    char huruf_yang_dicari;

    // Input kalimat dari pengguna
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    // Input huruf yang ingin dicari dari pengguna
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> huruf_yang_dicari;

    // Memanggil fungsi pencarian dan mencetak hasil
    string hasil = search_letter_in_sentence(kalimat, huruf_yang_dicari);
    cout << hasil << endl;

    return 0;
}
