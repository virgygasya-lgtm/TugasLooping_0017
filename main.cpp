#include <iostream>
using namespace std;

int n;       // variabel global untuk angka
int choice;  // variabel global untuk menu

bool isPrime(int num) 
{
    if (num <= 1) return false;
    int i = 2;
    while (i <= num / 2) 
    {
        if (num % i == 0) return false;
        i++;
    }
    return true;
}

bool isFibonacci(int num) 
{
    if (num < 0) return false;
    int a = 0, b = 1;
    while (b < num) 
    {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return (num == a || num == b);
}

void inputNumber() 
{
    cout << "Masukkan angka (>=1): ";
    cin >> n;
    if (n < 1) {
        cout << "Input tidak valid. Angka harus >= 1.\n";
        n = 1; // fallback default
    }
}

void showResultPrime() 
{
    if (isPrime(n)) {
        cout << n << " adalah bilangan prima.\n";
    } else {
        cout << n << " bukan bilangan prima.\n";
    }
}

void showResultFibonacci() 
{
    if (isFibonacci(n)) {
        cout << n << " termasuk bilangan Fibonacci.\n";
    } else {
        cout << n << " bukan bilangan Fibonacci.\n";
    }
}

void showMenu() 
{
    cout << "\n=== MENU ===\n";
    cout << "1. Cek bilangan prima\n";
    cout << "2. Cek bilangan Fibonacci\n";
    cout << "0. Keluar\n";
    cout << "Pilihan: ";
    cin >> choice;
}

int main() 
{
    while (true) 
    {
        showMenu();
        switch (choice) 
        {
            case 1:
                inputNumber();
                showResultPrime();
                break;
            case 2:
                inputNumber();
                showResultFibonacci();
                break;
            case 0:
                cout << "Program selesai.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    }
}