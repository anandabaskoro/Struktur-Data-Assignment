# <h1 align="center">Laporan Praktikum Modul 3 - Single and double linked list</h1>
<p align="center">Ananda Baskoro Putra</p>
<p align="center">2311102187 / 11-E-IF</p>

## Dasar Teori

Linked List atau struktur berkait, yaitu cara penyimpanan data secara terstruktur, sehingga pemrogram dapat secara otomatis menciptakan suatu tempat baru untuk menyimpan data kapan saja diperlukan.
Linked list mengandung tiga buah simpul atau node. Sebuah pointer menunjuk simpul terkiri dan setiap simpul mempunyai pointer yang menunjuk ke simpul berikutnya. Pointer pada simpul
terakhir tidak menunjuk ke mana-mana, maka berisi NULL.
Simpul pada Linked list terdiri dari dua komponen utama, yaitu :
1. Data, yaitu bisa berupa satu elemen data atau beberapa elemen data
2. Pointer yang menunjuk ke simpul lain.

## Guided 

### 1. Single Linked List
    #include <iostream>
    using namespace std;

    ///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
    //Deklarasi Struct Node
    struct Node{
    //komponen/member
    int data;
    Node *next;
    };
    Node *head;
    Node *tail;
    //Inisialisasi Node
    void init(){
    head = NULL;
    tail = NULL;
    }
    // Pengecekan
    bool isEmpty(){
    if (head == NULL)
    return true;
    else
    return false;
    }
    //Tambah Depan
    void insertDepan(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
    head = tail = baru;
    tail->next = NULL;
    
    }
    else{
    baru->next = head;
    head = baru;
    }
    }
    //Tambah Belakang
    void insertBelakang(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
    head = tail = baru;
    tail->next = NULL;
    }
    else{
    tail->next = baru;
    tail = baru;
    }
    }
    //Hitung Jumlah List
    int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
    jumlah++;
    hitung = hitung->next;
    }
    return jumlah;
    }
    //Tambah Tengah
    void insertTengah(int data, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
    cout << "Posisi diluar jangkauan" << endl;
    
    }
    else if( posisi == 1){
    cout << "Posisi bukan posisi tengah" <<
    
    endl;
    }
    else{
    Node *baru, *bantu;
    baru = new Node();
    baru->data = data;
    // tranversing
    bantu = head;
    int nomor = 1;
    while( nomor < posisi - 1 ){
    bantu = bantu->next;
    nomor++;
    }
    baru->next = bantu->next;
    bantu->next = baru;
    }
    }
    //Hapus Depan
    void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false){
    if (head->next != NULL){
    hapus = head;
    head = head->next;
    delete hapus;
    }
    else{
    head = tail = NULL;
    }
    }
    else{
    cout << "List kosong!" << endl;
    }
    }
    
    //Hapus Belakang
    void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
    if (head != tail){
    hapus = tail;
    bantu = head;
    while (bantu->next != tail){
    bantu = bantu->next;
    }
    tail = bantu;
    tail->next = NULL;
    delete hapus;
    }
    else{
    head = tail = NULL;
    }
    }
    else{
    cout << "List kosong!" << endl;
    }
    }
    //Hapus Tengah
    void hapusTengah(int posisi){
    Node *hapus, *bantu, *bantu2;
    if( posisi < 1 || posisi > hitungList() ){
    cout << "Posisi di luar jangkauan" << endl;
    }
    else if( posisi == 1){
    cout << "Posisi bukan posisi tengah" <<
    
    endl;
    }
    else{
    int nomor = 1;
    bantu = head;
    while( nomor <= posisi ){
    
    if( nomor == posisi-1 ){
    bantu2 = bantu;
    }
    if( nomor == posisi ){
    hapus = bantu;
    }
    bantu = bantu->next;
    nomor++;
    }
    bantu2->next = bantu;
    delete hapus;
    }
    }
    //Ubah Depan
    void ubahDepan(int data){
    if (isEmpty() == false){
    head->data = data;
    }
    else{
    cout << "List masih kosong!" << endl;
    }
    }
    //Ubah Tengah
    void ubahTengah(int data, int posisi){
    Node *bantu;
    if (isEmpty() == false){
    if( posisi < 1 || posisi > hitungList() ){
    cout << "Posisi di luar jangkauan" <<

    endl;
    }
    else if( posisi == 1){
    cout << "Posisi bukan posisi tengah" <<
    
    endl;
    }
    else{
    bantu = head;
    int nomor = 1;
    
    while (nomor < posisi){
    bantu = bantu->next;nomor++;
    }
    bantu->data = data;
    }
    }
    else{
    cout << "List masih kosong!" << endl;
    }
    }
    //Ubah Belakang
    void ubahBelakang(int data){
    if (isEmpty() == false){
    tail->data = data;
    }
    else{
    cout << "List masih kosong!" << endl;
    }
    }
    //Hapus List
    void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
    hapus = bantu;
    bantu = bantu->next;
    delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
    }
    //Tampilkan List
    void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
    
    while (bantu != NULL){
    cout << bantu->data << ends;
    bantu = bantu->next;
    }
    cout << endl;
    }
    else{
    cout << "List masih kosong!" << endl;
    }
    }
    int main(){
    init();
    insertDepan(3);tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
    }

   #### Output :

   ![Screenshot 2024-03-26 233926](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/52ff76c6-1ae2-4572-b1a5-1081820d45ce)

   ### Deskripsi Program:
   Program di atas merupakan implementasi dari struktur data linked list tunggal non-circular, dengan fungsi-fungsi dasar seperti penambahan node di depan,
   belakang, dan di tengah, penghapusan node dari depan, belakang, dan tengah, serta pengubahan nilai data node. Program ini juga menyediakan fungsi untuk menghitung jumlah 
   node dalam linked list dan membersihkan seluruh isi linked list. Di dalam fungsi main(), program menunjukkan contoh penggunaan fungsi-fungsi tersebut untuk manipulasi linked list.

### 2. Double Linked List
    
    #include <iostream>
    using namespace std;
    
    class Node {
        public:int data;
        Node* prev;
        Node* next;
    };
    class DoublyLinkedList {
            public:
            Node* head;
            Node* tail;
            DoublyLinkedList() {
                head = nullptr;
                tail = nullptr;
        }
        void push(int data) {
            Node* newNode = new Node;
            newNode->data = data;
            newNode->prev = nullptr;
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            } 
            else {
                tail = newNode;
            }
            head = newNode;
        }
        void pop() {
            if (head == nullptr) {
                return;
            }
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } 
            else {
                tail = nullptr;
            }
            delete temp;
        }
        bool update(int oldData, int newData) {
            Node* current = head;while (current != nullptr) {
                if (current->data == oldData) {
                    current->data = newData;
                    return true;
                }
                current = current->next;
            }
            return false;
        }
        void deleteAll() {
            Node* current = head;
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            head = nullptr;
            tail = nullptr;
        }
        void display() {
            Node* current = head;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    };
    
    
    int main() {
        DoublyLinkedList list;
        while (true) {
            cout << "1. Add data" << endl;
            cout << "2. Delete data" << endl;
            cout << "3. Update data" << endl;
            cout << "4. Clear data" << endl;
            cout << "5. Display data" << endl;
            cout << "6. Exit" << endl;int choice;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1: {
                    int data;
                    cout << "Enter data to add: ";
                    cin >> data;
                    list.push(data);
                    break;
                }
                case 2: {
                    list.pop();
                    break;
                }
                case 3: {
                    int oldData, newData;
                    cout << "Enter old data: ";
                    cin >> oldData;
                    cout << "Enter new data: ";
                    cin >> newData;
                    bool updated = list.update(oldData, newData);
                    if (!updated) {
                        cout << "Data not found" << endl;
                    }
                    break;
                }
                case 4: {
                    list.deleteAll();
                    break;
                }
                case 5: {
                    list.display();
                    break;
                }
                case 6: {
                    return 0;
                }
                default: {
                    cout << "Invalid choice" << endl;
                    break;
                }
            }
        }
        return 0;
    }
 #### Output :
![Screenshot 2024-03-27 205125](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/76f995a5-d068-47b4-83d1-1a39ff933b79)
![Screenshot 2024-03-27 205142](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/b6679010-d67c-45eb-a9f0-b86994a9af00)

 ### Deskripsi Program:
Program di atas merupakan implementasi dari struktur data linked list ganda (doubly linked list). Program ini menyediakan fungsionalitas untuk menambahkan data ke dalam linked list, 
menghapus data dari linked list, memperbarui data di dalam linked list, menghapus semua data dari linked list, dan menampilkan seluruh data yang ada dalam linked list. Pengguna dapat memilih operasi 
yang ingin dilakukan melalui menu yang ditampilkan di layar, dan program akan menjalankan operasi sesuai dengan pilihan pengguna. Program ini menggunakan konsep OOP (Object-Oriented Programming) dengan dua kelas utama,
yaitu Node untuk merepresentasikan setiap node dalam linked list dan DoublyLinkedList untuk mengelola linked list secara keseluruhan.

## Unguided 

### 1. Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:
### a. Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.
### b. Hapus data Akechi
### c. Tambahkan data berikut diantara John dan Jane : Futaba 18
### d. Tambahkan data berikut diawal : Igor 20
### e. Ubah data Michael menjadi : Reyn 18
### f. Tampilkan seluruh data
    
    //Ananda Baskoro P
    //2311102187
    
    
    #include <iostream>
    #include <string>
    
    using namespace std;
    
    // Struktur Node
    struct Node {
        string nama;
        int usia;
        Node* next;
    };
    
    // Kelas Linked List
    class LinkedList {
    private:
        Node* head;
    
    public:
        LinkedList() : head(nullptr) {}

    // Fungsi untuk menyisipkan data di akhir daftar
    void sisipkan(string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Fungsi untuk menampilkan semua data dalam daftar
    void tampilkan() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->nama << " " << temp->usia << endl;
            temp = temp->next;
        }
    }

    // Fungsi untuk menghapus node berdasarkan nama
    void hapusNode(string nama) {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        // Jika node head sendiri menyimpan nama yang akan dihapus
        if (temp != nullptr && temp->nama == nama) {
            head = temp->next;
            delete temp;
            return;
        }

        // Mencari node yang akan dihapus
        while (temp != nullptr && temp->nama != nama) {
            prev = temp;
            temp = temp->next;
        }

        // Jika nama tidak ada dalam daftar
        if (temp == nullptr) {
            return;
        }

        // Memutuskan hubungan node dari linked list
        prev->next = temp->next;
        delete temp;
    }

    // Fungsi untuk menyisipkan node setelah node tertentu
    void sisipkanSetelah(string namaSebelum, string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;

        Node* temp = head;
        while (temp != nullptr && temp->nama != namaSebelum) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << namaSebelum << " tidak ditemukan dalam daftar." << endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Fungsi untuk menyisipkan node di awal daftar
    void sisipkanDiAwal(string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;

        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk mengubah data berdasarkan nama
    void ubah(string nama, string namaBaru, int usiaBaru) {
        Node* temp = head;
        while (temp != nullptr && temp->nama != nama) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << nama << " tidak ditemukan dalam daftar." << endl;
            return;
        }

        temp->nama = namaBaru;
        temp->usia = usiaBaru;
    }
    };
    
    int main() {
        LinkedList daftar;

    // Memasukkan data
    daftar.sisipkan("Baskoro", 20);
    daftar.sisipkan("John", 19);
    daftar.sisipkan("Jane", 20);
    daftar.sisipkan("Michael", 18);
    daftar.sisipkan("Yusuke", 19);
    daftar.sisipkan("Akechi", 20);
    daftar.sisipkan("Hoshino", 18);
    daftar.sisipkan("Karin", 18);

    char pilihan;
    string nama, namaBaru;
    int usia, usiaBaru;

    do {
        cout << "Menu:" << endl;
        cout << "a. Tampilkan semua data" << endl;
        cout << "b. Hapus data Akechi" << endl;
        cout << "c. Tambahkan data di antara John dan Jane" << endl;
        cout << "d. Tambahkan data di awal" << endl;
        cout << "e. Ubah data Michael" << endl;
        cout << "f. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 'a':
                break;
            case 'b':
                daftar.hapusNode("Akechi");
                cout << "Data Akechi telah dihapus." << endl;
                break;
            case 'c':
                cout << "Masukkan nama dan usia yang ingin ditambahkan: ";
                cin >> nama >> usia;
                daftar.sisipkanSetelah("John", nama, usia);
                break;
            case 'd':
                cout << "Masukkan nama dan usia yang ingin ditambahkan di awal: ";
                cin >> nama >> usia;
                daftar.sisipkanDiAwal(nama, usia);
                break;
            case 'e':
                cout << "Masukkan nama dan usia baru untuk Michael: ";
                cin >> namaBaru >> usiaBaru;
                daftar.ubah("Michael", namaBaru, usiaBaru);
                break;
            case 'f':
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }

        // Menampilkan data setelah setiap operasi
        cout << "Data mahasiswa:" << endl;
        daftar.tampilkan();
        cout << endl;

    } while (pilihan != 'f');

    return 0;
    }

  #### Output :
  ![Screenshot 2024-03-27 205609](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/5685ba5e-135b-46f4-bb9f-0bba74ca8ee2)
  ![Screenshot 2024-03-27 205718](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/a73df40d-36f0-4274-82cf-c44ed275e39d)
  ![Screenshot 2024-03-27 205729](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/fd3dd9fa-10bf-49bc-b635-e0c5a0b58abb)

  
 ### Deskripsi Program:
 Program di atas merupakan implementasi dari linked list yang menggunakan struktur data berbasis node dan dilengkapi dengan kelas LinkedList untuk mengelola data. 
 Program ini memungkinkan pengguna untuk menambahkan data ke dalam linked list, menampilkan seluruh data yang ada, menghapus data berdasarkan nama, menyisipkan data 
 di antara dua node tertentu, menyisipkan data di awal linked list, serta mengubah data berdasarkan nama. Pengguna dapat memilih operasi yang ingin dilakukan melalui menu yang ditampilkan di layar,
 dan program akan menjalankan operasi sesuai dengan pilihan pengguna. Program ini menawarkan fungsionalitas dasar untuk manajemen data dan penyuntingan linked list.

 
### 2. Soal mengenai Double Linked List Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.
### Nama Produk Harga
### Originote 60.000
### Somethinc 150.000
### Skintific 100.000
### Wardah 50.000
### Hanasui 30.000

### Case:
### 1. Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific
### 2. Hapus produk wardah
### 3. Update produk Hanasui menjadi Cleora dengan harga 55.000
### 4. Tampilkan menu seperti dibawah ini

### Toko Skincare Purwokerto
### 1. Tambah Data
### 2. Hapus Data
### 3. Update Data
### 4. Tambah Data Urutan Tertentu
### 5. Hapus Data Urutan Tertentu
### 6. Hapus Seluruh Data
### 7. Tampilkan Data
### 8. Exit
### Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah ini :

### Nama Produk Harga
### Originote 60.000
### Somethinc 150.000
### Azarine 65.000
### Skintific 100.000
### Cleora 55.000
    
    //Ananda Baskoro P
    //2311102187
    
    #include <iostream>
    using namespace std;
    
    struct Node {
        string namaProduk;
        double harga;
        Node* prev;
        Node* next;
    };
    
    class LinkedList {
    private:
        Node* head;
        Node* tail;
    public:
        LinkedList() {
            head = NULL;
            tail = NULL;
        }

    void tambahData(string nama, double harga) {
        Node* newNode = new Node;
        newNode->namaProduk = nama;
        newNode->harga = harga;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void hapusData(string nama) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == nama) {
                if (current == head && current == tail) {
                    head = tail = NULL;
                } else if (current == head) {
                    head = head->next;
                    head->prev = NULL;
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = NULL;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan!" << endl;
    }

    void updateData(string nama, string newName, double newHarga) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == nama) {
                current->namaProduk = newName;
                current->harga = newHarga;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan!" << endl;
    }

    void tambahDataUrutanTertentu(string nama, double harga, string setelah) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == setelah) {
                Node* newNode = new Node;
                newNode->namaProduk = nama;
                newNode->harga = harga;
                newNode->prev = current;
                newNode->next = current->next;
                if (current->next != NULL) {
                    current->next->prev = newNode;
                }
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Produk setelahnya tidak ditemukan!" << endl;
    }

    void hapusDataUrutanTertentu(string nama) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == nama) {
                if (current == head) {
                    head = head->next;
                    head->prev = NULL;
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = NULL;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan!" << endl;
    }

    void hapusSeluruhData() {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = NULL;
    }

    void tampilkanData() {
        Node* current = head;
        cout << "----------------------" << endl;
        cout << "Nama Produk  ||\t Harga " << endl;
        cout << "----------------------" << endl;
        while (current != NULL) {
            cout << current->namaProduk << "\t" << current->harga << endl;
            current = current->next;
        }
    }
    };

    int main() {
        LinkedList daftarProduk;
        daftarProduk.tambahData("Originote", 60000);
        daftarProduk.tambahData("Somethinc", 150000);
        daftarProduk.tambahData("Skintific", 100000);
        daftarProduk.tambahData("Wardah", 50000);
        daftarProduk.tambahData("Hanasui", 30000);

    int pilihan;
    string nama, newName, setelah;
    double harga, newHarga;

    do {
        cout << "--------------------------------" << endl;
        cout << " || Toko Skincare Purwokerto || " << endl;
        cout << "--------------------------------" << endl;

        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Nama Produk: ";
                cin >> nama;
                cout << "Harga: ";
                cin >> harga;
                daftarProduk.tambahData(nama, harga);
                daftarProduk.tampilkanData();
                break;
            case 2:
                cout << "Nama Produk yang akan dihapus: ";
                cin >> nama;
                daftarProduk.hapusData(nama);
                daftarProduk.tampilkanData();
                break;
            case 3:
                cout << "Nama Produk yang akan diupdate: ";
                cin >> nama;
                cout << "Nama Baru: ";
                cin >> newName;
                cout << "Harga Baru: ";
                cin >> newHarga;
                daftarProduk.updateData(nama, newName, newHarga);
                daftarProduk.tampilkanData();
                break;
            case 4:
                cout << "Nama Produk: ";
                cin >> nama;
                cout << "Harga: ";
                cin >> harga;
                cout << "Setelah Produk: ";
                cin >> setelah;
                daftarProduk.tambahDataUrutanTertentu(nama, harga, setelah);
                daftarProduk.tampilkanData();
                break;
            case 5:
                cout << "Nama Produk yang akan dihapus: ";
                cin >> nama;
                daftarProduk.hapusDataUrutanTertentu(nama);
                daftarProduk.tampilkanData();
                break;
            case 6:
                daftarProduk.hapusSeluruhData();
                cout << "Seluruh data telah dihapus." << endl;
                break;
            case 7:
                daftarProduk.tampilkanData();
                break;
            case 8:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 8);

    return 0;
    }

  #### Output :
  ![Screenshot 2024-03-27 210547](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/55a781ba-6f96-4523-9e2d-bd6ebb78e2ec)
  ![Screenshot 2024-03-27 210601](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/85084b3b-c620-4f4b-b45e-18dd9d0bfa58)
  ![Screenshot 2024-03-27 210617](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/2df88092-bf06-4d6f-987d-cbfe30c59b84)
  ![Screenshot 2024-03-27 210632](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/39cfbf8b-df53-422f-8ab2-6f0a1c78fbf1)


   ### Deskripsi Program:
   Program di atas merupakan implementasi dari struktur data linked list ganda (doubly linked list) . Program ini digunakan untuk mengelola daftar produk pada sebuah toko skincare.
   Program menyediakan fungsi-fungsi untuk menambahkan data produk, menghapus data produk, mengubah data produk, menambahkan data produk di urutan tertentu, menghapus data produk di urutan tertentu, 
   menghapus seluruh data produk, dan menampilkan seluruh data produk yang tersedia. Pengguna dapat memilih operasi yang ingin dilakukan melalui menu yang ditampilkan di layar, dan program akan menjalankan
   operasi sesuai dengan pilihan pengguna. Program ini memanfaatkan konsep linked list untuk penyimpanan data yang fleksibel dan mudah diakses.


## Kesimpulan
Linked list merupakan metode yang efektif untuk mengelola data secara dinamis, memungkinkan penambahan, penghapusan, pembaruan, dan akses data tanpa memerlukan alokasi memori statis sebelumnya. Kelebihan utama
linked list adalah kemampuannya menangani data dengan ukuran yang tidak pasti dan memperbolehkan operasi penyisipan atau penghapusan elemen dengan cepat. Meskipun demikian, penggunaan linked list juga memiliki kelemahan
seperti penggunaan memori tambahan untuk menyimpan pointer dan kompleksitas akses yang tidak secepat array. Meski begitu, linked list tetap menjadi pilihan populer dalam implementasi struktur data dinamis di C++ karena
fleksibilitas dan kemampuannya dalam menangani situasi di mana jumlah elemen tidak pasti.Kelebihan linked list antara lain penambahan elemen tidak terbatas dan penghapusan elemen lebih cepat. Namun, linked list juga memiliki 
kekurangan, seperti hanya dapat diakses secara sekuensial dan memerlukan lebih banyak memori dalam jumlah yang besar.Secara keseluruhan, linked list adalah struktur data yang fleksibel dan efisien dalam operasi penyisipan dan 
penghapusan, namun perlu diperhatikan karakteristik dan kebutuhan spesifik dari aplikasi saat memilih menggunakan linked list sebagai struktur data.

## Referensi
https://www.journal.piksi.ac.id/
https://repository.unikom.ac.id/





  













    
