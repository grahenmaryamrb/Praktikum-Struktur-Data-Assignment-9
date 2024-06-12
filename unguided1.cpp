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