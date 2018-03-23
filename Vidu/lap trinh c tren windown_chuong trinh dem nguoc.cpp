#include <iostream>
#include <windows.h>
#include <unistd.h>
#define timer 10
using namespace std;
int main ()
{
	int count = timer;
	while(count != 0)
	{
		system("pause");
		cout << count--;
		sleep(2);
	}
	return 0;
}
