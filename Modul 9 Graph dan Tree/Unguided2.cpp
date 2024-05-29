#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Deklarasi Pohon
struct Pohon {
    char data2311102187;
    Pohon *left, *right, *parent; // pointer
};

// pointer global
Pohon *root;

// Inisialisasi
void init() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

Pohon *newPohon(char data2311102187) {
    Pohon *node = new Pohon();
    node->data2311102187 = data2311102187;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void buatNode(char data2311102187) {
    if (isEmpty()) {
        root = newPohon(data2311102187);
        cout << "\nNode " << data2311102187 << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon *insertLeft(char data2311102187, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->data2311102187 << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data2311102187);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data2311102187 << " berhasil ditambahkan ke child kiri " << node->data2311102187 << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data2311102187, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->data2311102187 << " sudah ada child kanan!" << endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data2311102187);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data2311102187 << " berhasil ditambahkan ke child kanan " << node->data2311102187 << endl;
            return baru;
        }
    }
}

void update(char data2311102187, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else {
            char temp = node->data2311102187;
            node->data2311102187 = data2311102187;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data2311102187 << endl;
        }
    }
}

void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData node : " << node->data2311102187 << endl;
        }
    }
}

void find(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\nData Node : " << node->data2311102187 << endl;
            cout << "Root : " << root->data2311102187 << endl;
            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data2311102187 << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data2311102187 << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling : " << node->parent->right->data2311102187 << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data2311102187 << endl;
            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data2311102187 << endl;
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            cout << " " << node->data2311102187 << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            inOrder(node->left);
            cout << " " << node->data2311102187 << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data2311102187 << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) {
            if (node != root) {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);

            if (node == root) {
                delete root;
                root = NULL;
            } else {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node) {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data2311102187 << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear() {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);

            if (heightKiri >= heightKanan) {
                return heightKiri + 1;
            } else {
                return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void characteristic() {
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree : " << s / h << endl;
    else
        cout << "Average Node of Tree : 0" << endl;
}

// Menampilkan Child dari node
void showChild(Pohon *node) {
    if (node->left != NULL)
        cout << "Child Kiri : " << node->left->data2311102187 << endl;
    else
        cout << "Child Kiri : (tidak punya Child kiri)" << endl;

    if (node->right != NULL)
        cout << "Child Kanan : " << node->right->data2311102187 << endl;
    else
        cout << "Child Kanan : (tidak punya Child kanan)" << endl;
}

// Menampilkan Descendant dari node
void showDescendants(Pohon *node) {
    if (node == NULL)
        return;
    
    queue<Pohon*> q;
    q.push(node);
    vector<char> descendants;

    while (!q.empty()) {
        Pohon* current = q.front();
        q.pop();

        if (current != node) {
            descendants.push_back(current->data2311102187);
        }

        if (current->left != NULL) {
            q.push(current->left);
        }

        if (current->right != NULL) {
            q.push(current->right);
        }
    }

    if (descendants.empty()) {
        cout << "Node " << node->data2311102187 << " tidak punya descendants." << endl;
    } else {
        cout << "Descendants of node " << node->data2311102187 << " : ";
        for (char data2311102187 : descendants) {
            cout << data2311102187 << " ";
        }
        cout << endl;
    }
}

// Fungsi untuk menampilkan menu dan mengelola input pengguna
void menu() {
    char data2311102187;
    Pohon *node;
    int pilihan;
    
    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Buat Node Root" << endl;
        cout << "2. Insert Left" << endl;
        cout << "3. Insert Right" << endl;
        cout << "4. Update Node" << endl;
        cout << "5. Retrieve Node" << endl;
        cout << "6. Find Node" << endl;
        cout << "7. PreOrder Traversal" << endl;
        cout << "8. InOrder Traversal" << endl;
        cout << "9. PostOrder Traversal" << endl;
        cout << "10. Tampilkan Child Node" << endl;
        cout << "11. Tampilkan Descendants Node" << endl;
        cout << "12. Hapus SubTree" << endl;
        cout << "13. Hapus Tree" << endl;
        cout << "14. Karakteristik Tree" << endl;
        cout << "15. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data untuk root: ";
                cin >> data2311102187;
                buatNode(data2311102187);
                break;
            case 2:
                cout << "Masukkan data untuk child kiri: ";
                cin >> data2311102187;
                cout << "Masukkan data parent: ";
                cin >> data2311102187;
                node = root;
                while (node && node->data2311102187 != data2311102187) {
                    if (node->left && node->left->data2311102187 == data2311102187) {
                        node = node->left;
                    } else if (node->right && node->right->data2311102187 == data2311102187) {
                        node = node->right;
                    } else {
                        break;
                    }
                }
                if (node && node->data2311102187 == data2311102187) {
                    insertLeft(data2311102187, node);
                } else {
                    cout << "Node parent tidak ditemukan!" << endl;
                }
                break;
            case 3:
                cout << "Masukkan data untuk child kanan: ";
                cin >> data2311102187;
                cout << "Masukkan data parent: ";
                cin >> data2311102187;
                node = root;
                while (node && node->data2311102187 != data2311102187) {
                    if (node->left && node->left->data2311102187 == data2311102187) {
                        node = node->left;
                    } else if (node->right && node->right->data2311102187 == data2311102187) {
                        node = node->right;
                    } else {
                        break;
                    }
                }
                if (node && node->data2311102187 == data2311102187) {
                    insertRight(data2311102187, node);
                } else {
                    cout << "Node parent tidak ditemukan!" << endl;
                }
                break;
            case 4:
                cout << "Masukkan data node yang akan diupdate: ";
                cin >> data2311102187;
                cout << "Masukkan data baru: ";
                char newData;
                cin >> newData;
                node = root;
                while (node && node->data2311102187 != data2311102187) {
                    if (node->left && node->left->data2311102187 == data2311102187) {
                        node = node->left;
                    } else if (node->right && node->right->data2311102187 == data2311102187) {
                        node = node->right;
                    } else {
                        break;
                    }
                }
                if (node && node->data2311102187 == data2311102187) {
                    update(newData, node);
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 5:
                cout << "Masukkan data node yang akan diretrieve: ";
                cin >> data2311102187;
                node = root;
                while (node && node->data2311102187 != data2311102187) {
                    if (node->left && node->left->data2311102187 == data2311102187) {
                        node = node->left;
                    } else if (node->right && node->right->data2311102187 == data2311102187) {
                        node = node->right;
                    } else {
                        break;
                    }
                }
                if (node && node->data2311102187 == data2311102187) {
                    retrieve(node);
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 6:
                cout << "Masukkan data node yang akan dicari: ";
                cin >> data2311102187;
                node = root;
                while (node && node->data2311102187 != data2311102187) {
                    if (node->left && node->left->data2311102187 == data2311102187) {
                        node = node->left;
                    } else if (node->right && node->right->data2311102187 == data2311102187) {
                        node = node->right;
                    } else {
                        break;
                    }
                }
                if (node && node->data2311102187 == data2311102187) {
                    find(node);
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 7:
                cout << "\nPreOrder :" << endl;
                preOrder(root);
                cout << "\n" << endl;
                break;
            case 8:
                cout << "InOrder :" << endl;
                inOrder(root);
                cout << "\n" << endl;
                break;
            case 9:
                cout << "PostOrder :" << endl;
                postOrder(root);
                cout << "\n" << endl;
                break;
            case 10:
                cout << "Masukkan data node: ";
                cin >> data2311102187;
                node = root;
                while (node && node->data2311102187 != data2311102187) {
                    if (node->left && node->left->data2311102187 == data2311102187) {
                        node = node->left;
                    } else if (node->right && node->right->data2311102187 == data2311102187) {
                        node = node->right;
                    } else {
                        break;
                    }
                }
                if (node && node->data2311102187 == data2311102187) {
                    showChild(node);
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 11:
                cout << "Masukkan data node: ";
                cin >> data2311102187;
                node = root;
                while (node && node->data2311102187 != data2311102187) {
                    if (node->left && node->left->data2311102187 == data2311102187) {
                        node = node->left;
                    } else if (node->right && node->right->data2311102187 == data2311102187) {
                        node = node->right;
                    } else {
                        break;
                    }
                }
                if (node && node->data2311102187 == data2311102187) {
                    showDescendants(node);
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 12:
                cout << "Masukkan data node untuk menghapus subtree: ";
                cin >> data2311102187;
                node = root;
                while (node && node->data2311102187 != data2311102187) {
                    if (node->left && node->left->data2311102187 == data2311102187) {
                        node = node->left;
                    } else if (node->right && node->right->data2311102187 == data2311102187) {
                        node = node->right;
                    } else {
                        break;
                    }
                }
                if (node && node->data2311102187 == data2311102187) {
                    deleteSub(node);
                } else {
                    cout << "Node tidak ditemukan!" << endl;
                }
                break;
            case 13:
                clear();
                break;
            case 14:
                characteristic();
                break;
            case 15:
                cout << "Keluar..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 15);
}

int main() {
    init();
    menu();
    return 0;
}
