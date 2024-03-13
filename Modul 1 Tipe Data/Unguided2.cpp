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
