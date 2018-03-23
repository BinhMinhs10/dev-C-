#include <iostream> 
#include <fstream> 
#include <iostream> 
using namespace std;

int main()
{
    ofstream SoChan ("So Chan.txt");
    SoChan<<"Day so chan tu 1 -> 1000 \n";
    for(int a = 1; a <= 1000; a++)
    {
        if(a%2 == 0)
        {
            SoChan<<a;
            SoChan<<"\n";
        }
    }
    SoChan.close();
    return 0;
}
