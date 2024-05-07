# <h1 align="center">Laporan Praktikum Modul 6 - Stack</h1>
<p align="center">Ananda Baskoro Putra</p>
<p align="center">2311102187 / 11-E-IF</p>

## Dasar teori

Stack atau Tumpukan adalah suatu struktur data yang terbentuk dari barisan hingga yang terurut dari satuan data. Pada Stack, penambahan dan penghapusan elemennya hanya dapat dilakukan pada satu posisi, yaitu posisi akhir stack. Posisi
ini disebut Puncak atau Top dari stack.

Ada beberapa operasi dasar yang bisa kita untuk lakukan terhadap struktur data stack. Operasi-operasi tersebut meliputi Push Menyisipkan elemen ke bagian atas stack,Pop Menghapus elemen atas dari stack,IsEmpty Memeriksa apakah stack kosong,
IsFull Memerika apakah stack sudah penuh,Peek Mendapatkan nilai elemen teratas tanpa menghapusnya.

## Guided

    #include <iostream>
    using namespace std;
    
    string arrayBuku[5];
    int maksimal = 5, top = 0;
    
    bool isFull()
    {
        return (top == maksimal);
    }
    
    bool isEmpty()
    {
        return (top == 0);
    }
    
    void pushArrayBuku(string data)
    {
        if (isFull())
        {
            cout << "Data telah penuh" << endl;
        }
        else
        {
            arrayBuku[top] = data;
            top++;
        }
    }
    
    void popArrayBuku()
    {
        if (isEmpty())
        {
            cout << "Tidak ada data yang dihapus" << endl;
        }
        else
        {
            arrayBuku[top - 1] = "";
            top--;
        }
    }
    
    void peekArrayBuku(int posisi)
    {
        if (isEmpty())
        {
            cout << "Tidak ada data yang bisa dilihat" << endl;
        }
        else
        {
            int index = top;
            for (int i = 0; i < posisi; i++)
            {
                index--;
            }
            cout << "posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
        }
    }
    
    int countStack()
    {
        return top;
    }
    
    void changeArrayBuku(int posisi, string data)
    {
        if (posisi > top)
        {
            cout << "Posisi melebihi data yang ada" << endl;
        }
        else
        {
            int index = top;
            for (int i = 1; i <= posisi; i++)
            {
                index--;
            }
            arrayBuku[index] = data;
        }
    }
    
    void destroyArrayBuku()
    {
        for (int i = top; i >= 0; i--)
        {
            arrayBuku[i] = "";
        }
        top = 0;
    }
    
    void cetakArrayBuku()
    {
        if (isEmpty())
        {
            cout << "Tidak ada data yang dicetak" << endl;
        }
        else
        {
            for (int i = top - 1; i >= 0; i--)
            {
                cout << arrayBuku[i] << endl;
            }
        }
    }
    
    int main()
    {
        pushArrayBuku("Kalkulus");
        pushArrayBuku("Struktur Data");
        pushArrayBuku("Matematika Diskrit");
        pushArrayBuku("Dasar Multimedia");
        pushArrayBuku("Inggris");
    
        cetakArrayBuku();
        cout << "\n";
    
        cout << "Apakah data stack penuh? " << isFull() << endl;
        cout << "Apakah data stack kosong? " << isEmpty() << endl;
    
        peekArrayBuku(2);
        popArrayBuku();
    
        cout << "Banyaknya data = " << countStack() << endl;
    
        changeArrayBuku(2, "Bahasa Jerman");
        cetakArrayBuku();
    
        cout << "\n";
    
        destroyArrayBuku();
        cout << "Jumlah data setelah dihapus : " << top << endl;
        cetakArrayBuku();
    
        return 0;
    }

## Deskripsi program

Program tersebut merupakan implementasi dari struktur data tumpukan (stack) menggunakan array. Program ini memungkinkan pengguna untuk menambahkan buku ke dalam tumpukan, menghapus buku dari tumpukan, melihat buku pada posisi tertentu dalam tumpukan, menghitung jumlah buku dalam 
tumpukan, mengubah judul buku pada posisi tertentu dalam tumpukan, mencetak seluruh isi tumpukan, serta menghapus semua buku dari tumpukan. Program tersebut menampilkan interaksi dengan tumpukan buku seperti menambah, menghapus, dan memodifikasi data dalam tumpukan, serta memberikan 
informasi tentang status tumpukan seperti apakah tumpukan sudah penuh atau kosong, serta jumlah data dalam tumpukan setelah operasi tertentu.

## Unguided

### 1. Soal mengenai materi 
Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

    //Ananda Baskoro Putra
    //2311102187
    
    #include <iostream>
    #include <stack>
    #include <string>
    #include <locale>
    
    using namespace std;
    
    // Fungsi untuk menghapus karakter non-alphanumeric dari sebuah string
    string removeNonAlphanumeric(string str) {
        string result = "";
        for (char c : str) {
            if (isalnum(c)) { // isalnum() memeriksa apakah karakter adalah alfanumerik
                result += tolower(c); // Mengubah karakter menjadi huruf kecil
            }
        }
        return result;
    }
    
    // Fungsi untuk menentukan apakah sebuah string adalah palindrom
    bool isPalindrome(string str) {
        stack<char> charStack;
        int length = str.length();
    
        // Menambahkan setengah karakter pertama ke stack
        for (int i = 0; i < length / 2; i++) {
            charStack.push(str[i]);
        }
    
        // Memeriksa setengah karakter kedua dengan stack
        for (int i = (length + 1) / 2; i < length; i++) {
            if (charStack.top() != str[i]) {
                return false;
            }
            charStack.pop();
        }
    
        return true;
    }
    
    int main() {
        string input;
        cout << "Masukkan kalimat: ";
        getline(cin, input);
    
        // Menghapus karakter non-alphanumeric dan mengubah menjadi huruf kecil
        string cleanedInput = removeNonAlphanumeric(input);
    
        if (isPalindrome(cleanedInput)) {
            cout << "Kalimat tersebut adalah palindrom." << endl;
        } else {
            cout << "Kalimat tersebut bukan palindrom." << endl;
        }
    
        return 0;
    }

## Output

![Screenshot 2024-05-07 215652](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/9236274c-35f0-4182-9fa3-2cc5b441eb26)
![Screenshot 2024-05-07 215733](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/17038166-c27a-4690-87c8-b0a84a1a6c19)


## Deskripsi program

Program tersebut merupakan program untuk menentukan apakah sebuah kalimat yang dimasukkan pengguna merupakan palindrom atau tidak. Palindrom adalah sebuah kata, frasa, angka, atau urutan lainnya yang dapat dibaca sama baik dari depan maupun
dari belakang. Program ini menggunakan fungsi-fungsi standar dari C++ untuk menghapus karakter non-alphanumeric dari kalimat yang dimasukkan, mengubah semua karakter menjadi huruf kecil, dan kemudian memeriksa apakah kalimat tersebut merupakan palindrom dengan memanfaatkan struktur
data stack untuk membandingkan setengah bagian pertama kalimat dengan setengah bagian kedua yang telah dibalik. Program memberikan keluaran berupa pesan yang menunjukkan apakah kalimat tersebut adalah palindrom atau bukan.

### 2. Soal mengenai materi 

Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?

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

## Output

![Screenshot 2024-05-07 221916](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/bebabaf6-b38d-430c-87f8-503265e0e18b)

## Deskripsi program

Program tersebut adalah implementasi dari struktur data tumpukan (stack). Program ini memungkinkan pengguna untuk memasukkan sebuah kalimat, kemudian program akan membalikkan kalimat tersebut menggunakan tumpukan. Setiap karakter dari kalimat dimasukkan
ke dalam tumpukan, kemudian karakter tersebut diambil satu per satu dari tumpukan untuk membalikkan urutan karakter kalimat. Hasil akhirnya adalah kalimat yang telah dibalikkan, yang kemudian dicetak ke layar.

## Kesimpulam

Stack adalah  struktur data yang penting dan berguna dalam pengembangan perangkat lunak. Tumpukan merupakan struktur data linier yang mengikuti prinsip LIFO (Last In First Out), di mana elemen terakhir yang dimasukkan adalah yang pertama kali diambil. Keunggulan utamanya
adalah kemampuan untuk menyimpan data secara sementara dan mengaksesnya dengan cepat, serta menyediakan operasi push (menambahkan elemen), pop (menghapus elemen), dan peek (mengakses elemen teratas) yang efisien. Tumpukan banyak digunakan dalam pemecahan
masalah algoritma, pengelolaan memori, eksekusi fungsi dalam pemanggilan rekursif, dan dalam berbagai aplikasi lain yang membutuhkan penanganan data dalam urutan tertentu.

## Referensi

Mulyana, A., et al., Cara Mudah Mempelajari Algoritma dan Struktur Data. Edisi Pertama. Yogyakarta : DIVA Press, 2021

Drozdek, A. (1996). Data Structures and Algorithms in C++.











