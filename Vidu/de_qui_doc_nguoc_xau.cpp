#include <iostream>
void ReverseString()
{
    char X;
    std::cin.get(X);
    if ( X == '\n')
        return;
    ReverseString();
    std::cout << X;
}

int main()
{
    std::cout << "Enter a string : ";
    ReverseString();
    return 0;
}  
