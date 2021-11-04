// Laboratorna 6.3(2).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int n, int Low, int High, int i) {
        a[i] = Low + rand() % (High - Low + 1);
        if (i < n - 1)
            Create(a, n, Low, High, i + 1);
}
template<typename T>
void Create(T* a, const int n, int Low, int High, int i) {
        a[i] = (T)Low + rand() % (High - Low + 1);
        if (i < n - 1)
            Create(a, n, Low, High, i + 1);
}
void Print(int* a, const int n, int i) {
        cout << setw(4) << a[i];
        if (i < n - 1)
            Print(a, n, i + 1);
        else
            cout << endl;
}
template <typename T>
void Print(T* a, const int n, int i) {
    cout << setw(4) << a[i];
    if (i < n - 1)
        Print(a, n, i + 1);
    else
        cout << endl;
}
int Min(int* a, const int n, int min, int i) {
        if (a[i] < min)
            min = a[i];
        if (i < n - 1)
            return Min(a, n, min, i + 1);
        else 
           return min;
}
template <typename T>
int Min(T* a, const int n, int min, int i) {
    if (a[i] < min)
        min = a[i];
    if (i < n - 1)
        return Min(a, n, min, i + 1);
    else
        return min;
}
int main()
{
    srand((unsigned)time(NULL));
    int n;
    cout << "n="; cin >> n;
    int* a = new int[n];
    int Low;
    cout << "Low="; cin >> Low;
    int High;
    cout << "High="; cin >> High;
    Create(a, n, Low, High,0);
    Print(a, n, 0);

    cout << " min = " << Min(a, n, 0, 0) << endl;

    delete[] a;
    a = nullptr;
    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
