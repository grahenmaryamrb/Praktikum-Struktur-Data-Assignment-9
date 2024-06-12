# <h1 align="center">Laporan Praktikum Modul Rekursif & Hash Table</h1>
<p align="center">Grahen Maryam Rompas Basiran</p>
<p align="center">2311110062</p>

## Dasar Teori
### REKURSIF
Rekursif adalah suatu konsep dalam ilmu komputer dan pemrograman di mana suatu fungsi atau prosedur dapat memanggil dirinya sendiri secara langsung atau tidak langsung. Dengan kata lain, rekursif adalah proses di mana suatu masalah diselesaikan dengan menguraikan masalah tersebut menjadi submasalah yang lebih sederhana, kemudian menyelesaikan masing-masing submasalah secara rekursif [1].

## HASH TABLE
Hash Table (Tabel Hash) adalah struktur data yang digunakan untuk menyimpan pasangan kunci-nilai (key-value pairs). Hash table mengimplementasikan operasi penyisipan, pencarian, dan penghapusan dengan kompleksitas waktu rata-rata O(1), yang sangat efisien dalam banyak kasus [2].

## Guided
### 1. Rekursif Langsung (Direct Recursion)
```C++
#include <iostream>
using namespace std;

void countdown(int 'n') {
    if ('n' >= 1) {
        cout << 'n' << " ";
        countdown('n' - 1);
    }
}

int main() {
    cout << "Rekursif Langsung: ";
    countdown(5); // 5 merupakan input nya
    cout << endl;
    return 0;
}
```
### Penjelasan
Program di atas menggunakan konsep rekursif untuk melakukan hitung mundur dari angka yang diinputkan.

1. Program mendefinisikan sebuah fungsi bernama `countdown` yang menerima satu parameter bertipe integer yaitu `n`.

2. Fungsi `countdown` menggunakan konsep rekursif. Artinya, fungsi tersebut memanggil dirinya sendiri di dalam fungsi itu sendiri.

3. Fungsi `countdown` memiliki kasus basis (base case) yaitu ketika `n` kurang dari 1. Dalam kasus ini, fungsi tidak akan melakukan apapun dan berhenti memanggil dirinya sendiri (rekursif berhenti).

4. Jika `n` lebih besar atau sama dengan 1, maka program akan melakukan dua hal:
   a. Mencetak nilai `n` ke layar.
   b. Memanggil fungsi `countdown` lagi dengan parameter `n-1` (rekursif).

5. Dalam fungsi `main`, program memanggil fungsi `countdown` dengan parameter 5, yang berarti hitung mundur dimulai dari angka 5.

6. Ketika fungsi `countdown(5)` dipanggil, program akan mencetak 5, lalu memanggil `countdown(4)`.
   Ketika `countdown(4)` dipanggil, program akan mencetak 4, lalu memanggil `countdown(3)`.
   Proses ini berlanjut sampai `countdown(1)` dipanggil.
   Ketika `countdown(1)` dipanggil, program akan mencetak 1, lalu memanggil `countdown(0)`.
   Karena `countdown(0)` memenuhi kasus basis (n < 1), maka rekursif berhenti.

7. Setelah rekursif selesai, program akan mencetak output "Rekursif Langsung: 5 4 3 2 1" di layar, yang merupakan hasil dari hitung mundur dari angka 5. 

### 2. Rekursif Tidak Langsung (Indirect Recursion)
```C++
#include <iostream>
using namespace std;

void functionB(int 'n');

void functionA(int 'n') {
    if ('n' > 0) {
        cout << 'n' << " ";
        functionB('n' - 1); // Panggilan rekursif tidak langsung
    }
}

void functionB(int 'n') {
    if ('n' > 0) {
        cout << 'n' << " ";
        functionA('n' / 2); // Panggilan rekursif tidak langsung
    }
}

int main() {
    int num = 5;
    cout << "Rekursif Tidak Langsung: ";
    functionA(num);
    return 0;
}
```
### Penjelasan
Program ini mengimplementasikan rekursif tidak langsung (indirect recursion) dengan menggunakan dua fungsi, yaitu `functionA` dan `functionB`. Rekursif tidak langsung terjadi ketika sebuah fungsi memanggil fungsi lain secara rekursif, dan fungsi yang dipanggil kemudian memanggil fungsi pertama secara rekursif.

1. Fungsi `functionA` menerima sebuah parameter bertipe integer `n`. Jika `n` lebih besar dari 0, fungsi akan mencetak `n` ke layar, kemudian memanggil `functionB` dengan parameter `n-1` (rekursif tidak langsung).

2. Fungsi `functionB` juga menerima sebuah parameter bertipe integer `n`. Jika `n` lebih besar dari 0, fungsi akan mencetak `n` ke layar, kemudian memanggil `functionA` dengan parameter `n/2` (rekursif tidak langsung).

3. Di dalam fungsi `main`, program menginisialisasi variabel `num` dengan nilai 5, kemudian memanggil `functionA` dengan parameter `num`.

4. Ketika `functionA(5)` dipanggil, fungsi akan mencetak 5 ke layar, kemudian memanggil `functionB(4)`.

5. Ketika `functionB(4)` dipanggil, fungsi akan mencetak 4 ke layar, kemudian memanggil `functionA(2)`.

6. Proses ini berlanjut dengan `functionA` dan `functionB` saling memanggil satu sama lain secara rekursif sampai kondisi berhenti (`n` <= 0) terpenuhi.

7. Setelah rekursif selesai, program akan mencetak output "Rekursif Tidak Langsung: 5 4 2 1 1" di layar, yang merupakan hasil dari pemanggilan rekursif tidak langsung antara `functionA` dan `functionB`.

Pola output yang dihasilkan adalah sebagai berikut:
- `functionA(5)` mencetak 5, kemudian memanggil `functionB(4)`
- `functionB(4)` mencetak 4, kemudian memanggil `functionA(2)`
- `functionA(2)` mencetak 2, kemudian memanggil `functionB(1)`
- `functionB(1)` mencetak 1, kemudian memanggil `functionA(0)`
- `functionA(0)` tidak mencetak apapun karena kondisi berhenti terpenuhi
- Rekursif berhenti dan program selesai.

### 3. Hash Table
```C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int TABLE_SIZE = 11;

string name;
string phone_number;
class HashNode{
    public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number){
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap{
    private:
    vector<HashNode*> table[TABLE_SIZE];
    public:
    int hashFunc(string key){
        int hash_val = 0;
        for (char c : key){
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }
    void insert(string name, string phone_number){
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val]){
            if (node->name == name){
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }
    void remove(string name){
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++){
            if ((*it)->name == name){
                table[hash_val].erase(it);
                return;
            }
        }
    }
    string searchByName(string name){
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]){
            if (node->name == name){
                return node->phone_number;
            }
        }
        return "";
    }
    void print(){
        for (int i = 0; i < TABLE_SIZE; i++){
            cout << i << ": ";
            for (auto pair : table[i]){
                if (pair != nullptr){
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main(){
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah: " << employee_map.searchByName("Mistah") << endl;
    cout << "Nomer Hp Mistah: " << employee_map.searchByName("Pastah") << endl;
    cout << "Nomer Hp Mistah: " << employee_map.searchByName("Ghana") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus: " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table: " << endl;

    employee_map.print();

    return 0;
}
```
### Penjelasan
Program di atas mengimplementasikan struktur data Hash Table untuk menyimpan pasangan nama dan nomor telepon.

1. Program mendefinisikan dua variabel global `name` dan `phone_number` untuk menyimpan nama dan nomor telepon.

2. Terdapat dua kelas, yaitu `HashNode` dan `HashMap`:
   - `HashNode` merupakan kelas yang merepresentasikan sebuah node dalam tabel hash, yang berisi nama dan nomor telepon.
   - `HashMap` merupakan kelas yang mengimplementasikan operasi-operasi pada tabel hash, seperti penyisipan, penghapusan, pencarian, dan pencetakan tabel.

3. Kelas `HashMap` memiliki array vektor bernama `table` dengan ukuran `TABLE_SIZE` (11) untuk menyimpan node-node `HashNode`.

4. Fungsi `hashFunc` digunakan untuk menghasilkan nilai hash dari suatu kunci (nama) dengan menjumlahkan nilai ASCII dari setiap karakter dalam nama tersebut dan mengambil sisa pembagiannya dengan `TABLE_SIZE`.

5. Fungsi `insert` digunakan untuk menyisipkan pasangan nama dan nomor telepon ke dalam tabel hash. Jika nama sudah ada, nomor telepon akan diperbarui.

6. Fungsi `remove` digunakan untuk menghapus node dengan nama tertentu dari tabel hash.

7. Fungsi `searchByName` digunakan untuk mencari nomor telepon berdasarkan nama dalam tabel hash.

8. Fungsi `print` digunakan untuk mencetak seluruh isi tabel hash ke layar.

9. Dalam fungsi `main`, program membuat objek `employee_map` dari kelas `HashMap`.

10. Program kemudian menyisipkan tiga pasangan nama dan nomor telepon ke dalam `employee_map`.

11. Program mencari dan mencetak nomor telepon untuk tiga nama yang diberikan.

12. Program menghapus nama "Mistah" dari tabel hash dan mencari nomor teleponnya untuk memverifikasi bahwa penghapusan berhasil dilakukan.

13. Terakhir, program mencetak seluruh isi tabel hash ke layar.

## Unguided
### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!
```C++
#include <iostream>
using namespace std;

int Grahen_231110062;

// Fungsi untuk menghitung faktorial menggunakan rekursi
int factorial(int n) {
    if (n == 0) {  // basis kasus: faktorial dari 0 adalah 1
        return 1;
    } else {  // Rumus rekursif: n! = n * (n-1)!
        return n * factorial(n - 1);
    }
}

int main() {
    int angka;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> angka;

    if (angka >= 0) {
        cout << "Faktorial dari " << angka << " adalah: " << factorial(angka) << endl;
    } else {
        cout << "Mohon masukkan bilangan bulat yang lebih besar atau sama dengan 0." << endl;
    }

    return 0;
}
```
#### Output:
![Screenshot]
### Penjelasan
Program ini mengimplementasikan konsep rekursif langsung (direct recursion) untuk menghitung nilai faktorial dari sebuah bilangan bulat positif yang diinputkan oleh pengguna. Program memiliki sebuah fungsi bernama `factorial` yang menerima parameter `n` bertipe integer.

Dalam fungsi `factorial`, terdapat dua kasus:

1. Kasus basis (base case): Jika `n` bernilai 0, maka fungsi akan mengembalikan nilai 1, karena faktorial dari 0 adalah 1 (0! = 1).

2. Kasus rekursif: Jika `n` tidak bernilai 0, maka fungsi akan memanggil dirinya sendiri dengan argumen `n-1` dan mengalikan hasilnya dengan `n`. Ini sesuai dengan rumus rekursif untuk menghitung faktorial, yaitu `n! = n * (n-1)!`.

Di dalam fungsi `main`, program meminta pengguna untuk memasukkan sebuah bilangan bulat positif. Jika bilangan yang dimasukkan lebih besar atau sama dengan 0, maka program akan memanggil fungsi `factorial` dengan bilangan tersebut sebagai argumen dan menampilkan hasil faktorialnya ke layar. Namun, jika bilangan yang dimasukkan kurang dari 0, program akan menampilkan pesan kesalahan karena faktorial hanya dapat dihitung untuk bilangan bulat positif.

Jadi, program ini memanfaatkan konsep rekursif langsung untuk menghitung faktorial dari sebuah bilangan bulat positif dengan cara memecah masalah menjadi submasalah yang lebih sederhana hingga mencapai kasus basis.

### 2. Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 di atas!
```C++
#include <iostream>
using namespace std;

int Grahen_2311110062;

int factorialB(int n);

// Fungsi pertama yang memulai panggilan rekursi tidak langsung
int factorialA(int n) {
    if (n == 0) {  
        return 1;
    } else {  
        return n * factorialB(n - 1);
    }
}

// Fungsi kedua yang melanjutkan panggilan rekursi tidak langsung
int factorialB(int n) {
    if (n == 0) {  
        return 1;
    } else {  
        return n * factorialA(n - 1);
    }
}

int main() {
    int number;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> number;

    if (number >= 0) {
        cout << "Faktorial dari " << number << " adalah: " << factorialA(number) << endl;
    } else {
        cout << "Mohon masukkan bilangan bulat yang lebih besar atau sama dengan 0." << endl;
    }

    return 0;
}
```
#### Output
![Screenshot]

### Penjelasan
Program ini mengimplementasikan konsep rekursif tidak langsung (indirect recursion) untuk menghitung nilai faktorial dari sebuah bilangan bulat positif yang diinputkan oleh pengguna. Program memiliki dua fungsi rekursif, yaitu `factorialA` dan `factorialB`.

Dalam fungsi `factorialA`, terdapat dua kasus:

1. Kasus basis (base case): Jika `n` bernilai 0, maka fungsi akan mengembalikan nilai 1, karena faktorial dari 0 adalah 1 (0! = 1).

2. Kasus rekursif: Jika `n` tidak bernilai 0, maka fungsi akan memanggil fungsi `factorialB` dengan argumen `n-1` dan mengalikan hasilnya dengan `n`.

Sementara itu, dalam fungsi `factorialB`, terdapat dua kasus serupa:

1. Kasus basis: Jika `n` bernilai 0, maka fungsi akan mengembalikan nilai 1.

2. Kasus rekursif: Jika `n` tidak bernilai 0, maka fungsi akan memanggil fungsi `factorialA` dengan argumen `n-1` dan mengalikan hasilnya dengan `n`.

Di dalam fungsi `main`, program meminta pengguna untuk memasukkan sebuah bilangan bulat positif. Jika bilangan yang dimasukkan lebih besar atau sama dengan 0, maka program akan memanggil fungsi `factorialA` dengan bilangan tersebut sebagai argumen dan menampilkan hasil faktorialnya ke layar. Namun, jika bilangan yang dimasukkan kurang dari 0, program akan menampilkan pesan kesalahan karena faktorial hanya dapat dihitung untuk bilangan bulat positif.

Ketika fungsi `factorialA` dipanggil, ia akan melakukan pemanggilan rekursif tidak langsung ke fungsi `factorialB`, dan begitu pula sebaliknya. Proses ini akan berlanjut sampai akhirnya mencapai kasus basis `n = 0` pada salah satu fungsi. Setelah mencapai kasus basis, nilai-nilai akan dikalikan secara berurutan mengikuti alur rekursi tidak langsung.

Jadi, program ini memanfaatkan konsep rekursif tidak langsung, di mana dua fungsi saling memanggil satu sama lain secara rekursif, untuk menghitung faktorial dari sebuah bilangan bulat positif.

### 3. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan : a. Setiap mahasiswa memiliki NIM dan nilai. b. Program memiliki tampilan pilihan menu berisi poin C. c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).
```C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Grahen_2311110062;

const int TABLE_SIZE = 11;

// Struktur untuk menyimpan data mahasiswa
struct Mahasiswa {
    string nim;
    string nama;
    double nilai;
    Mahasiswa(string nim, string nama, double nilai) : nim(nim), nama(nama), nilai(nilai) {}
};

class HashMap {
private:
    vector<Mahasiswa*> table[TABLE_SIZE];

    // Fungsi hash untuk menghasilkan indeks dari sebuah NIM
    int hashFunc(string nim) {
        int hash_val = 0;
        for (size_t i = 0; i < nim.length(); ++i) {
            hash_val += nim[i];
        }
        return hash_val % TABLE_SIZE;
    }

public:
    // Fungsi untuk menambahkan data mahasiswa baru
    void tambahData(string nim, string nama, double nilai) {
        int index = hashFunc(nim);
        table[index].push_back(new Mahasiswa(nim, nama, nilai));
    }

    // Fungsi untuk menghapus data mahasiswa berdasarkan NIM
    void hapusData(string nim) {
        int index = hashFunc(nim);
        for (size_t i = 0; i < table[index].size(); ++i) {
            if (table[index][i]->nim == nim) {
                delete table[index][i];
                table[index].erase(table[index].begin() + i);
                return;
            }
        }
        cout << "Mahasiswa dengan NIM '" << nim << "' tidak ditemukan." << endl;
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan NIM
    void cariByNIM(string nim) {
        int index = hashFunc(nim);
        for (size_t i = 0; i < table[index].size(); ++i) {
            if (table[index][i]->nim == nim) {
                cout << "Mahasiswa dengan NIM '" << nim << "' ditemukan.\nNama: " << table[index][i]->nama << ", Nilai: " << table[index][i]->nilai << endl;
                return;
            }
        }
        cout << "Mahasiswa dengan NIM '" << nim << "' tidak ditemukan." << endl;
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai
    void cariByRange(double minNilai, double maxNilai) {
        bool found = false;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (size_t j = 0; j < table[i].size(); ++j) {
                if (table[i][j]->nilai >= minNilai && table[i][j]->nilai <= maxNilai) {
                    found = true;
                    cout << "NIM: " << table[i][j]->nim << ", Nama: " << table[i][j]->nama << ", Nilai: " << table[i][j]->nilai << endl;
                }
            }
        }
        if (!found) {
            cout << "Mahasiswa dengan nilai antara " << minNilai << " dan " << maxNilai << " tidak ditemukan." << endl;
        }
    }

    // Destructor untuk membersihkan memori
    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (size_t j = 0; j < table[i].size(); ++j) {
                delete table[i][j];
            }
        }
    }
};

int main() {
    HashMap mahasiswa_map;
    int choice;
    string nim, nama;
    double nilai;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Hapus Data Mahasiswa\n";
        cout << "3. Cari Mahasiswa Berdasarkan NIM\n";
        cout << "4. Cari Mahasiswa Berdasarkan Rentang Nilai (80 - 90)\n";
        cout << "5. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan NIM Mahasiswa: ";
                cin >> nim;
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Nilai Mahasiswa: ";
                cin >> nilai;
                mahasiswa_map.tambahData(nim, nama, nilai);
                break;
            case 2:
                cout << "Masukkan NIM Mahasiswa yang akan dihapus: ";
                cin >> nim;
                mahasiswa_map.hapusData(nim);
                break;
            case 3:
                cout << "Masukkan NIM Mahasiswa yang ingin dicari: ";
                cin >> nim;
                mahasiswa_map.cariByNIM(nim);
                break;
            case 4:
                mahasiswa_map.cariByRange(80.0, 90.0);
                break;
            case 5:
                cout << "Terima kasih! Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan masukkan pilihan yang benar.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
```
#### Output
![Screenshot]

### Penjelasan
Program ini mengimplementasikan struktur data Hash Table untuk menyimpan data mahasiswa yang terdiri dari NIM, nama, dan nilai. Program mendefinisikan sebuah struct `Mahasiswa` yang menyimpan atribut-atribut tersebut.

Kelas utama adalah `HashMap` yang memiliki array vektor `table` dengan ukuran tetap `TABLE_SIZE` (dalam kasus ini, 11). Setiap elemen pada array ini adalah vektor yang menyimpan pointer ke objek `Mahasiswa`. Fungsi `hashFunc` digunakan untuk menghitung nilai hash dari sebuah NIM dengan menjumlahkan nilai ASCII setiap karakternya dan mengambil sisa pembagian dengan `TABLE_SIZE`. Nilai hash ini digunakan sebagai indeks untuk menyimpan atau mencari data mahasiswa pada array `table`.

Program menyediakan empat fungsi utama:

1. `tambahData`: Digunakan untuk menambahkan data mahasiswa baru ke dalam Hash Map. Fungsi ini akan menghitung nilai hash dari NIM yang diberikan dan menempatkan objek `Mahasiswa` baru pada vektor di indeks yang sesuai.

2. `hapusData`: Digunakan untuk menghapus data mahasiswa berdasarkan NIM. Fungsi ini akan mencari objek `Mahasiswa` dengan NIM yang sesuai pada vektor di indeks yang sesuai, menghapusnya, dan membersihkan memori yang digunakan.

3. `cariByNIM`: Digunakan untuk mencari data mahasiswa berdasarkan NIM yang diberikan. Fungsi ini akan menghitung nilai hash dari NIM, lalu memeriksa setiap objek `Mahasiswa` pada vektor di indeks yang sesuai. Jika ditemukan, data mahasiswa akan dicetak.

4. `cariByRange`: Digunakan untuk mencari data mahasiswa berdasarkan rentang nilai yang diberikan. Fungsi ini akan memeriksa setiap objek `Mahasiswa` pada semua vektor di semua indeks. Jika nilai mahasiswa berada dalam rentang yang diberikan, data mahasiswa akan dicetak.

Dalam fungsi `main`, program menampilkan menu dan meminta pengguna untuk memilih operasi yang ingin dilakukan. Pengguna dapat menambah data, menghapus data, mencari data berdasarkan NIM, atau mencari data berdasarkan rentang nilai.

Setelah selesai menggunakan program, destruktor `~HashMap` akan dipanggil secara otomatis untuk membersihkan memori yang digunakan oleh objek-objek `Mahasiswa`.

Jadi, program ini memanfaatkan struktur data Hash Table untuk menyimpan dan mengakses data mahasiswa secara efisien dengan mengimplementasikan berbagai operasi seperti penambahan, penghapusan, pencarian berdasarkan NIM, dan pencarian berdasarkan rentang nilai.

## Kesimpulan
#### Hasil praktikum: 
Pada kesempatan praktikum ini, saya belajar Rekursif dan Hash Table. Rekursif adalah suatu konsep dalam ilmu komputer dan pemrograman di mana suatu fungsi atau prosedur dapat memanggil dirinya sendiri secara langsung atau tidak langsung. Sedangkan Hash Table adalah Hash Table (Tabel Hash) adalah struktur data yang digunakan untuk menyimpan pasangan kunci-nilai (key-value pairs). 

#### Pelajaran yang didapat
1. **Rekursif**: 
   - Konsep rekursif merupakan metode dalam ilmu komputer di mana fungsi atau prosedur dapat memanggil dirinya sendiri untuk memecahkan masalah. 
   - Hal ini memungkinkan masalah yang kompleks dipecah menjadi masalah yang lebih kecil dan lebih sederhana yang lebih mudah untuk diatasi.
   - Rekursi sering digunakan dalam pemecahan masalah algoritma dan pemrograman karena keefektifannya dalam menyederhanakan penyelesaian masalah melalui pendekatan langkah demi langkah.

2. **Hash Table**:
   - Hash table adalah struktur data yang memanfaatkan algoritma hash untuk menyimpan dan mengelola pasangan kunci-nilai.
   - Struktur ini menawarkan efisiensi yang tinggi dalam operasi penyisipan, pencarian, dan penghapusan, dengan kompleksitas waktu rata-rata O(1).
   - Keunggulan hash table menjadikannya pilihan yang populer dalam pengembangan perangkat lunak, terutama saat kecepatan akses data menjadi prioritas utama.

## Referensi
[1] Stephen Herlambang, “Implementasi Fungsi Rekursif Dalam Algoritma dan Perbandingannya dengan Fungsi Iteratif”, 2008.

[2] Jasson Prestiliano, "Aplikasi Tabel Hash dalam Pengarsipan dan Pencarian Data", 2007.
