//Ananda Baskoro Putra
//2311102187

#include <iostream>

using namespace std;

// Fungsi untuk menghitung jumlah angka 4 menggunakan Sequential Search
int count_number_4(int data[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (data[i] == 4) {
            count++;
        }
    }
    return count;
}

int main() {
    // Inisialisasi data array
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int size = sizeof(data) / sizeof(data[0]);

    // Menghitung jumlah angka 4
    int jumlah_angka_4 = count_number_4(data, size);

    // Menampilkan hasil
    cout << "Jumlah angka 4 dalam array: " << jumlah_angka_4 << endl;

    return 0;
}
