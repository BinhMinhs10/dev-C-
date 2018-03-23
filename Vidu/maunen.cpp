#include <windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsoleColor, 6);
        cout << "  nguyen binh minh  ";
         printf("\n");
    
    return 0;
}
