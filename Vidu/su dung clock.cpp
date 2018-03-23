#include <iostream>
#include <stdio.h>
#include <time.h>
void wait(int seconds)
{
	clock_t ew;
	ew = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < ew) {}
}
int main()
{
	int n;
	for (n = 1; n>0; n++)
	{
		if (n < 101) // d?m d?n 100
		{
			printf("%d\n", n);
			wait(2); // 2 giây.
		}

	}
	return 0;
}
