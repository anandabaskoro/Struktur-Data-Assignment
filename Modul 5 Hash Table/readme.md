# <h1 align="center">Laporan Praktikum Modul 4 - Linked list circural</h1>
<p align="center">Ananda Baskoro Putra</p>
<p align="center">2311102187 / 11-E-IF</p>

## Dasar teori

Hash Table merupakan salah satu struktur data yang digunakan dalam penyimpanan data sementara. Tujuan penggunaan hash table adalah mempercepat pencarian kembali dari banyak data yang disimpan. 
Hash table menggunakan suatu teknik penyimpanan sehingga waktu yang dibutuhkan untuk penambahan data (insertions), penghapusan data (deletions), dan pencarian data (searching) relatif sama dibanding
struktur data atau algoritma yang lain[1].

Struktur data dan algoritma ini yang berbeda diketahui memiliki kelebihan dan kekurangannya masing-masing.Demikian pula tabel hash memiliki kelebihan dan kekurangan.
Keuntungan dari tabel hash adalah: Relatif cepat,Kecepatan penyisipan, penghapusan, dan pencarian relatif sama [1].

Tabel hash  menggunakan memori  utama berupa array dengan tambahan algoritma untuk mempercepat pengolahan data.Pada dasarnya tabel hash adalah penyimpanan data yang menggunakan nilai kunci yang berasal 
dari nilai data itu sendiri.Nilai kunci ini digunakan untuk menentukan nilai hash.Dengan kata lain fungsi hash adalah fungsi sederhana yang menghitung nilai hash  dari nilai kunci data [1].


## Guided

### 1. Program Pertama Hash Table

     #include <iostream>
    using namespace std;
    
    const int MAX_SIZE = 10;
    
    // Fungsi hash sederhana
    int hash_func(int key)
    {
        return key % MAX_SIZE;
    }
    
    // Struktur data untuk setiap node
    struct Node
    {
        int key;
        int value;
        Node *next;
        Node(int key, int value) : key(key), value(value), next(nullptr) {}
    };
    
    // Class hash table
    class HashTable
    {
    private:
        Node **table;
    
    public:
        HashTable()
        {
            table = new Node *[MAX_SIZE]();
        }
        ~HashTable()
        {
            for (int i = 0; i < MAX_SIZE; i++)
            {
                Node *current = table[i];
                while (current != nullptr)
                {
                    Node *temp = current;
                    current = current->next;
                    delete temp;
                }
            }
            delete[] table;
        }
    
        // Insertion
        void insert(int key, int value)
        {
            int index = hash_func(key);
            Node *current = table[index];
            while (current != nullptr)
            {
                if (current->key == key)
                {
                    current->value = value;
                    return;
                }
                current = current->next;
            }
            Node *node = new Node(key, value);
            node->next = table[index];
            table[index] = node;
        }
        // Searching
        int get(int key)
        {
            int index = hash_func(key);
            Node *current = table[index];
            while (current != nullptr)
            {
                if (current->key == key)
                {
                    return current->value;
                }
                current = current->next;
            }
            return -1;
        }
    
        // Deletion
        void remove(int key)
        {
            int index = hash_func(key);
            Node *current = table[index];
            Node *prev = nullptr;
            while (current != nullptr)
            {
                if (current->key == key)
                {
                    if (prev == nullptr)
                    {
                        table[index] = current->next;
                    }
                    else
                    {
                        prev->next = current->next;
                    }
                    delete current;
                    return;
                }
                prev = current;
                current = current->next;
            }
        }
    
        // Traversal
        void traverse()
        {
            for (int i = 0; i < MAX_SIZE; i++)
            {
                Node *current = table[i];
                while (current != nullptr)
                {
                    cout << current->key << ": " << current->value
                         << endl;
                    current = current->next;
                }
            }
        }
    };
    
    int main()
    {
        HashTable ht;
        // Insertion
        ht.insert(1, 10);
        ht.insert(2, 20);
        ht.insert(3, 30);
    
        // Searching
        cout << "Get key 1: " << ht.get(1) << endl;
        cout << "Get key 4: " << ht.get(4) << endl;
    
        // Deletion
        ht.remove(4);
    
        // Traversal
        ht.traverse();
    
        return 0;
    }

## Deskripsi program

Program ini menggunakan fungsi hash sederhana untuk menentukan indeks setiap kunci dalam tabel hash, dan setiap entri tabel direpresentasikan oleh struktur Node yang menyimpan pasangan kunci-nilai.
Kelas HashTable menyediakan metode untuk memasukkan, mencari, dan menghapus entri, serta untuk menelusuri seluruh isi tabel hash. Program utama menggunakan objek HashTable untuk melakukan operasi-operasi tersebut,
seperti memasukkan beberapa pasangan kunci-nilai, mencari nilai berdasarkan kunci, menghapus entri berdasarkan kunci, dan menampilkan seluruh isi tabel hash.

### 2. Program Kedua Hash Table

    #include <iostream>
    #include <string>
    #include <vector>
    
    using namespace std;
    
    const int TABLE_SIZE = 11;
    string name;
    string phone_number;
    
    class HashNode
    {
    public:
        string name;
        string phone_number;
        HashNode(string name, string phone_number)
        {
            this->name = name;
            this->phone_number = phone_number;
        }
    };
    
    class HashMap
    {
    private:
        vector<HashNode *> table[TABLE_SIZE];
    
    public:
        int hashFunc(string key)
        {
            int hash_val = 0;
            for (char c : key)
            {
                hash_val += c;
            }
            return hash_val % TABLE_SIZE;
        }
    
        void insert(string name, string phone_number)
        {
            int hash_val = hashFunc(name);
            for (auto node : table[hash_val])
            {
                if (node->name == name)
                {
                    node->phone_number = phone_number;
                    return;
                }
            }
            table[hash_val].push_back(new HashNode(name, phone_number));
        }
    
        void remove(string name)
        {
            int hash_val = hashFunc(name);
            for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++)
            {
                if ((*it)->name == name)
                {
                    table[hash_val].erase(it);
                    return;
                }
            }
        }
    
        string searchByName(string name)
        {
            int hash_val = hashFunc(name);
            for (auto node : table[hash_val])
            {
                if (node->name == name)
                {
                    return node->phone_number;
                }
            }
            return "";
        }
    
        void print()
        {
            for (int i = 0; i < TABLE_SIZE; i++)
            {
                cout << i << ": ";
                for (auto pair : table[i])
                {
                    if (pair != nullptr)
                    {
                        cout << "[" << pair->name << ", " << pair->phone_number << "]";
                    }
                }
                cout << endl;
            }
        }
    };
    
    int main()
    {
        HashMap employee_map;
    
        employee_map.insert("Mistah", "1234");
        employee_map.insert("Pastah", "5678");
        employee_map.insert("Ghana", "91011");
    
        cout << "Nomer Hp Mistah : "
             << employee_map.searchByName("Mistah") << endl;
        cout << "Phone Hp Pastah : "
             << employee_map.searchByName("Pastah") << endl;
    
        employee_map.remove("Mistah");
    
        cout << "Nomer Hp Mistah setelah dihapus : "
             << employee_map.searchByName("Mistah") << endl
             << endl;
    
        cout << "Hash Table : " << endl;
    
        employee_map.print();
    
        return 0;
    }

## Deskripsi program

Program ini adalah implementasi sederhana dari tabel hash menggunakan chaining untuk menangani tabrakan (collision). Program ini memungkinkan pengguna untuk menyimpan nama dan nomor telepon dalam tabel hash, 
di mana nama digunakan sebagai kunci. Setiap nama di-hash ke dalam indeks dalam tabel hash menggunakan fungsi hash sederhana. Jika terjadi tabrakan, data disimpan dalam bentuk daftar terhubung (linked list) di indeks yang sama. 
Program menyediakan fungsi untuk memasukkan data baru, menghapus data berdasarkan nama, mencari nomor telepon berdasarkan nama, dan mencetak isi tabel hash. Dalam program utama, beberapa entri ditambahkan ke tabel hash, kemudian 
beberapa pencarian dilakukan, satu entri dihapus, dan akhirnya isi tabel hash dicetak.


## Unguided

### 1. Soal mengenai materi

Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswamemiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru,
menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkannilai. Dengan ketentuan :

a. Setiap mahasiswa memiliki NIM dan nilai.

b. Program memiliki tampilan pilihan menu berisi poin C.

c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).


    // Ananda Baskoro Putra
    // 2311102187
    
    #include <iostream>
    #include <iomanip>
    using namespace std;
    
    const int MAX_SIZE = 10;
    
    // struktur data untuk setiap node
    struct mahasiswa
    {
        string nama;
        long long NIM;
        int nilai;
        mahasiswa *next; // pointer untuk menunjukkan node selanjutnya dalam collision handling
    
        mahasiswa(string nama, long long NIM, int nilai) : nama(nama), NIM(NIM), nilai(nilai), next(nullptr) {}
    };
    
    // class hash table
    class HashTable
    {
    private:
        mahasiswa **table; // array pointer untuk menunjukkan ke elemen-elemen tabel hash
    
        // fungsi hash sederhana
        int hash_func(long long key)
        {
            return key % MAX_SIZE; // menggunakan modulus untuk mendapatkan indeks
        }
    
    public:
        // constructor
        HashTable()
        {
            table = new mahasiswa *[MAX_SIZE](); // inisialisasi array pointer dengan nullptr
        }
    
        // destructor
        ~HashTable()
        {
            // menghapus semua node dan array pointer
            for (int i = 0; i < MAX_SIZE; ++i)
            {
                mahasiswa *current = table[i];
                while (current != nullptr)
                {
                    mahasiswa *temp = current;
                    current = current->next;
                    delete temp;
                }
            }
            delete[] table;
        }
    
        // insertion
        void insert(string nama, long long NIM, int nilai)
        {
            int index = hash_func(NIM);                                 // mendapatkan indeks berdasarkan NIM
            mahasiswa *new_mahasiswa = new mahasiswa(nama, NIM, nilai); // membuat node baru
            new_mahasiswa->next = table[index];                         // menambahkan node baru ke depan daftar di indeks yang tepat
            table[index] = new_mahasiswa;
        }
    
        // deletion
        void remove(long long NIM)
        {
            int index = hash_func(NIM);        // mendapatkan indeks berdasarkan NIM
            mahasiswa *current = table[index]; // mengambil node pertama di indeks yang tepat
            mahasiswa *prev = nullptr;         // pointer untuk node sebelumnya
            while (current != nullptr)
            {
                if (current->NIM == NIM)
                {
                    if (prev == nullptr)
                    {
                        table[index] = current->next; // jika node yang dihapus adalah node pertama di indeks, atur node berikutnya sebagai node pertama
                    }
                    else
                    {
                        prev->next = current->next; // jika bukan, hubungkan node sebelumnya dengan node setelahnya
                    }
                    delete current; // hapus node yang ditemukan
                    cout << "Mahasiswa dengan NIM " << NIM << " telah dihapus." << endl;
                    return;
                }
                prev = current;
                current = current->next;
            }
            cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
        }
    
        // searching by NIM
        mahasiswa *cari_NIM(long long NIM)
        {
            long long index = hash_func(NIM);  // mendapatkan indeks berdasarkan NIM
            mahasiswa *current = table[index]; // mengambil node pertama di indeks yang tepat
            while (current != nullptr)
            {
                if (current->NIM == NIM)
                {
                    return current; // kembalikan node jika NIM cocok
                }
                current = current->next;
            }
            return nullptr; // kembalikan nullptr jika tidak ditemukan
        }
    
        // searching by rentang nilai
        void cari_nilai(int awal, int akhir)
        {
            // mencetak header tabel
            cout << "-----------------------------------------------------------" << endl;
            cout << "|       Nama         |       NIM        |      Nilai      |" << endl;
            cout << "-----------------------------------------------------------" << endl;
            // traverse semua bucket pada tabel hash
            for (int i = 0; i < MAX_SIZE; ++i)
            {
                mahasiswa *current = table[i]; // mengambil node pertama di indeks yang tepat
                // traverse semua node dalam bucket
                while (current != nullptr)
                {
                    // jika nilai berada dalam rentang yang ditentukan, cetak informasi mahasiswa
                    if (current->nilai >= awal && current->nilai <= akhir)
                    {
                        cout << "| " << setw(19) << left << current->nama
                             << "| " << setw(17) << current->NIM
                             << "| " << setw(15) << current->nilai << " |" << endl;
                    }
                    current = current->next;
                }
            }
            cout << "-----------------------------------------------------------" << endl;
        }
    
        // traversal
        void traverse()
        {
            // mencetak header tabel
            cout << "-----------------------------------------------------------" << endl;
            cout << "|       Nama         |       NIM        |      Nilai      |" << endl;
            cout << "-----------------------------------------------------------" << endl;
            // traverse semua bucket pada tabel hash
            for (int i = 0; i < MAX_SIZE; ++i)
            {
                mahasiswa *current = table[i]; // mengambil node pertama di indeks yang tepat
                // traverse semua node dalam bucket
                while (current != nullptr)
                {
                    // cetak informasi mahasiswa
                    cout << "| " << setw(19) << left << current->nama
                         << "| " << setw(17) << current->NIM
                         << "| " << setw(15) << current->nilai << " |" << endl;
                    current = current->next;
                }
            }
            cout << "-----------------------------------------------------------" << endl;
        }
    };
    
    int main()
    {
        HashTable ht;
    
        int pilih, nilai, awal, akhir;
        string nama;
        long long NIM;
    
        do
        {
            // menu utama
            cout << "\nMenu:" << endl;
            cout << "1. Tambah Data Mahasiswa" << endl;
            cout << "2. Hapus Data Mahasiswa" << endl;
            cout << "3. Cari berdasarkan NIM" << endl;
            cout << "4. Cari berdasarkan Rentang Nilai" << endl;
            cout << "5. Tampilkan Semua Data" << endl;
            cout << "6. Keluar" << endl;
            cout << "Pilih menu : ";
            cin >> pilih;
    
            switch (pilih)
            {
            case 1:
                // tambah data mahasiswa
                cout << "Masukan nama : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukan NIM : ";
                cin >> NIM;
                cout << "Masukan nilai : ";
                cin >> nilai;
                ht.insert(nama, NIM, nilai);
                cout<<"Data berhasil ditambahkan"<<endl;
                break;
            case 2:
                // hapus data mahasiswa berdasarkan NIM
                cout << "Masukan NIM yang ingin dihapus : ";
                cin >> NIM;
                ht.remove(NIM);
                break;
            case 3:
                // cari mahasiswa berdasarkan NIM
                cout << "Masukan NIM yang ingin dicari : ";
                cin >> NIM;
                {
                    mahasiswa *mahasiswa_ptr = ht.cari_NIM(NIM);
                    if (mahasiswa_ptr)
                    {
                        cout << "Ditemukan mahasiswa dengan NIM " << NIM << " bernama " << mahasiswa_ptr->nama << " dan memiliki nilai " << mahasiswa_ptr->nilai << endl;
                    }
                    else
                    {
                        cout << "mahasiswa dengan NIM " << NIM << " tidak ditemukan" << endl;
                    }
                }
                break;
            case 4:
                // cari mahasiswa berdasarkan rentang nilai
                cout << "masukan nilai awal : ";
                cin >> awal;
                cout << "maukan nilai akhir : ";
                cin >> akhir;
                ht.cari_nilai(awal, akhir);
                break;
            case 5:
                // tampilkan semua data mahasiswa
                ht.traverse();
                break;
            case 6:
                cout << "Terimakasih" << endl; // keluar dari program
                break;
            default:
                cout << "Pilihan invalid!" << endl; // jika pilihan tidak valid
            }
        } while (pilih != 6); // ulangi sampai pengguna memilih untuk keluar
    
        return 0;
    }

#### Output 1

![Screenshot 2024-04-16 193601](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/584edeec-7013-4bfd-98a3-e6cb397acf76)

#### Output 2

![Screenshot 2024-04-16 193618](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/c191ce1d-754b-4ee2-b433-271791ede4d3)

#### Output 3

![Screenshot 2024-04-16 193630](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/f6dc33fe-7173-4b3f-a8de-fb67dd8a0975)

#### Output 4

![Screenshot 2024-04-16 193636](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/3386a8bf-aaab-4efe-a473-8d367eaefbb8)

#### Output 5

![Screenshot 2024-04-16 193646](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/90ebbb9a-3e5c-450d-9acd-155d0e55c693)

#### Out[ut 6

![Screenshot 2024-04-16 193653](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/cfa4249a-c77c-4060-a352-5fe4db76d164)


## Deskripsi program

Program ini berguna untuk menyimpan data mahasiswa, yaitu nama, NIM, dan nilai, dalam tabel hash. Setiap mahasiswa direpresentasikan oleh struktur data yang terdiri dari nama, NIM, dan nilai. 
Program ini menyediakan fungsi untuk menambahkan data mahasiswa baru, menghapus data mahasiswa berdasarkan NIM, mencari mahasiswa berdasarkan NIM, mencari mahasiswa berdasarkan rentang nilai, dan menampilkan 
semua data mahasiswa yang tersimpan dalam tabel hash. Dalam program utama, kita dapat memilih berbagai opsi melalui menu yang disediakan, dan program akan menanggapi sesuai dengan pilihan yang dibuat oleh 
pengguna hingga pengguna memilih untuk keluar dari program.

## Kesimpulan

Hash table adalah struktur data yang efisien digunakan untuk memetakan kunci ke nilai-nilai tertentu. Dengan menggunakan fungsi hash, kunci-kunci tersebut diubah menjadi indeks yang menunjukkan lokasi penyimpanan dalam tabel hash.
Hal ini memungkinkan akses cepat dan efisien terhadap data, dengan waktu akses rata-rata yang konstan (O(1)). Selain itu, teknik penanganan collision seperti chaining memungkinkan penanganan konflik yang terjadi saat dua kunci 
menghasilkan indeks yang sama. 

## Referensi

[1] Mulyana, A., et al., Cara Mudah Mempelajari Algoritma dan Struktur Data. Edisi Pertama. Yogyakarta : DIVA Press, 2021

[2] Malik, D. S. (2010). Struktur Data penggunaan C++.








