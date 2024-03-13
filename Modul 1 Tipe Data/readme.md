# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Ananda Baskoro Putra</p>
<p align="center">2311102187 / 11-E-IF</p>


##Dasar Teori

• Tipe data primitive (sederhana) Tipe data primitive adalah tipe data yang hanya mampu menyimpan satu nilai pada setiap satu variabel. tipe data ini ini merupakan tipe data dasar yang 
sering digunakan program. Contoh tipe data primitive, yaitu :

A. Tipe Numerik, tipe numerik ini digunakan pada variable untuk menyimpan nilai dalam bentuk angka. Tipe data ini terbagi menjadi “Integer” dan “Real”.- Integer (int), merupakan tipe data 
bilangan bulat.

B. Karakter (char), merupakan tipe data yang menyimpan hanya satu (1) digit karakter, karena ukuran satu digit itu satu byte (dan 1 byte itu = 8 bit). untuk penulisan karakter menggunakan 
petik tunggal ( ‘ ) di depan dan belakang karakter yang ditulis.

C. Boolean, merupakan tipe data logika yang hanya bernilai true (benar) dan false (salah). FYI, tipe data ini memakai memori paling kecil.

## Guided 

### 1. TIPE DATA PRIMITIF

#include <iostream>
using namespace std;

int main()
{
    char op;
    float num1, num2;
    // it allows user to enter operator i,e, +, -, *, /
    cin >> op;
    // it allows user to enter the operands
    cin >> num1 >> num2;
    // switch statement begins
    switch (op)
    {
    // if user center +
    case '+':
        cout << num1 + num2;
        break;
    // if user center -
    case '-':
        cout << num1 - num2;
        break;
    // if user center *
    case '*':
        cout << num1 * num2;
        break;
    // if user center /
    case '/':
        cout << num1 / num2;
        break;
    // if the operator is other than +,-,* or /,
    // error message will be display
    default:
        cout << "Error! operator is not correct";
    } // switch statement ends
return 0;
}

Program tersebut merupakan sebuah kalkulator sederhana yang menerima input dari pengguna berupa operator matematika (+, -, *, /) dan dua operand dalam bentuk bilangan floating point. Setelah menerima input, program menggunakan pernyataan switch-case untuk melakukan operasi yang sesuai berdasarkan operator yang dimasukkan pengguna. Setelah itu, hasil operasi matematika tersebut akan ditampilkan ke layar

### 2. TIPE DATA ABSTRAK

#include <stdio.h>

// struct
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
}

int main()
{
    // menggunakan struct
    struct Mahasiswa mhs1, mhs2;
    // mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;

    // mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Name : %s\n", mhs1.name);
    printf("Address : %s\n", mhs1.address);
    printf("Age : %d\n", mhs1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Name : %s\n", mhs2.name);
    printf("Address : %s\n", mhs2.address);
    printf("Age : %d\n", mhs2.age);
return 0;
}

Program tersebut merupakan contoh penggunaan struct dalam bahasa pemrograman C. Struct digunakan untuk membuat tipe data baru yang menggabungkan beberapa tipe data lainnya. Dalam contoh ini, struct Mahasiswa digunakan untuk merepresentasikan data mahasiswa, yang terdiri dari nama (string), alamat (string), dan umur (integer).

### 3. TIPE DATA KOLEKSI

#include <iostream>

using namespace std;

int main()
{
    // deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    // menncetak array
    cout << "Isi array pertama : " << nilai[0] << endl;
    cout << "Isi array kedua :  " << nilai[1] << endl;
    cout << "Isi array ketiga : " << nilai[2] << endl;
    cout << "Isi array keempat : " << nilai[3] << endl;
    cout << "Isi array kelima : " << nilai[4] << endl;
return 0;
}

Program tersebut adalah contoh penggunaan array dalam bahasa pemrograman C++. Array digunakan untuk menyimpan sekumpulan nilai dengan tipe data yang sama dalam satu variabel. Dalam contoh ini, sebuah array dengan nama nilai yang terdiri dari lima elemen bertipe integer dideklarasikan dan diinisialisasi dengan beberapa nilai.

## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

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

'''
#### Output:

![Screenshot 2024-03-13 213311](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/40ece5c7-2b8d-4a21-9b9e-c190ef221d82)

Program tersebut adalah contoh sederhana dari sebuah program C++ yang menggunakan dua fungsi untuk melakukan operasi matematika dasar, yaitu penjumlahan dan perkalian, pada dua bilangan bulat yang dimasukkan oleh pengguna

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya.

#include <iostream>
#include <string>

using namespace std;

// Struct untuk merepresentasikan data mahasiswa
struct Mahasiswa
{
    string nama;
    int nim;
    string jeniskelamin;
};

// kelas untuk merepresentasikan data mahasiswa
class Mahasiswakelas
{
public: // tambahkan hak akses public
    string nama;
    int nim;
    string jeniskelamin;
};

class Mahasiswakelas1
{
public: // tambahkan hak akses public
    string nama;
    int nim;
    string jeniskelamin;
};

int main()
{

    Mahasiswa mhs;
    Mahasiswakelas mhs1; // ganti mhs2 menjadi mhs1

    mhs.nama = "anandabaskkoro";
    mhs.nim = 87;   
    mhs.jeniskelamin = "laki-laki";

    cout <<"===== informasi mahasiswa ====="<< endl;
    cout << "Nama : " << mhs.nama << endl;
    cout << "NIM : " << mhs.nim << endl;
    cout << "Jenis Kelamin : " << mhs.jeniskelamin << endl;

    mhs1.nama = "diana"; // ganti mhs2 menjadi mhs1
    mhs1.nim = 23;
    mhs1.jeniskelamin = "perempuan";

    cout <<"===== informasi mahasiswa ====="<< endl;
    cout << "Nama : " << mhs1.nama << endl; // ganti mhs.nama menjadi mhs1.nama
    cout << "NIM : " << mhs1.nim << endl; // ganti mhs.nim menjadi mhs1.nim
    cout << "Jenis Kelamin : " << mhs1.jeniskelamin << endl; // ganti mhs.jeniskelamin menjadi mhs1.jeniskelamin
    
    return 0;
}

#### Output:

![Screenshot 2024-03-13 215825](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/d6fd9ae2-1825-48b0-b930-4d9aafbc7454)

Program tersebut menunjukkan penggunaan struct dan class dalam C++ untuk merepresentasikan data mahasiswa dengan beberapa atribut. Perbedaan antara struct dan class dalam hal penggunaan adalah bahwa anggota struct defaultnya public, sedangkan anggota class defaultnya private. Ini memungkinkan untuk mengorganisir dan mengelola data dalam sebuah program dengan lebih terstruktur dan terorganisir.

3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.
## Struct
```C++

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

```
#### Output:

![Screenshot 2024-03-13 220949](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/31d7debb-4b5a-416b-b45d-b3b7a17bf02c)

Program tersebut memberikan contoh sederhana dari bagaimana std::map digunakan untuk mengelola data dalam bentuk pasangan kunci-nilai, dan bagaimana data tersebut dapat diakses dan digunakan untuk memenuhi kebutuhan aplikasi.

## Kesimpulam

Kesimpulannya, pemahaman tentang tipe data primitif sangat penting dalam pengembangan perangkat lunak karena memungkinkan pengelolaan data dengan cara yang efisien dan terstruktur. Setiap tipe data memiliki kegunaan dan karakteristiknya sendiri, dan pemilihan yang tepat akan membantu dalam merancang solusi yang baik dan efisien. Selain itu, pemahaman tentang struktur data primitif juga merupakan dasar dalam memahami konsep yang lebih kompleks dalam pemrograman.

## Referensi

A. S. Putra, “2018 Artikel Struktur Data, Audit Dan Jaringan Komputer,” 2018.

Yoga pratama,Jenis jenis tipe data,Bandar Lampung:Y Pratama - scholar.archive.org,2019
