# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Ananda Baskoro Putra</p>
<p align="center">2311102187 / 11-E-IF</p>


## Dasar Teori

A.Pengertian Array

Array adalah suatu struktur yang terdiri dari sejumlah elemen yang memiliki tipe data yang sama. Elemen-elemen array tersusun secara sekuensial dalam memori komputer. Semua elemem array bertipe sama. Array cocok untuk organisasi kumpulan data homogen yang ukuran atau jumlah elemen maksimumnya telah diketahui dari awal. Homogen adalah bahwa setiap elemen dari sebuah array tertentu haruslah mempunyai tipe data yang sama.
Array dibagi menjadi :
  
1. Array Satu Dimensi
    
Array satu dimensi tidak lain adalah kumpulan elemen-elemen identik yang tersusun dalam satu baris, tetapi isi dari elemen tersebut boleh berbeda.  Dapat disebut juga dengan istilah vektor yang menggambarkan data dalam suatu urutan
Deklarasi : Type_Data Nama_Variabel [index] 
Misalnya : int A[5]; 

2.  Array Dua Dimensi 

Array dua dimensi yang sering digambarkan sebagai sebuah matriks merupakan perluasan dari sebuah array satu dimensi. Jika array satu dimensi hanya terdiri dari sebuah baris dengan beberapa kolom elemen maka array dua dimensi terdiri dari beberapa baris dan beberapa kolom elemen yang bertipe sama. Pendeklarasian array dua dimensi hampir sama dengan pendeklarasian array satu dimensi, kecuali bahwa array dua dimensi terdapat dua jumlah elemen array yang terdapat di dalam kurung siku dan keduanya boleh tidak sama.
Deklarasi : Type_Data Nama_Variabel [Index1] [index2]; 
Misal : int A[3][2];

 3.   Array Tiga Dimensi 
 
Array tiga dimensi digunakan untuk mengelola data dalam bentuk 3 dimensi atau tiga sisi. 
Deklarasi : Type_Data Nama_Variabel [index1] [ndex2] [index3]; 
Misal : int A [3][4][2];

4.   Array Banyak Dimensi

Sebenarnya array banyak dimensi ini tidak terlalu sering dipakai seperti halnya array satu dimensi, dua dimensi, dan tiga dimensi. Array banyak dimensi ini pada dasarnya sama dengan array sebelimnya kecuali pada jumlah dimensinya.
Deklarasi : Type_Data Nama_Variabel [index1] [ndex2] [index3] [ndex4].....;
Misal : int A [3][4][2][5];

## Guided 

### 1. Program input array tiga dimensi

    #include <iostream>
    using namespace std;
    // PROGRAM INPUT ARRAY 3 DIMENSI
    int main()
    {
    // Deklarasi array
    int arr[2][3][3];
    // Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout <<endl;
    }
    }

    Program tersebut merupakan sebuah program dalam bahasa C++ yang memungkinkan pengguna untuk menginputkan data ke dalam array tiga dimensi dan kemudian menampilkannya. Program ini terdiri dari tiga bagian utama:

#### Deskripsi Program

Program tersebut berfungsi untuk menginputkan data ke dalam array tiga dimensi dan kemudian menampilkannya. Program ini terdiri dari tiga bagian utama:

1.Input Data:

Program meminta kita untuk memasukkan nilai-nilai ke dalam array tiga dimensi menggunakan tiga nested loop.

2.Output Data:

Setelah semua data dimasukkan, program akan menampilkan nilai-nilai dari array tiga dimensi yang telah dimasukkan oleh kita.

3.Tampilan Array:

Program juga menampilkan array dalam bentuk yang lebih sederhana, dengan menampilkan setiap baris dari array dalam satu baris dengan menggunakan perulangan.

### 2. Program mencari nilai maksimal pada array

     #include <iostream>
     using namespace std;
     int main()
     {
     int maks, a, i = 1, lokasi;
     cout << "Masukkan panjang array: ";
     cin >> a;
     int array[a];
     cout << "Masukkan " << a << " angka\n";
     for (i = 0; i < a; i++)
     {
     cout << "Array ke-" << (i) << ": ";
     cin >> array[i];
     }
     maks = array[0];
     for (i = 0; i < a; i++)
     {
     if (array[i] > maks)
     {
     maks = array[i];
     lokasi = i;
     }
     }
     cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
     }

#### Deskrpisi Program

Program tersebut bertujuan untuk mencari nikai maksimum yang sudah diinputkan.

## Unguided

### 1.Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!

    #include <iostream> 
    using namespace std; 

    int main() { 
    int bilangan [10]; 
    
    //data array yang akan di proses
    cout << "Data Array : " ; 
    for (int i=0; i<10; i++){ 
        cin >> bilangan [i] ; 
        
    } 
    // proses pemilihan nomor genap yang akan di outputkan
    cout << "Nomor Genap : " ; 
    for (int i=0; i<10; i++){ 
        if (bilangan [i]%2 == 0){ 
            cout << bilangan [i] << " " ; 
            
        } 
    } 
    //proses pemilihan nomor ganjil yang akan di outputkan
    cout << endl; 
    cout << "Nomor Ganjil : " ; 
    for (int i=0; i<10; i++){ 
        if (bilangan [i]%2 != 0){ 
            cout << bilangan [i] << " " ; 
         } 
    } 
    return 0;
    }

#### Output 
    ![Screenshot 2024-03-19 214208](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/5fab827c-8e92-44fb-bc8a-001c051b7bf7)


### Deskrpisi Program

Program tersebut bertujuan untuk memisahkan bilangan genap dan ganjil dari sebuah array yang berisi 10 bilangan yang diinputkan.

### 2.Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

    #include <iostream> 
    using namespace std; 

    int main() { 
    int a, b, c; 
    cout << "Masukkan jumlah elemen matriks: "; 
    cin >> a; 
    cout << "Masukkan ukuran matriks (y z): "; 
    cin >> b >> c; 
    
    int arr[a][b][c]; 
    //Input elemen 
    for (int i = 0; i < a; i++) { 
        for (int j = 0; j < b; j++) { 
            for (int k = 0; k < c; k++) { 
                cout << "Input Array[" << i << "][" << j << "][" << k << "] = "; 
                cin >> arr[i][j][k]; 
            } 
        } 
        cout << endl; 
    } 
    //Output Array 
    for (int i = 0; i < a; i++) { 
        for (int j = 0; j < b; j++) { 
            for (int k = 0; k < c; k++) { 
                cout << "Data Array[" << i << "][" << j << "][" << k << "] = " << arr[i][j][k] << endl; 
            }
            
        } 
    }
    cout << endl; 
    //Tampilan array 
    for (int i = 0; i < a; i++) { 
        cout << "Matriks ke-" << i+1 << ":" << endl; 
        for (int j = 0; j < b; j++) { 
            for (int k = 0; k < c; k++) { 
                cout << arr[i][j][k] << " "; 
            } 
             cout << endl; 
        } 
        cout << endl; 
    } 
    return 0;
    }

#### Output
    ![Screenshot 2024-03-19 214634](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/d89a208b-04d1-4950-984e-5c33c3d46c0d)

### Deskrpisi Program

Program tersebut bertujuan untuk memasukkan jumlah elemen matriks dan ukuran matriks dalam format "baris kolom", kemudian meminta kita untuk memasukkan nilai-nilai elemen dari matriks tiga dimensi. Setelah itu, program akan menampilkan data matriks beserta tampilan matriks satu per satu dengan nomor urutan matriks.

### 3.Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

      #include <iostream> 
     using namespace std; 

    int main() { 
    int a; 
    cout << "Masukkan jumlah elemen array yang anda inginkan: "; 
    cin >> a; 
    
    int arr[a]; 
    for (int i = 0; i < a; i++) { 
        cout << "Input elemen array ke-" << i+1 << ": "; 
        cin >> arr[i]; 
        } 
        
        int choose; 
        if (true) { 
            cout << endl; 
            cout << "Pilih menu yang diinginkan: " << endl; 
            cout << "1. Mencari nilai maksimum" << endl; 
            cout << "2. Mencari nilai minimum" << endl; 
            cout << "3. Mencari nilai rata-rata" << endl; 
            cout << "Pilihan Anda: "; 
            cin >> choose; 
            switch(choose) { 
                case 1: { 
                    int maks = arr[0]; 
                    for (int i = 1; i < a; i++) {
                    if (arr[i] > maks) { 
                        maks = arr[i]; 
                        } 
                } 
                cout << "Nilai maksimum: " << maks << endl; 
                
                break; 
                }
                case 2: { 
                    int min = arr[0]; 
                    for (int i = 1; i < a; i++) { 
                    if (arr[i] < min) { 
                        min = arr[i]; 
                        } 
                } 
                cout << "Nilai minimum: " << min << endl; 
                
                break; 
                
                }
                 case 3: { 
                    int sum = 0; 
                    for (int i = 0; i < a; i++) { 
                        sum += arr[i]; 
                        } 
                        double ratarata = (double)sum / a; 
                        cout << "Nilai rata-rata: " << ratarata << endl; 
                        
                        break; 
                        
                    } 
                    default: { 
                    cout << "Pilihan yang anda masukkan tidak valid." << endl; 
                            
                    break; 
                            
                } 
            } 
        } 
     return 0;
    }

#### Output

    ![Screenshot 2024-03-19 214807](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/a9850317-b58f-491c-9a0e-86245591d0aa)

    ![Screenshot 2024-03-19 214923](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/aa61dfeb-2dd5-4439-a1ac-20f33fe8e410)

    ![Screenshot 2024-03-19 215745](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/4ce0cd5b-d453-4af3-a42c-01605684af11)


### Deskrpisi Program

Program tersebu bertujuan untuk memasukkan jumlah elemen dalam sebuah array, kemudian mengisi array dengan nilai-nilai yang dimasukkan oleh pengguna. Setelah itu, kita dapat memilih menu untuk mencari nilai maksimum, minimum, atau rata-rata dari elemen-elemen array yang dimasukkan. Program menggunakan switch case untuk mengimplementasikan pilihan kita, di mana setiap kasus melakukan iterasi melalui array untuk mencari nilai maksimum, minimum, atau menghitung rata-rata, dan kemudian menampilkan hasilnya sesuai dengan pilihan yang dibuat oleh kita. Jika kita memasukkan pilihan yang tidak valid, program akan memberikan pesan kesalahan.

## Kesimppulan

Array adalah struktur data yang penting dalam pemrograman karena memungkinkan kita untuk menyimpan dan mengelola sejumlah besar data dalam satu variabel. Dengan menggunakan array, kita dapat mengakses dan memanipulasi elemen-elemen data secara efisien menggunakan indeks. Materi array meliputi konsep dasar pembuatan, inisialisasi, penggunaan, dan manipulasi array dalam berbagai bahasa pemrograman. Penting untuk memahami bagaimana array bekerja dan bagaimana cara efektif menggunakan array dalam pemrograman, karena hal ini sangat berguna dalam menangani data dalam berbagai aplikasi, mulai dari pengolahan sederhana hingga pengembangan aplikasi yang kompleks. Dengan pemahaman yang baik tentang array, kita dapat mengembangkan solusi pemrograman yang lebih efisien dan efektif.

## Referensi

aldi-2020-04-04T11_57_12.242Z








