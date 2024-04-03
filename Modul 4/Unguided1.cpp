//RANGGA PRADARRELL FATHI
//2311102200
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