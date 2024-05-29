# <h1 align="center">Laporan Praktikum Modul 9 - Graph dan tree</h1>
<p align="center">Ananda Baskoro Putra</p>
<p align="center">2311102187 / 11-E-IF</p>

## Dasar teori

Graph

Graph adalah kumpulan node (simpul) di dalam bidang  dua dimensi yang dihubungkan dengan sekumpulan garis  (sisi). Graph dapat digunakan untuk merepresentasikan objek objek diskret dan hubungan antara objek-objek tersebut.Representasi visual dari graph adalah dengan menyatakan 
objek sebagai node, bulatan, atau titik (vertex), sedangkan hubungan antara objek dinyatakan dengan garis (edge).

Graph merupakan suatu cabang ilmu yang memiliki banyak terapan. Banyak sekali struktur yang bisa direpresentasikan dengan graph, dan banyak masalah yang dapat diselesaikan dengan bantuan graph. Seringkali, graph digunakan untuk merepresentasikan suatu jaringan. Misalkan, jaringan jalan raya dimodelkan graph dengan kota sebagai simpul (vertex/ node) dan jalan yang menghubungkan setiap kotanya sebagai sisi (edge) yang bobotnya (weight) adalah panjang dari jalan tersebut. Ada beberapa cara untuk menyimpan graph di dalam sistem komputer.

Ada bebrapa istilah pada graph diantaranya vertex, edge, adjacent, weight, path, cycle/circuit. Dan juga ada beberapa jenis graph yaitu graph tak berarah, graph berarah, graph berbobot.[1]

Tree

Struktur pohon (tree) merupakan struktur yang penting mengharuskan kita mengorganisasikan informasi berdasarkan struktur lojik. Struktur data tree juga memungkinkan untuk mengakses suatu elemen dengan khusus. Struktur tree banyak dipakai untuk menggambarkan data yang memiliki struktur seperti pohon atau ada disebut sebagai struktur yang hirarkis.Struktur tree digunakan banyak di berbagai area. Struktur organisasi banyak digunakan di suatu perusahaan menyerupai struktur pohon. Sebagai contoh, seorang direktur di perusahaan membawahi wakil direktur. yang terjadi saat ini adalah orang-orang yang dihadapkan dengan struktur seperti ini membangun model data dan komponen pengelolaan datanya secara sendiri. Setiap orang membangun model data pohonnya sendiri sekaligus komponen pengelolaan datanya. Terlebih lagi, struktur pohon yang dikelola pada struktur data eksternal tidak banyak dibahas.Suatu tree merupakan sekumpulan simpul yang saling terhubung satu sama lain membentuk struktur sebuah pohon. struktur ini merupakan setiap simpul yang terhubung, tidak memiliki simpul anak, dan satu simpul ayah. Simpul yang tidak mempunyai simpul ayah disebut simpul akar.Dalam struktur pohon, hanya terdapat satu path yang menghubungkan satu simpul ke yang lain.[2]

## Guided

1.Program Graph
    
    #include <iostream>
    #include <iomanip>
    using namespace std;
    string simpul[7] = {
    "Ciamis",
    "Bandung",
    "Bekasi",
    "tasikmalaya",
    "Cianjur",
    "Purwokerto",
    "Yogyakarta"
    };
    int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
    };
    void tampilGraph(){
    for (int baris = 0; baris <7; baris ++){
    cout <<" " << setiosflags (ios::left)<<setw (15)
    << simpul [baris] << " : ";
    for (int kolom = 0; kolom<7; kolom++){
    if (busur[baris][kolom]!=0){
    cout << " " << simpul[kolom]<< "(" << busur[baris][kolom]
    
    << ")";
    }
    }
    cout << endl;
    }
    }
    int main(){
    tampilGraph();
    return 0;
    }

## Deskripsi program

Program diatas merupakan matriks ketetanggaan untuk merepresentasikan graf berarah dengan simpul-simpul yang mewakili kota-kota seperti Ciamis, Bandung, Bekasi, Tasikmalaya, Cianjur, Purwokerto, dan Yogyakarta. Matriks ketetanggaan busur menyimpan bobot busur antara simpul-simpul tersebut, di mana nilai nol menunjukkan tidak ada hubungan langsung antara dua simpul. Fungsi tampilGraph menampilkan graf dengan mencetak setiap simpul dan busur yang terhubung ke simpul-simpul lainnya beserta bobotnya, menggunakan manipulasi format untuk membuat tampilan lebih rapi. Program ini membantu dalam visualisasi graf dengan memberikan representasi yang jelas tentang bagaimana simpul-simpul tersebut terhubung.

2.Program tree

    #include <iostream>
    
    using namespace std;
    
    // PROGRAM BINARY TREE
    // Deklarasi Pohon
    
    struct Pohon {
        char data;
        Pohon *left, *right, *parent; //pointer
    };
    
    //pointer global
    Pohon *root;
    
    // Inisialisasi
    void init() {
        root = NULL;
    }
    
    bool isEmpty() {
        return root == NULL;
    }
    
    Pohon *newPohon(char data) {
        Pohon *node = new Pohon();
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;
        return node;
    }
    
    void buatNode(char data) {
        if (isEmpty()) {
            root = newPohon(data);
                cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
        } else {
            cout << "\nPohon sudah dibuat" << endl;
        }
    }
    
    Pohon *insertLeft(char data, Pohon *node) {
        if (isEmpty()) {
            cout << "\nBuat tree terlebih dahulu!" << endl;
            return NULL;
        } else {
            if (node->left != NULL) {
                cout << "\nNode " << node->data << " sudah ada child kiri!"<< endl;
                return NULL;
            } else {
                Pohon *baru = newPohon(data);
                baru->parent = node;
                node->left = baru;
                cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
                return baru;
            }
        }
    }
    
    Pohon *insertRight(char data, Pohon *node) {
        if (isEmpty()) {
            cout << "\nBuat tree terlebih dahulu!" << endl;
            return NULL;
        } else {
            if (node->right != NULL) {
                cout << "\nNode " << node->data << " sudah ada child kanan!"<< endl;
                return NULL;
            } else {
                Pohon *baru = newPohon(data);
                baru->parent = node;
                node->right = baru;
                    cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
                    return baru;
            }
        }
    }
    
    void update(char data, Pohon *node) {
        if (isEmpty()) {
            cout << "\nBuat tree terlebih dahulu!" << endl;
        } else {
            if (!node)
                cout << "\nNode yang ingin diganti tidak ada!!" << endl;
            else {
                char temp = node->data;
                node->data = data;
                cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
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
                cout << "\nData node : " << node->data << endl;
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
                cout << "\nData Node : " << node->data << endl;
                cout << "Root : " << root->data << endl;
                if (!node->parent)
                    cout << "Parent : (tidak punya parent)" << endl;
                else
                    cout << "Parent : " << node->parent->data << endl;
                if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                    cout << "Sibling : " << node->parent->left->data << endl;
                else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                    cout << "Sibling : " << node->parent->right->data << endl;
                else
                    cout << "Sibling : (tidak punya sibling)" << endl;
                if (!node->left)
                    cout << "Child Kiri : (tidak punya Child kiri)" << endl;
                else
                    cout << "Child Kiri : " << node->left->data << endl;
                if (!node->right)
                    cout << "Child Kanan : (tidak punya Child kanan)" << endl;
                else
                    cout << "Child Kanan : " << node->right->data << endl;
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
                cout << " " << node->data << ", ";
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
            cout << " " << node->data << ", ";
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
            cout << " " << node->data << ", ";
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
                cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
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
    
    int main() {
        init();
        buatNode('A');
    
        Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;
    
        nodeB = insertLeft('B', root);
        nodeC = insertRight('C', root);
        nodeD = insertLeft('D', nodeB);
        nodeE = insertRight('E', nodeB);
        nodeF = insertLeft('F', nodeC);
        nodeG = insertLeft('G', nodeE);
        nodeH = insertRight('H', nodeE);
        nodeI = insertLeft('I', nodeG);
        nodeJ = insertRight('J', nodeG);
    
        update('Z', nodeC);
        update('C', nodeC);
        retrieve(nodeC);
        find(nodeC);
        cout << "\nPreOrder :" << endl;
        preOrder(root);
        cout << "\n" << endl;
        cout << "InOrder :" << endl;
        inOrder(root);
        cout << "\n" << endl;
        cout << "PostOrder :" << endl;
        postOrder(root);
        cout << "\n" << endl;
        characteristic();
        deleteSub(nodeE);
        cout << "\nPreOrder :" << endl;
        preOrder(root);
        cout << "\n" << endl;
        characteristic();
    }

## Deskripsi program

Program dimulai dengan mendeklarasikan struktur Pohon, yang mencakup data, serta pointer untuk anak kiri, anak kanan, dan parent. Fungsi init menginisialisasi pohon dengan root sebagai NULL. Ada berbagai fungsi untuk membuat node baru (newPohon), menambah node kiri (insertLeft) dan kanan (insertRight), memperbarui data node (update), mengambil data node (retrieve), dan menemukan informasi node (find). Penelusuran dilakukan menggunakan metode pre-order, in-order, dan post-order. Fungsi lain termasuk menghapus seluruh pohon (deleteTree), menghapus subtree (deleteSub), membersihkan pohon (clear), menghitung ukuran pohon (size), dan menghitung tinggi pohon (height). Fungsi characteristic menampilkan ukuran, tinggi, dan rata-rata node per level. Pada main, berbagai node dibuat dan dihubungkan untuk membentuk pohon, kemudian beberapa operasi dilakukan seperti pembaruan node, penelusuran, dan karakteristik pohon ditampilkan.

## Unguided

1.Buatlah program graph dengan menggunakan inputan user untuk menghitung  jarak dari sebuah kota ke kota lainnya. 

    #include <iostream>
    #include <vector>
    #include <set>
    #include <climits>
    #include <algorithm>
    
    using namespace std;
    
    // Struktur untuk merepresentasikan simpul dalam graph
    struct Vertex {
        string name_Ananda_2311102187;
        int distance;
    };
    
    // Fungsi untuk membuat graph yang direpresentasikan sebagai adjacency matrix
    vector<vector<int>> createGraph(vector<string>& vertices) {
        // Mendapatkan jumlah simpul dari user
        int numVertices;
        cout << "Masukkan jumlah simpul: ";
        cin >> numVertices;
    
        // Memasukkan nama simpul
        vertices.resize(numVertices);
        for (int i = 0; i < numVertices; i++) {
            cout << "Masukkan nama simpul " << i + 1 << ": ";
            cin >> vertices[i];
        }
    
        // Membangun adjacency matrix
        vector<vector<int>> adjacencyMatrix(numVertices, vector<int>(numVertices));
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (i == j) {
                    // Bobot untuk simpul yang sama selalu 0
                    adjacencyMatrix[i][j] = 0;
                } else {
                    cout << "Masukkan bobot " << vertices[i] << "-->" << vertices[j] << ": ";
                    cin >> adjacencyMatrix[i][j];
                }
            }
        }
    
        return adjacencyMatrix;
    }
    
    // Fungsi untuk mencari jarak antara dua kota (simpul) dalam graph
    int findDistance(const vector<vector<int>>& adjacencyMatrix, const vector<string>& vertices,
                     const string& startCity, const string& endCity) {
        // Mencari indeks kota awal dan kota tujuan dalam daftar simpul
        auto startIt = find(vertices.begin(), vertices.end(), startCity);
        auto endIt = find(vertices.begin(), vertices.end(), endCity);
    
        if (startIt == vertices.end() || endIt == vertices.end()) {
            return -1; // Kota tidak ditemukan
        }
    
        int startIndex = distance(vertices.begin(), startIt);
        int endIndex = distance(vertices.begin(), endIt);
    
        // Menghitung jarak menggunakan algoritma Dijkstra
        vector<int> distances(vertices.size(), INT_MAX);
        distances[startIndex] = 0;
    
        // Menginisialisasi set simpul yang belum dikunjungi
        set<int> unvisitedVertices;
        for (int i = 0; i < vertices.size(); i++) {
            unvisitedVertices.insert(i);
        }
    
        // Menjalankan algoritma Dijkstra
        while (!unvisitedVertices.empty()) {
            // Menemukan simpul dengan jarak terpendek dari simpul awal yang belum dikunjungi
            int currentVertex = *min_element(unvisitedVertices.begin(), unvisitedVertices.end(),
                                             [&](int i, int j) { return distances[i] < distances[j]; });
    
            // Menghapus simpul dari set simpul yang belum dikunjungi
            unvisitedVertices.erase(currentVertex);
    
            // Memperbarui jarak simpul yang terhubung dengan simpul saat ini
            for (int neighbor = 0; neighbor < vertices.size(); neighbor++) {
                if (adjacencyMatrix[currentVertex][neighbor] > 0 &&
                    distances[currentVertex] + adjacencyMatrix[currentVertex][neighbor] < distances[neighbor]) {
                    distances[neighbor] = distances[currentVertex] + adjacencyMatrix[currentVertex][neighbor];
                }
            }
        }
    
        // Mengembalikan jarak ke kota tujuan
        return distances[endIndex];
    }
    
    int main() {
        // Membangun graph
        vector<string> vertices;
        vector<vector<int>> adjacencyMatrix = createGraph(vertices);
    
        // Mencari jarak antara dua kota
        string startCity, endCity;
        cout << "Masukkan nama kota awal: ";
        cin >> startCity;
        cout << "Masukkan nama kota tujuan: ";
        cin >> endCity;
    
        int distance = findDistance(adjacencyMatrix, vertices, startCity, endCity);
    
        // Menampilkan hasil
        if (distance == -1) {
            cout << "Tidak ada jalur dari " << startCity << " ke " << endCity << "." << endl;
        } else {
            cout << "Jarak dari " << startCity << " ke " << endCity << " adalah " << distance << " kilometer." << endl;
        }
    
        return 0;
    }

## Screenshoot output

![Screenshot 2024-05-28 220459](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/ab8aed8a-66c4-4358-8ea0-32d7601c00d9)

## Deskripsi program

Program tersebut berguna untuk mencari jarak terpendek antara dua kota dalam sebuah graf yang direpresentasikan sebagai adjacency matrix. Pertama, program meminta pengguna untuk memasukkan jumlah simpul (kota) dan nama-nama simpul tersebut, serta bobot (jarak) antara setiap pasangan simpul. Setelah membangun graf, pengguna diminta untuk memasukkan kota awal dan kota tujuan. Fungsi findDistance kemudian menggunakan algoritma Dijkstra untuk menghitung jarak terpendek dari kota awal ke kota tujuan. Jika jalur ditemukan, program menampilkan jarak tersebut; jika tidak, program menampilkan pesan bahwa tidak ada jalur yang tersedia.

2.Modifikasi guided tree diatas dengan program menu menggunakan input data tree  dari user dan berikan fungsi tambahan untuk menampilkan node child dan  descendant dari node yang diinput kan! 

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

## Screenshoot output


![Screenshot 2024-05-29 204357](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/5dc7557b-bfaf-4006-b14f-d20b87827905)


![Screenshot 2024-05-29 204408](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/c2513d8b-72b5-45a5-b1c6-4feacec169a5)


![Screenshot 2024-05-29 204417](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/6953a5db-dcf0-40cf-a0a1-eb430cfb1b8e)


![Screenshot 2024-05-29 204425](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/c44427fe-f979-404b-9893-801248e50507)


![Screenshot 2024-05-29 204433](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/1c1ecaec-a24e-4b12-9a59-ecbf58c4197b)


![Screenshot 2024-05-29 204442](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/6df90242-f37e-44ea-b5f9-7a6214359140)


![Screenshot 2024-05-29 204456](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/402e62c6-6ddc-4c4d-a256-82151dbe7f8b)


![Screenshot 2024-05-29 204504](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/7b288929-0999-42e1-81b4-28402919a9d7)


![Screenshot 2024-05-29 204511](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/ed63dc44-90aa-43a5-801d-c593be27980b)


![Screenshot 2024-05-29 204521](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/128ba8e4-9054-4891-b75c-29a185ceccbf)


![Screenshot 2024-05-29 204527](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/e9c9f3f2-cdbc-4338-881f-fa09a87459df)


![Screenshot 2024-05-29 204535](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/ffd9446a-df4f-4a96-ba6b-b5335a018255)


![Screenshot 2024-05-29 204542](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/d8f2db95-3901-4991-801e-b69be40ef88c)


![Screenshot 2024-05-29 204734](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/404c2860-5425-4100-9051-996a0f636194)


![Screenshot 2024-05-29 204750](https://github.com/anandabaskoro/Struktur-Data-Assignment/assets/162494864/9ad3dcd5-2121-4d2b-96a8-7ceca4df4a70)

## Deskripsi program

Program ini berguna untuk melakukan berbagai operasi seperti menambahkan node, mengubah data node, menelusuri pohon menggunakan metode pre-order, in-order, dan post-order, serta menampilkan karakteristik pohon seperti ukuran dan tinggi. Pengguna dapat membuat pohon dengan memasukkan node root terlebih dahulu, kemudian menambahkan anak kiri atau kanan pada node yang sudah ada. Selain itu, program juga mendukung operasi untuk mencari, menampilkan, dan menghapus node, serta menghapus subtree dan seluruh pohon. Dengan menu interaktif, pengguna dapat memilih berbagai opsi untuk mengelola dan menampilkan informasi tentang pohon biner.

## Kesimpulan

Graphs dan trees adalah dua struktur data yang sangat penting dalam ilmu komputer. Graphs, dengan simpul dan sisi yang menghubungkannya, memberikan cara yang fleksibel untuk merepresentasikan berbagai hubungan kompleks antara objek. Mereka digunakan luas dalam berbagai aplikasi seperti jaringan sosial, perencanaan rute, dan pemodelan masalah kehidupan nyata lainnya. Di sisi lain, trees menyediakan struktur hierarkis yang terorganisir dengan baik, dengan simpul akar dan cabang yang terhubung secara berurutan. Mereka adalah landasan dari banyak algoritma pencarian, pemrosesan bahasa alami, dan implementasi struktur data efisien seperti binary search trees. Kedua struktur data ini memiliki kegunaan yang unik dan penting dalam pemrograman, membantu kita memahami dan memanipulasi informasi dengan cara yang berbeda.

## Referensi

[1] Mulyana, A., et al., Cara Mudah Mempelajari Algoritma dan Struktur Data. Edisi Pertama. Yogyakarta : DIVA Press, 2021

Agustin, S. (2022). IMPLEMENTASI STRUKTUR DATA TREE PADA WEB BLOG SEBAGAI MEDIA PEMBEOLAJARAN. 7.









