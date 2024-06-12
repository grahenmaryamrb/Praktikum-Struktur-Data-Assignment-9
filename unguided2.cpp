#include <iostream>
using namespace std;

int Grahen_231110062;

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
