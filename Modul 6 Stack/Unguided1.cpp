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
