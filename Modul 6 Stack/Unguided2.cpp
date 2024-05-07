//Ananda Baskoro Putra
//2311102187

#include <iostream>
#include <cstring>

using namespace std;

struct Tumpukan {
    char nama[50];
    int top;
} T;

void push(char x) {
    if (T.top == 49) { // Memeriksa apakah tumpukan sudah penuh
        cout << "Tumpukan sudah penuh";
    } else {
        T.top = T.top + 1;
        T.nama[T.top] = x; // Memasukkan karakter ke dalam tumpukan
    }
}

char pop() {
    char hasil;
    if (T.top == 0) { // Memeriksa apakah tumpukan sudah kosong
        cout << "Tumpukan sudah kosong";
        hasil = ' ';
    } else {
        hasil = T.nama[T.top]; // Mengambil karakter dari tumpukan
        T.top = T.top - 1; // Mengurangi indeks top untuk menunjuk ke elemen berikutnya
    }
    return hasil; // Mengembalikan karakter yang diambil dari tumpukan
}

int main() {
    int len;
    char kalimat[25];
    T.top = 0;

    cout << "Masukkan Kalimat: ";
    cin.getline(kalimat, 25); // Menerima masukan kalimat dari pengguna

    len = strlen(kalimat); // Menghitung panjang kalimat

    cout << "Kalimat Asli: " << kalimat; // Menampilkan kalimat asli yang dimasukkan pengguna

    for (int i = 0; i < len; i++) {
        push(kalimat[i]); // Memasukkan setiap karakter kalimat ke dalam tumpukan
    }

    cout << "\nKalimat Setelah dibalik: ";
    for (int i = 0; i < len; i++) {
        cout << pop(); // Mengambil dan menampilkan karakter dari tumpukan untuk membalikkan kalimat
    }
    cout << endl;

    return 0;
}
