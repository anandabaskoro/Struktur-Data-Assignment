# <h1 align="center">Laporan Praktikum Modul 8 - Searching</h1>
<p align="center">Ananda Baskoro Putra</p>
<p align="center">2311102187 / 11-E-IF</p>

## Dasar teori

Searching atau pencarian data adalah salah satu operasi fundamental dalam pemrograman yang melibatkan pencarian elemen atau nilai tertentu di dalam struktur data seperti array, vektor, atau daftar tertaut (linked list).

Sequential search atau pencarian linear adalah algoritma pencarian paling sederhana. Prinsip kerjanya adalah memeriksa setiap elemen dalam struktur data (seperti array atau linked list) satu per satu secara berurutan hingga elemen yang dicari ditemukan atau seluruh elemen sudah diperiksa.

Binary search hanya dapat diterapkan pada struktur data yang sudah terurut (sorted), seperti array atau linked list yang terurut. Prinsip kerjanya adalah membagi struktur data menjadi dua bagian dan mencari elemen yang dicari di dalam salah satu bagian tersebut. Proses ini diulangi secara rekursif hingga elemen ditemukan atau seluruh elemen sudah diperiksa.[1]

 ## Guided

 1.Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.

     #include <iostream>
    using namespace std;
    
    int main()
    {
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;
    // algoritma Sequential Search
    for (i = 0; i < n; i++)
    {
    if (data[i] == cari)
    {
    ketemu = true;
    break;
    }
    }
    cout << "\t Program Sequential Search Sederhana\n " << endl;
    cout<< "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    if (ketemu){
    cout << "\n angka " << cari << " ditemukan pada indeks ke -" << i << endl;}
    else
    {
    cout << cari << " tidak dapat ditemukan pada data." << 
    endl;
    }
    return 0;
    }

## Deskripsi program

 Program ini mencari elemen tertentu dalam sebuah array. Pertama, program mendeklarasikan sebuah array data dengan 10 elemen dan variabel cari yang berisi nilai yang akan dicari, yaitu 10. Variabel ketemu diinisialisasi dengan false untuk menandai apakah nilai yang dicari ditemukan atau tidak. 
 Algoritma pencarian sekuensial berjalan dengan mengecek setiap elemen dalam array satu per satu menggunakan loop for. Jika elemen yang dicari ditemukan, variabel ketemu diubah menjadi true dan loop berhenti. Setelah pencarian selesai, program mencetak hasil pencarian, yaitu indeks di mana elemen ditemukan atau pesan bahwa elemen tidak ditemukan dalam array.

2.Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search.

    #include <iostream>
    #include <iomanip>
    using namespace std;
    
    // Deklarasi array dan variabel untuk pencarian
    int arrayData[7] = {1, 8, 2, 5, 4, 9, 7};
    int cari;
    void selection_sort(int arr[], int n) {
    int temp, min;
    for (int i = 0; i < n - 1; i++) {
    min = i;
    for (int j = i + 1; j < n; j++) {
    if (arr[j] < arr[min]) {
    min = j;
    }
    }
    // Tukar elemen
    temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
    }
    }
    void binary_search(int arr[], int n, int target) {
    int awal = 0, akhir = n - 1, tengah, b_flag = 0;
    while (b_flag == 0 && awal <= akhir) {
    tengah = (awal + akhir) / 2;
    if (arr[tengah] == target) {
    b_flag = 1;
    break;
    } else if (arr[tengah] < target) {
    awal = tengah + 1;
    } else {
    akhir = tengah - 1;
    }
    }
    if (b_flag == 1)
    cout << "\nData ditemukan pada index ke-" << tengah << 
    endl;
    else
    cout << "\nData tidak ditemukan\n";
    }
    int main() {
    cout << "\tBINARY SEARCH" << endl;
    cout << "\nData awal: ";
    // Tampilkan data awal
    for (int x = 0; x < 7; x++) {
    cout << setw(3) << arrayData[x];
    }
    cout << endl;
    cout << "\nMasukkan data yang ingin Anda cari: ";
    cin >> cari;
    // Urutkan data dengan selection sort
    selection_sort(arrayData, 7);
    cout << "\nData diurutkan: ";
    // Tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++) {
    cout << setw(3) << arrayData[x];
    }
    cout << endl;
    // Lakukan binary search
    binary_search(arrayData, 7, cari);
    return 0;
    }

## Deskrpisi program

Program dimulai dengan mendeklarasikan array arrayData yang berisi 7 elemen dan variabel cari untuk menampung nilai yang akan dicari. Pertama, array diurutkan menggunakan algoritma Selection Sort. Setelah array diurutkan, program meminta pengguna untuk memasukkan nilai yang akan dicari. Selanjutnya, pencarian dilakukan menggunakan algoritma Binary Search pada array yang sudah diurutkan. 
Jika nilai ditemukan, program mencetak indeks di mana nilai tersebut ditemukan; jika tidak, program mencetak pesan bahwa nilai tidak ditemukan. Program juga menampilkan array sebelum dan sesudah pengurutan untuk memudahkan pengguna dalam memahami proses yang terjadi.

 ## Unguided

 1.Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

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

## Screenshoot output

![Screenshot 2024-05-20 204428](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/562e4f50-f442-46e7-b359-eda1c7fb1752)

## Deskripsi program

Program imi mendefinisikan fungsi binary_search yang mencari sebuah karakter dalam vektor yang sudah diurutkan dan mengembalikan indeks karakter tersebut jika ditemukan, atau -1 jika tidak ditemukan. Fungsi search_letter_in_sentence digunakan untuk memproses kalimat yang diberikan pengguna, menghapus spasi, dan memasukkan huruf-huruf ke dalam sebuah vektor. 
Setelah itFungsi ini kemudian menggunakan binary_search untuk mencari huruf yang diinginkan dalam vektor yang sudah diurutkan. Jika huruf ditemukan, program mengembalikan pesan yang menunjukkan indeks huruf tersebut dalam daftar terurut. Jika tidak ditemukan, program mengembalikan pesan bahwa huruf tersebut tidak ditemukan dalam kalimat. Program utama meminta pengguna untuk memasukkan sebuah kalimat dan huruf yang ingin dicari, lalu memanggil search_letter_in_sentence dan mencetak hasil pencariannya.

2.Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

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

## Screenshoot output

![Screenshot 2024-05-20 204730](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/2e473c28-d340-4f6c-9110-77fcd29782f9)

## Deskripsi program

Program ini menggunakan fungsi count_vowels yang menerima sebuah string sebagai parameter dan menghitung jumlah huruf vokal (a, e, i, o, u) di dalamnya. Di dalam fungsi ini, setiap karakter dalam kalimat diubah menjadi huruf kecil menggunakan tolower untuk memastikan pemeriksaan huruf vokal tidak peka terhadap kasus (case-insensitive). Kemudian, karakter tersebut diperiksa apakah termasuk dalam string vowels, yang berisi semua huruf vokal. 
Jika ya, penghitung vokal (vowel_count) ditambah satu. Program utama meminta pengguna untuk memasukkan sebuah kalimat, lalu memanggil fungsi count_vowels untuk menghitung jumlah huruf vokal dalam kalimat tersebut, dan akhirnya mencetak hasil perhitungannya.

3.Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

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

## Screenshoot output

![Screenshot 2024-05-20 204920](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/e8336d03-0808-40ff-b0a3-97c8e0abbe71)

## Deskripsi program

Program ini mendefinisikan fungsi count_number_4 yang menerima dua parameter: sebuah array data dan ukurannya size. Fungsi ini menghitung berapa kali angka 4 muncul dalam array dengan menggunakan loop for yang memeriksa setiap elemen array satu per satu. Jika elemen array sama dengan 4, penghitung (count) ditambah satu. Fungsi ini kemudian mengembalikan nilai penghitung tersebut.

## Kesimpulan

Searching dalam struktur data adalah proses menemukan elemen tertentu di dalam kumpulan data. Teknik-teknik pencarian yang umum digunakan termasuk Sequential Search dan Binary Search. Sequential Search bekerja dengan memeriksa setiap elemen secara berurutan sampai elemen yang dicari ditemukan atau seluruh elemen telah diperiksa, cocok untuk data yang tidak terurut.
Sementara itu, Binary Search membutuhkan data yang telah diurutkan dan bekerja dengan cara membagi ruang pencarian menjadi dua secara berulang, yang membuatnya lebih efisien dengan kompleksitas waktu O(log n). Memilih algoritma pencarian yang tepat sangat penting untuk kinerja aplikasi, terutama saat bekerja dengan data dalam jumlah besar atau yang membutuhkan pencarian cepat dan berulang.

## Referensi

[1] Riyanto, Joko, et al. "ALGORITMA DAN PEMROGRAMAN 2." (2022).




