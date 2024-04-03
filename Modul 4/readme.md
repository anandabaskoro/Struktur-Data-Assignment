# <h1 align="center">Laporan Praktikum Modul 4 - Linked list circural</h1>
<p align="center">Ananda Baskoro Putra</p>
<p align="center">2311102187 / 11-E-IF</p>

## Dasar teori

linked list circular adalah variasi dari linked list di mana penunjuk berikutnya dari node terakhir menunjuk kembali ke node head. Hal ini menciptakan struktur circular, 
di mana list tersebut tidak memiliki awal atau akhir yang pasti. Dalam linked list non-circular, penunjuk berikutnya dari node terakhir disetel ke nol, yang menunjukkan akhir list.(1)

Single linked list sircular: Dalam Single linked list sircular, node terakhir dari list berisi penunjuk ke node pertama dari list.[2] Melintasi Single linked list sircular hingga kita 
mencapai node yang sama tempat kami memulai. Single linked list sircular tidak memiliki awal atau akhir. Tidak ada nilai null di bagian selanjutnya dari node mana pun.

Double linked list sircular:Double linked list sircular memiliki properti Double linked list dan linked list sircular di mana dua elemen berurutan dihubungkan atau dihubungkan oleh penunjuk 
sebelumnya dan berikutnya dan node terakhir menunjuk ke node pertama dengan penunjuk berikutnya dan juga node pertama menunjuk ke node terakhir dengan penunjuk sebelumnya.(2)

Linked List Non Circular
Linked list non-circular adalah struktur data linear di mana setiap elemen terhubung ke elemen berikutnya, namun elemen terakhir tidak terhubung kembali ke elemen pertama atau ke elemen mana pun dalam linked list. 
Sebagai akibatnya, traversing dari awal ke akhir linked list akan berakhir ketika mencapai elemen terakhir yang menunjuk ke nilai NULL. Ini membuat manipulasi dan pengelolaan data menjadi lebih sederhana dan jelas,
namun tidak memungkinkan traversing langsung kembali ke elemen pertama setelah mencapai elemen terakhir.(2)


## Guided 

### 1.Linked list non circural

    #include <iostream>
    
    using namespace std;
    
    struct Node
    {
        int data;
        Node *next;
    };
    
    Node *head;
    Node *tail;
    
    // inialisasi Node
    void init()
    {
        head = NULL;
        tail = NULL;
    }
    
    // pengecekan
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    // tambah depan
    void insertDepan(int nilai)
    {
        // buat node baru
        Node *baru = new Node;
        baru->data = nilai;
        baru->next = NULL;
    
        if (isEmpty())
        {
            head = tail = baru;
            tail->next = NULL;
        }
        else
        {
            baru->next = head;
            head = baru;
        }
    }
    
    // tambah belakang
    void insertBelakang(int nilai)
    {
        // buat node baru
        Node *baru = new Node;
        baru->data = nilai;
        baru->next = NULL;
    
        if (isEmpty())
        {
            head = tail = baru;
            tail->next = NULL;
        }
        else
        {
            tail->next = baru;
            tail = baru;
        }
    }
    
    // hitung jumlah list
    int hitungList()
    {
        Node *hitung;
        hitung = head;
        int jumlah = 0;
    
        while (hitung != NULL)
        {
            jumlah++;
            hitung = hitung->next;
        }
    
        return jumlah;
    }
    
    // tambah tengah
    void insertTengah(int data, int posisi)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi diluar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan di tengah" << endl;
        }
        else
        {
            Node *baru, *bantu;
            baru = new Node();
            baru->data = data;
    
            // tranversing
            bantu = head;
            int nomor = 1;
    
            while (nomor < posisi - 1)
            {
                bantu = bantu->next;
                nomor++;
            }
    
            baru->next = bantu->next;
            bantu->next = baru;
        }
    }
    
    // hapus depan
    void hapusDepan()
    {
        Node *hapus;
    
        if (!isEmpty())
        {
            if (head->next != NULL)
            {
                hapus = head;
                head = head->next;
                delete hapus;
            }
            else
            {
                head = tail = NULL;
            }
        }
        else
        {
            cout << "List Kosong!" << endl;
        }
    }
    
    // hapus belakang
    void hapusBelakang()
    {
        Node *hapus;
        Node *bantu;
    
        if (!isEmpty())
        {
            if (head != tail)
            {
                hapus = tail;
                bantu = head;
    
                while (bantu->next != tail)
                {
                    bantu = bantu->next;
                }
    
                tail = bantu;
                tail->next = NULL;
                delete hapus;
            }
            else
            {
                head = tail = NULL;
            }
        }
        else
        {
            cout << "List Kosong!" << endl;
        }
    }
    
    // hapsu tengah
    void hapusTengah(int posisi)
    {
        Node *hapus, *bantu, *bantu2;
    
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan di tengah" << endl;
        }
        else
        {
            int nomor = 1;
            bantu = head;
    
            while (nomor <= posisi)
            {
                if (nomor == posisi - 1)
                {
                    bantu2 = bantu;
                }
    
                if (nomor == posisi)
                {
                    hapus = bantu;
                }
    
                bantu = bantu->next;
                nomor++;
            }
            bantu2->next = bantu;
            delete hapus;
        }
    }
    
    // ubah depan
    void ubahDepan(int data)
    {
        if (!isEmpty())
        {
            head->data = data;
        }
        else
        {
            cout << "List masih kosong!" << endl;
        }
    }
    
    // ubah tengah
    void ubahTengah(int data, int posisi)
    {
        Node *bantu;
    
        if (!isEmpty())
        {
            if (posisi < 1 || posisi > hitungList())
            {
                cout << "Posisi di luar jangkauan" << endl;
            }
            else if (posisi == 1)
            {
                cout << "Posisi bukan di tengah" << endl;
            }
            else
            {
                bantu = head;
                int nomor = 1;
    
                while (nomor < posisi)
                {
                    bantu = bantu->next;
                    nomor++;
                }
    
                bantu->data = data;
            }
        }
        else
        {
            cout << "List masih kosong" << endl;
        }
    }
    
    // ubah belakang
    void ubahBelakang(int data)
    {
        if (!isEmpty())
        {
            tail->data = data;
        }
        else
        {
            cout << "List masih kosong" << endl;
        }
    }
    
    // hapus list
    void clearList()
    {
        Node *bantu, *hapus;
        bantu = head;
    
        while (bantu != NULL)
        {
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        }
    
        head = tail = NULL;
        cout << "List berhasil terhapus!" << endl;
    }
    
    // tampilkan list
    void tampil()
    {
        Node *bantu;
        bantu = head;
    
        if (!isEmpty())
        {
            while (bantu != NULL)
            {
                cout << bantu->data << ends;
                bantu = bantu->next;
            }
    
            cout << endl;
        }
        else
        {
            cout << "List masih kosong!" << endl;
        }
    }
    
    int main()
    {
        init();
    
        insertDepan(3);
        tampil();
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
        insertTengah(7, 2);
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

## Deskripsi program

Program tersebut adalah struktur data dinamis yang terdiri dari serangkaian node, dimana setiap node memiliki dua bagian:data dan pointer ke node berikutnya. Program ini menyediakan
fungsi-fungsi dasar untuk mengelola linked list, seperti penambahan elemen di depan, di belakang, atau di tengah, penghapusan elemen di depan, di belakang, atau di tengah, serta pengubahan
nilai elemen di depan, di belakang, atau di tengah. Selain itu, program juga memiliki fungsi untuk menampilkan isi linked list dan menghitung jumlah elemen dalam linked list.


### 2.Linked list circural
    
    #include <iostream>
    
    using namespace std;
    
    
    // program single linked list circular
    
    // deklarasi struct node
    struct Node
    {
        string data;
        Node *next;
    };
    
    Node *head, *tail, *baru, *bantu, *hapus;
    
    void init()
    {
        head = NULL;
        tail = head;
    }
    
    // pengecekan
    bool isEmpty()
    {
        if (head == NULL)
        {
            return 1; // true
        }
        else
        {
            return 0; // false
        }
    }
    
    // buat node baru
    void buatNode(string data)
    {
        baru = new Node;
        baru->data = data;
        baru->next = NULL;
    }
    
    // hitung list
    int hitungList()
    {
        bantu = head;
        int jumlah = 0;
    
        while (bantu != NULL)
        {
            jumlah++;
            bantu = bantu->next;
        }
    
        return jumlah;
    }
    
    // tambah depan
    void insertDepan(string data)
    {
        // buat node baru
        buatNode(data);
    
        if (isEmpty())
        {
            head = baru;
            tail = head;
            baru->next = head;
        }
        else
        {
            while (tail->next != head)
            {
                tail = tail->next;
            }
    
            baru->next = head;
            head = baru;
            tail->next = head;
        }
    }
    
    // tambah belakan
    void insertBelakang(string data)
    {
        // buat node baru
        buatNode(data);
    
        if (isEmpty())
        {
            head = baru;
            tail = head;
            tail->next = head;
        }
        else
        {
            while (tail->next != head)
            {
                tail = tail->next;
            }
    
            tail->next = baru;
            baru->next = head;
            tail = baru;
        }
    }
    
    // tambah tengah
    void insertTengah(string data, int posisi)
    {
        if (isEmpty())
        {
            head = baru;
            tail = head;
            baru->next = head;
        }
        else
        {
            baru->data = data;
    
            // transversing
            int nomor = 1;
            bantu = head;
    
            while (nomor < posisi - 1)
            {
                bantu = bantu->next;
                nomor++;
            }
    
            baru->next = bantu->next;
            bantu->next = baru;
        }
    }
    
    // hapus depan
    void hapusDepan()
    {
        if (!isEmpty())
        {
            hapus = head;
            tail = head;
    
            if (hapus->next == head)
            {
                head = NULL;
                tail = NULL;
    
                delete hapus;
            }
            else
            {
                while (tail->next != hapus)
                {
                    tail = tail->next;
                }
    
                head = head->next;
                tail->next = head;
                hapus->next = NULL;
    
                delete hapus;
            }
        }
        else
        {
            cout << "List masih kosong!" << endl;
        }
    }
    
    // hapus belakang
    void hapusBelakang()
    {
        if (!isEmpty())
        {
            hapus = head;
            tail = head;
    
            if (hapus->next == head)
            {
                head = NULL;
                tail = NULL;
    
                delete hapus;
            }
            else
            {
                while (hapus->next != head)
                {
                    hapus = hapus->next;
                }
    
                while (tail->next != hapus)
                {
                    tail = tail->next;
                }
    
                tail->next = head;
                hapus->next = NULL;
    
                delete hapus;
            }
        }
        else
        {
            cout << "List masih kosong!" << endl;
        }
    }
    
    // hapus tengah
    void hapusTengah(int posisi)
    {
        if (!isEmpty())
        {
            // transversing
            int nomor = 1;
            bantu = head;
    
            while (nomor < posisi - 1)
            {
                bantu = bantu->next;
                nomor++;
            }
    
            hapus = bantu->next;
            bantu->next = hapus->next;
    
            delete hapus;
        }
        else
        {
            cout << "List masih kosong!" << endl;
        }
    }
    
    // hapus list
    void clearList()
    {
        if (head != NULL)
        {
            hapus = head->next;
    
            while (hapus != head)
            {
                bantu = hapus->next;
                delete hapus;
                hapus = bantu;
            }
    
            delete head;
            head = NULL;
        }
    
        cout << "List berhasil terhapus!" << endl;
    }
    
    // tampilkan list
    void tampil()
    {
        if (!isEmpty())
        {
            tail = head;
            do
            {
                cout << tail->data << ends;
                tail = tail->next;
            } while (tail != head);
    
            cout << endl;
        }
        else
        {
            cout << "List masih kosong!" << endl;
        }
    }
    
    int main()
    {
        init();
        insertDepan("Ayam");
        tampil();
        insertDepan("Bebek");
        tampil();
        insertBelakang("Cicak");
        tampil();
        insertBelakang("Domba");
        tampil();
        hapusBelakang();
        tampil();
        hapusDepan();
        tampil();
        insertTengah("Sapi", 2);
        tampil();
        hapusTengah(2);
        tampil();
    
        return 0;
    }


## Deskripsi program

Program tersebut menjelaskan dimana setiap node menyimpan string sebagai datanya. Program ini menyediakan fungsi-fungsi dasar sepertipenambahan dan penghapusan elemen di depan,
di belakang, dan di tengah linked list, serta menampilkan isi linked list. Sirkularitas linked list diimplementasikan dengan menghubungkan pointer darinode terakhir kembali ke node pertama, membentuk lingkaran.

## Unguided 

### 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa, berikut contoh tampilan output dari nomor 1:

    //Ananda Baskroo Putra
    //2311102187
    
    
    #include <iostream>
    #include <cstring>
    using namespace std;
    
    // Struktur untuk node linked list
    struct Node
    {
        string nama, nim;
        Node *next;
    };
    
    Node *head = NULL; // Pointer untuk head linked list
    
    // Fungsi untuk menambahkan node baru di awal linked list
    void tambahDepan()
    {
        cout << "\n ||Tambah Depan||" << endl;
        cout << "" << endl;
        string nama, nim;
        cout << "Masukkan Nama: ";
        getline(cin >> ws, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);
    
        Node *newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = head;
        head = newNode;
        cout << "" << endl;
        cout << "Data telah ditambahkan" << endl;
    }
    
    // Fungsi untuk menambahkan node baru di akhir linked list
    void tambahBelakang()
    {
        cout << "\n ||Tambah Belakang||" << endl;
        cout << "" << endl;
        string nama, nim;
        cout << "Masukkan Nama: ";
        getline(cin >> ws, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);
    
        Node *newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = NULL;
    
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "" << endl;
        cout << "Data telah ditambahkan" << endl;
    }
    
    // Fungsi untuk menambahkan node baru di tengah linked list
    void tambahTengah()
    {
        cout << "\n ||Tambah Tengah||" << endl;
        cout << "" << endl;
        string nama, nim;
        int posisi;
        cout << "Masukkan Nama: ";
        getline(cin >> ws, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);
        cout << "Masukkan Posisi: ";
        cin >> posisi;
    
        Node *newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;
    
        if (posisi == 1)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i < posisi - 1; i++)
            {
                if (temp == NULL)
                {
                    cout << "Posisi tidak valid" << endl;
                    return;
                }
                temp = temp->next;
            }
            if (temp == NULL)
            {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        cout << "" << endl;
        cout << "Data telah ditambahkan" << endl;
    }
    
    // Fungsi untuk mengubah data node di awal linked list
    void ubahDepan()
    {
        cout << "\n ||Ubah Depan||" << endl;
        cout << "" << endl;
        if (head == NULL)
        {
            cout << "Linked list kosong" << endl;
            return;
        }
    
        string nama, nim;
        cout << "Masukkan nama baru: ";
        getline(cin >> ws, nama);
        cout << "Masukkan NIM baru: ";
        getline(cin, nim);
    
        head->nama = nama;
        head->nim = nim;
    
        cout << "" << endl;
        cout << "Data " << nama << " telah diubah" << endl;
    }
    
    // Fungsi untuk mengubah data node di akhir linked list
    void ubahBelakang()
    {
        cout << "" << endl;
        cout << "\n ||Ubah Belakang||" << endl;
        if (head == NULL)
        {
            cout << "Linked list kosong" << endl;
            return;
        }
    
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
    
        string nama, nim;
        cout << "Masukkan nama baru: ";
        getline(cin >> ws, nama);
        cout << "Masukkan NIM baru: ";
        getline(cin, nim);
    
        temp->nama = nama;
        temp->nim = nim;
    
        cout << "" << endl;
        cout << "Data " << nama << " telah diubah" << endl;
    }
    
    // Fungsi untuk mengubah data node di tengah linked list
    void ubahTengah()
    {
        cout << "\n ||Ubah Tengah||" << endl;
        cout << "" << endl;
        if (head == NULL)
        {
            cout << "Linked list kosong" << endl;
            return;
        }
    
        int posisi;
        cout << "Masukkan posisi: ";
        cin >> posisi;
    
        Node *temp = head;
        for (int i = 1; i < posisi; i++)
        {
            if (temp == NULL)
            {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }
    
        if (temp == NULL)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
    
        string nama, nim;
        cout << "Masukkan nama baru: ";
        getline(cin >> ws, nama);
        cout << "Masukkan NIM baru: ";
        getline(cin, nim);
    
        temp->nama = nama;
        temp->nim = nim;
    
        cout << "" << endl;
        cout << "Data " << nama << " telah diubah" << endl;
    }
    
    // Fungsi untuk menghapus node di awal linked list
    void hapusDepan()
    {
        cout << "\n ||Hapus Depan||" << endl;
        cout << "" << endl;
        if (head == NULL)
        {
            cout << "Linked list kosong" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    
        cout << "" << endl;
        cout << "Data depan telah dihapus" << endl;
    }
    
    // Fungsi untuk menghapus node di akhir linked list
    void hapusBelakang()
    {
        cout << "\n ||Hapus Belakang||" << endl;
        cout << "" << endl;
        if (head == NULL)
        {
            cout << "Linked list kosong" << endl;
            return;
        }
    
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            cout << "Data telah dihapus" << endl;
            return;
        }
    
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
    
        Node *deleteNode = temp->next;
        temp->next = NULL;
        delete deleteNode;
    
        cout << "" << endl;
        cout << "Data akhir telah dihapus" << endl;
    }
    
    // Fungsi untuk menghapus node di tengah linked list
    void hapusTengah()
    {
        cout << "\n ||Hapus Tengah||" << endl;
        cout << "" << endl;
        if (head == NULL)
        {
            cout << "Linked list kosong" << endl;
            return;
        }
    
        int posisi;
        cout << "Masukkan posisi: ";
        cin >> posisi;
    
        if (posisi == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Data telah dihapus" << endl;
            return;
        }
    
        Node *temp = head;
        for (int i = 1; i < posisi - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }
    
        if (temp == NULL || temp->next == NULL)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
    
        Node *deleteNode = temp->next;
        temp->next = temp->next->next;
        delete deleteNode;
    
        cout << "" << endl;
        cout << "Data ke-" << posisi << " telah dihapus" << endl;
    }
    
    // Fungsi untuk menghapus seluruh data dalam linked list
    void hapusSeluruhData()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *deleteNode = temp;
            temp = temp->next;
            delete deleteNode;
        }
        head = NULL;
        cout << "Seluruh data telah dihapus" << endl;
    }
    
    // Fungsi untuk menampilkan seluruh data dalam linked list
    void tampilkanData()
    {
        Node *temp = head;
        cout << "DATA MAHASISWA" << endl;
        cout << "|| NAMA "
             << "  |  "
             << "NIM"
             << "\t ||"
             << "\n"
             << endl;
        while (temp != NULL)
        {
            cout << temp->nama << "\t  |" << temp->nim << endl;
            temp = temp->next;
        }
    }
    
    int main()
    {
        int pilihan;
        do
        {
            cout << "\n||PROGAM SINGLE LINKED LIST NON-CIRCULAR||"
                 << "\n"
                 << endl;
            cout << "Tampilan Menu:" << endl;
            cout << "1. Tambah Depan" << endl;
            cout << "2. Tambah Belakang" << endl;
            cout << "3. Tambah Tengah" << endl;
            cout << "4. Ubah Depan" << endl;
            cout << "5. Ubah Belakang" << endl;
            cout << "6. Ubah Tengah" << endl;
            cout << "7. Hapus Depan" << endl;
            cout << "8. Hapus Belakang" << endl;
            cout << "9. Hapus Tengah" << endl;
            cout << "10. Hapus List" << endl;
            cout << "11. TAMPILKAN" << endl;
            cout << "0. KELUAR" << endl;
            cout << "Pilih Operasi: ";
            cin >> pilihan;
    
            switch (pilihan)
            {
            case 1:
                tambahDepan();
                break;
            case 2:
                tambahBelakang();
                break;
            case 3:
                tambahTengah();
                break;
            case 4:
                ubahDepan();
                break;
            case 5:
                ubahBelakang();
                break;
            case 6:
                ubahTengah();
                break;
            case 7:
                hapusDepan();
                break;
            case 8:
                hapusBelakang();
                break;
            case 9:
                hapusTengah();
                break;
            case 10:
                hapusSeluruhData();
                break;
            case 11:
                tampilkanData();
                break;
            case 0:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
            }
        } while (pilihan != 0);
    
        return 0;
    }

#### Output

#### Tampilan Operasi Tambah
![Screenshot 2024-04-03 213215](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/b73ea7e3-101f-4b1f-9e59-eef100e84564)
![Screenshot 2024-04-03 213223](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/cb6a5bd7-6105-47ee-b581-7033d17b6730)
![Screenshot 2024-04-03 213232](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/3975758b-80a6-4df0-91a0-01bc9daf20fb)


#### Tampilan operasi hapus
![Screenshot 2024-04-03 213232](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/06c53a30-5943-4712-96c4-1e7c2d274521)
![Screenshot 2024-04-03 213243](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/6d88eafe-7a80-4db7-9a4a-6544dcfead6d)
![Screenshot 2024-04-03 213252](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/9f38a8c9-c34a-47ed-be62-538fea7451fc)


#### Tampilan operasi ubah
![318922264-2baa9c4f-34c5-45bd-900d-917d8ad6938d](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/6501ec36-aa72-46cf-89aa-4786123abe3e)
![318922326-10e1b9ff-416b-49ce-95f8-82cac55193bf](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/a2d6a6e6-2703-40fb-936d-3d42543912c1)
![318922392-b4dc2225-4b25-46fe-a65b-04774744ccf0](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/9399d738-bd56-454c-92fe-d16fa4a70c0a)


#### Tampilan menu tampil data
![Screenshot 2024-04-03 214023](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/3821992d-017c-4e54-aab4-721e1572abcb)


### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)
![Screenshot 2024-04-03 214646](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/0bad2192-62a6-4ed7-a8c0-b58fbe236515)

### 3. Lakukan perintah berikut:

#### a) Tambah data Wati 2330004 diantara Farrel dan Denis
![Screenshot 2024-04-03 214646](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/07c1926c-7732-433c-8e0a-1553eab90e80)


#### b) Hapus data Denis
![Screenshot 2024-04-03 214652](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/87612b1e-7c15-4dc9-9df2-349fb50028ac)


#### c) Tambahkan data berikut di awal: Owi 2330000
![Screenshot 2024-04-03 214701](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/992b3e57-8617-4db4-b644-0d57fc13112c)


#### d) Tambahkan data berikut di akhir: David 2330010
![Screenshot 2024-04-03 214707](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/f38d076a-0911-4b15-8a39-2abbcdd99ea0)


#### e) Ubah data Udin menjadi data berikut: Idin 23300045
![Screenshot 2024-04-03 214715](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/d6bec41c-36a5-4ed6-8f55-9f41abeae4ca)


#### f) Ubah data terkahir menjadi berikut: Lucy 23300101
![Screenshot 2024-04-03 214722](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/8abbbb46-7204-414d-bf78-f51903d7929f)


#### g) Hapus data awal
![Screenshot 2024-04-03 214729](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/d36d88d1-1433-401f-a5c7-9b7ef5982139)


#### h) Ubah data awal menjadi berikut: Bagas 2330002
![318923747-f2ba1392-b682-4206-87f8-31793500ea4c](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/e021dea0-3adc-4db6-8031-f2f8ec2b7e8d)


#### i) Hapus data akhir
![Screenshot 2024-04-03 214735](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/26a53265-939c-4d54-a5ae-9834f5dd42ff)


#### j) Tampila seluruh data
![Screenshot 2024-04-03 214743](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/c9f90109-92a7-453e-aad0-2544e6bdab78)


### Deskrpisi Program
Program ini merupakan program yang digunakan untuk menyimpan data mahasiswa berupa nama dan NIM. Program ini menyediakan beberapa fungsi dasar seperti menambahkan data di awal, akhir, atau tengah linked list,
mengubah data, menghapus data, menghapus seluruh data, serta menampilkan seluruh data yang tersimpan. Program menggunakan perulangan do-while untuk menampilkan menu operasi kepada pengguna,
dan pengguna dapat memilih operasi yang diinginkan dengan memasukkan nomor pilihan.

## Kesimppulan
Keuntungan utama dari daftar tertaut melingkar adalah memungkinkan traversal terus menerus tanpa  kembali ke elemen pertama.Hal ini memungkinkan pemrosesan data yang lebih efisien bergantung pada kasus penggunaan Anda.
Daftar tertaut melingkar mirip dengan daftar tertaut ganda dalam  sifat melingkarnya, namun hanya ada satu penunjuk berikutnya, sedangkan daftar tertaut ganda memiliki dua penunjuk (berikutnya dan sebelumnya).

Namun, daftar tertaut melingkar juga memiliki kelemahan sebagai berikut: B.Kompleksitas penanganan kasus-kasus khusus, seperti menemukan elemen terakhir atau melakukan operasi pada elemen terakhir.
Selain itu, kesalahan dalam implementasi operasi penambahan dan penghapusan elemen dapat mengakibatkan loop tak terbatas.Oleh karena itu, penggunaan daftar tertaut melingkar harus dipertimbangkan secara
hati-hati tergantung pada kebutuhan aplikasi dan karakteristik data yang diproses.Untuk menggunakan struktur data ini  secara efektif dalam pengembangan perangkat lunak, Anda harus memahami kekuatan dan kelemahan struktur data ini.

## Referensi

Drozdek, A. (2012). struktur data dan algoritma dalam C++ (1)

Goodrich, M. T., Tamassia, R., & Mount, D. M. (2011). struktur data dan algoritma dalam C++






























