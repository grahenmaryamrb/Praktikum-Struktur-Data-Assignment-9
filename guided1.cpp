#include <iostream>
using namespace std;

// Code ini berfungsi untuk melakukan hitung mundur
// dari angka yang diinputkan
void countdown(int n) {
    if (n >= 1) {
        cout << n << " ";
        countdown(n - 1);
    }
}

int main() {
    cout << "Rekursif Langsung: ";
    countdown(5); // 5 merupakan input nya
    cout << endl;
    return 0;
}