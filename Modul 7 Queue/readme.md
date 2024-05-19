# <h1 align="center">Laporan Praktikum Modul 6 - Stack</h1>
<p align="center">Ananda Baskoro Putra</p>
<p align="center">2311102187 / 11-E-IF</p>

## Dasar teori

Antrean atau queue (baca: qyu) adalah salah satu konsep struktur data yang memiliki sistem kerja, di mana yang pertama masuk maka akan menjadi yang pertama keluar (FIFO = first in first out), seperti halnya antrean yang terjadi dalam dunia nyata. Namun, hal ini tidak berlaku pada antrean
berprioritas. Sebab, pada antrean berprioritas, urutan keluar dari sebuah antrean ditentukan berdasarkan prioritas masingmasing elemen dalam antrean untuk diproses terlebih dahulu.Pada sebuah antrean, elemen hanya dapat ditambahkan melalui sisi belakang queue dan hanya dapat diambil dari sisibagian depan queue. Oleh karena itu, ada dua buah elemen pada sebuah queue, yaitu belakang (last atau rear) sebagai penunjuk paling belakang dan depan (first atau front) sebagai Queue (Antrean) penunjuk elemen bagian depan. Seperti halnya stack dan list, queue juga merupakan pemikiran struktur data yang dapat direpresentasikan secara statis menggunakan array atau secara dinamis menggunakan pointer. Begitu pun dengan elemen sebuah queue dapat diisi dengan data sesuai kebutuhan.[1]

Ada 2 operasi dasar pada queue yaitu :

- tambah 
- ambil

  ## Guided

          #include <iostream>
        using namespace std;
        
        const int maksimalQueue = 5; // Maksimal antrian
        int front = 0;               // Penanda antrian
        int back = 0;                // Penanda
        string queueTeller[5];       // Fungsi pengecekan
        
        bool isFull()
        { // Pengecekan antrian penuh atau tidak
            if (back == maksimalQueue)
            {
                return true; // =1
            }
            else
            {
                return false;
            }
        }
        bool isEmpty()
        { // Antriannya kosong atau tidak
            if (back == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        void enqueueAntrian(string data)
        { // Fungsi menambahkan antrian
            if (isFull())
            {
                cout << "Antrian penuh" << endl;
            }
            else
            {
                if (isEmpty())
                { // Kondisi ketika queue kosong
                    queueTeller[0] = data;
                    front++;
                    back++;
                }
                else
                { // Antrianya ada isi
                    queueTeller[back] = data;
                    back++;
                }
            }
        }
        void dequeueAntrian()
        { // Fungsi mengurangi antrian
            if (isEmpty())
            {
                cout << "Antrian kosong" << endl;
            }
            else
            {
                for (int i = 0; i < back; i++)
                {
                    queueTeller[i] = queueTeller[i + 1];
                }
                back--;
            }
        }
        int countQueue()
        { // Fungsi menghitung banyak antrian
            return back;
        }
        void clearQueue()
        { // Fungsi menghapus semua antrian
            if (isEmpty())
            {
                cout << "Antrian kosong" << endl;
            }
            else
            {
                for (int i = 0; i < back; i++)
                {
                    queueTeller[i] = "";
                }
                back = 0;
                front = 0;
            }
        }
        void viewQueue()
        { // Fungsi melihat antrian
            cout << "Data antrian teller:" << endl;
            for (int i = 0; i < maksimalQueue; i++)
            {
                if (queueTeller[i] != "")
                {
                    cout << i + 1 << ". " << queueTeller[i] << endl;
                }
                else
                {
                    cout << i + 1 << ". (kosong)" << endl;
                }
            }
        }
        
        int main()
        {
            enqueueAntrian("Andi");
            enqueueAntrian("Maya");
            viewQueue();
            cout << "Jumlah antrian = " << countQueue() << endl;
            dequeueAntrian();
            viewQueue();
            cout << "Jumlah antrian = " << countQueue() << endl;
            clearQueue();
            viewQueue();
            cout << "Jumlah antrian = " << countQueue() << endl;
            return 0;
        }

  ## Deskripsi program

  Program tersebut adalah implementasi antrian (queue) statis menggunakan array. Antrian memiliki kapasitas maksimal lima elemen yang ditandai dengan variabel maksimal Queue. Fungsi enqueueAntrian menambahkan elemen ke antrian, sementara dequeue Antrian menghapus elemen dari antrian dengan menggeser elemen-elemen
  lainnya ke kiri. Fungsi isFull dan isEmpty digunakan untuk memeriksa apakah antrian penuh atau kosong. Fungsi countQueue mengembalikan jumlah elemen dalam antrian, clearQueue menghapus semua elemen dalam antrian, dan viewQueue menampilkan isi antrian. Dalam fungsi main, program menambahkan, menghapus, dan menampilkan elemen-elemen dalam antrian, serta mengosongkan antrian untuk mendemonstrasikan operasi-operasi dasar tersebut.

## Unguided

### 1.Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list

      //Ananda Baskoro Putra
      //2311102187
      
      #include <iostream>
      using namespace std;
      
      struct Node
      {
          string data; // Data yang disimpan dalam node
          Node *next;  // Pointer ke node berikutnya dalam antrian
      };
      
      // Pointer global untuk mengelola bagian depan dan belakang antrian
      Node *front = NULL;
      Node *back = NULL;
      
      // Fungsi untuk memeriksa apakah antrian kosong
      bool isEmpty()
      {
          return front == NULL; // Antrian kosong jika front adalah NULL
      }
      
      // Fungsi untuk menambahkan elemen ke belakang antrian
      void enqueueAntrian(string data)
      {
          Node *newNode = new Node; // Membuat node baru
          newNode->data = data;     // Mengatur data untuk node baru
          newNode->next = NULL;     // Node baru akan menjadi node terakhir, jadi next adalah NULL
      
          if (isEmpty()) // Jika antrian kosong
          {
              front = back = newNode; // front dan back mengarah ke node baru
          }
          else // Jika antrian tidak kosong
          {
              back->next = newNode; // Menautkan node baru setelah node belakang saat ini
              back = newNode;       // Memperbarui pointer back ke node baru
          }
      }
      
      // Fungsi untuk menghapus elemen dari depan antrian
      void dequeueAntrian()
      {
          if (isEmpty()) // Jika antrian kosong
          {
              cout << "Antrian kosong" << endl;
          }
          else // Jika antrian tidak kosong
          {
              Node *temp = front;  // Simpan sementara node depan
              front = front->next; // Pindahkan pointer front ke node berikutnya
              delete temp;         // Hapus node depan lama
      
              if (front == NULL) // Jika antrian sekarang kosong
              {
                  back = NULL; // Perbarui pointer back ke NULL
              }
          }
      }
      
      // Fungsi untuk menghitung jumlah elemen dalam antrian
      int countQueue()
      {
          int count = 0;       // Inisialisasi hitungan ke nol
          Node *curr = front;  // Mulai dari depan antrian
          while (curr != NULL) // Traversal hingga akhir antrian
          {
              count++;           // Menambah hitungan untuk setiap node
              curr = curr->next; // Pindah ke node berikutnya
          }
          return count; // Kembalikan jumlah node
      }
      
      // Fungsi untuk mengosongkan antrian
      void clearQueue()
      {
          while (!isEmpty()) // Selama antrian tidak kosong
          {
              dequeueAntrian(); // Hapus elemen dari depan antrian
          }
      }
      
      // Fungsi untuk menampilkan elemen-elemen dalam antrian
      void viewQueue()
      {
          cout << "====== Data antrian teller ======" << endl;
          if (isEmpty()) // Jika antrian kosong
          {
              cout << "Data kosong !" << endl;
              return;
          }
      
          int posisi = 1;      // Inisialisasi posisi
          Node *curr = front;  // Mulai dari depan antrian
          while (curr != NULL) // Traversal hingga akhir antrian
          {
              cout << posisi << ". " << curr->data << endl; // Cetak posisi dan data node
              curr = curr->next;                            // Pindah ke node berikutnya
              posisi++;                                     // Tambah posisi
          }
      }
      
      int main()
      {
          enqueueAntrian("Ananda");
          enqueueAntrian("Andi");
          viewQueue();                                             // Menampilkan antrian
          cout << "\nJumlah antrian = " << countQueue() << "\n\n"; // Menampilkan jumlah antrian
          dequeueAntrian();                                        // Menghapus elemen dari depan antrian
          viewQueue();                                             // Menampilkan antrian
          cout << "\nJumlah antrian = " << countQueue() << "\n\n"; // Menampilkan jumlah antrian
          clearQueue();                                            // Mengosongkan antrian
          viewQueue();                                             // Menampilkan antrian
          cout << "\nJumlah antrian = " << countQueue() << "\n\n"; // Menampilkan jumlah antrian
      
          return 0;
      }

## Screenshoot output

![Screenshot 2024-05-19 185133](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/e29f66e1-da75-478f-af0a-5756374376fc)

## Deskripsi program

Program di atas merupakan antrian (queue) dinamis di mana setiap elemen antrian diwakili oleh node yang memiliki data dan pointer ke node berikutnya. Fungsi isEmpty memeriksa apakah antrian kosong, sedangkan enqueueAntrian menambahkan elemen baru ke belakang antrian, 
dan dequeueAntrian menghapus elemen dari depan antrian. Fungsi countQueue menghitung jumlah elemen dalam antrian, clearQueue mengosongkan antrian dengan menghapus semua elemen, dan viewQueue menampilkan semua elemen dalam antrian. Program utama menambahkan elemen ke antrian, menghapus elemen, menampilkan isi antrian, dan mengosongkan antrian untuk mendemonstrasikan fungsionalitas-fungsionalitas tersebut.

### 2.Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

      //Ananda Baskoro Putra
      //2311102187
      
      #include <iostream>
      #include <iomanip>
      using namespace std;
      
      struct Mahasiswa
      {
          string nama;   // Nama mahasiswa
          long long nim; // NIM mahasiswa
      };
      
      struct Node
      {
          Mahasiswa data; // Data mahasiswa disimpan dalam node
          Node *next;     // Pointer ke node berikutnya dalam antrian
      };
      
      // Pointer global untuk mengelola bagian depan dan belakang antrian
      Node *front = NULL;
      Node *back = NULL;
      
      // Fungsi untuk memeriksa apakah antrian kosong
      bool isEmpty()
      {
          return front == NULL; // Antrian kosong jika front adalah NULL
      }
      
      // Fungsi untuk menambahkan elemen ke belakang antrian
      void enqueueAntrian(string nama, long long nim)
      {
          Node *newNode = new Node;  // Membuat node baru
          newNode->data.nama = nama; // Mengatur nama mahasiswa untuk node baru
          newNode->data.nim = nim;   // Mengatur NIM mahasiswa untuk node baru
          newNode->next = NULL;      // Node baru akan menjadi node terakhir, jadi next adalah NULL
      
          if (isEmpty()) // Jika antrian kosong
          {
              front = back = newNode; // front dan back mengarah ke node baru
          }
          else // Jika antrian tidak kosong
          {
              back->next = newNode; // Menautkan node baru setelah node belakang saat ini
              back = newNode;       // Memperbarui pointer back ke node baru
          }
      }
      
      // Fungsi untuk menghapus elemen dari depan antrian
      void dequeueAntrian()
      {
          if (isEmpty()) // Jika antrian kosong
          {
              cout << "Antrian kosong" << endl;
          }
          else // Jika antrian tidak kosong
          {
              Node *temp = front;  // Simpan sementara node depan
              front = front->next; // Pindahkan pointer front ke node berikutnya
              delete temp;         // Hapus node depan lama
      
              if (front == NULL) // Jika antrian sekarang kosong
              {
                  back = NULL; // Perbarui pointer back ke NULL
              }
          }
      }
      
      // Fungsi untuk menghitung jumlah elemen dalam antrian
      int countQueue()
      {
          int count = 0;       // Inisialisasi hitungan ke nol
          Node *curr = front;  // Mulai dari depan antrian
          while (curr != NULL) // Traversal hingga akhir antrian
          {
              count++;           // Menambah hitungan untuk setiap node
              curr = curr->next; // Pindah ke node berikutnya
          }
          return count; // Kembalikan jumlah node
      }
      
      // Fungsi untuk mengosongkan antrian
      void clearQueue()
      {
          while (!isEmpty()) // Selama antrian tidak kosong
          {
              dequeueAntrian(); // Hapus elemen dari depan antrian
          }
      }
      
      // Fungsi untuk menampilkan elemen-elemen dalam antrian
      void viewQueue()
      {
          cout << "====== Data antrian mahasiswa ======" << endl;
          if (isEmpty()) // Jika antrian kosong
          {
              cout << "Data kosong !" << endl;
              return;
          }
      
          cout << "-----------------------------------------" << endl;
          cout << "|       Nama         |       NIM        |" << endl;
          cout << "-----------------------------------------" << endl;
      
          Node *curr = front;  // Mulai dari depan antrian
          while (curr != NULL) // Traversal hingga akhir antrian
          {
              cout << "| " << setw(18) << left << curr->data.nama << " | " << setw(17) << left << curr->data.nim << "|" << endl; // Cetak nama dan NIM node
              curr = curr->next;                                                                                                 // Pindah ke node berikutnya
          }
          cout << "-----------------------------------------" << endl;
      }
      
      int main()
      {
          enqueueAntrian("Baskoro", 111111111);
          enqueueAntrian("Ananda", 2311102187);
          viewQueue(); // Menampilkan antrian
          cout << "\nJumlah antrian = " << countQueue() << "\n\n";
          dequeueAntrian(); // Menghapus elemen dari depan antrian
          viewQueue();      // Menampilkan antrian
          cout << "\nJumlah antrian = " << countQueue() << "\n\n";
          clearQueue(); // Mengosongkan antrian
          viewQueue();  // Menampilkan antrian
          cout << "\nJumlah antrian = " << countQueue() << "\n\n";
      
          return 0;
      }

### Screenshoot output

![Screenshot 2024-05-19 185841](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/49501421-42e7-43d3-bf90-ef178eea5d2e)

### Deskripsi program 

Program diatas adalah program untuk untuk mengelola data mahasiswa. Setiap mahasiswa diwakili oleh struktur Mahasiswa yang menyimpan nama dan NIM. Fungsi enqueueAntrian menambahkan mahasiswa ke belakang antrian, sedangkan dequeueAntrian menghapus mahasiswa dari depan antrian. Fungsi isEmpty memeriksa apakah antrian kosong,
countQueue menghitung jumlah mahasiswa dalam antrian, dan clearQueue mengosongkan antrian. Fungsi viewQueue menampilkan daftar mahasiswa dalam antrian dalam format tabel. Program utama mendemonstrasikan fungsi-fungsi ini dengan menambahkan, menghapus, dan menampilkan data mahasiswa dalam antrian serta menghitung jumlah elemen dalam antrian.


## Kesimpulam

Queue adalah struktur data linear yang mengikuti prinsip First In First Out (FIFO), di mana elemen yang pertama kali dimasukkan akan menjadi elemen pertama yang dihapus. Queue dapat diimplementasikan menggunakan array atau linked list, dengan operasi dasar seperti enqueue (menambahkan elemen ke belakang antrian), dequeue (menghapus elemen dari depan antrian),
isEmpty (memeriksa apakah antrian kosong), dan count (menghitung jumlah elemen dalam antrian). Struktur data ini sangat berguna dalam berbagai aplikasi seperti manajemen tugas dalam sistem operasi, penjadwalan proses, antrian di printer, dan skenario lain di mana pemrosesan elemen dalam urutan kedatangan sangat penting. Implementasi queue yang efisien memastikan antrian dapat diakses dan dimodifikasi dengan cepat, mendukung performa optimal dalam berbagai konteks komputasi.


## Referensi

[1] Mulyana, A., et al., Cara Mudah Mempelajari Algoritma dan Struktur Data. Edisi Pertama. Yogyakarta : DIVA Press, 2021
