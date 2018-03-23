#include <stdio.h>
#include <dos.h>
int main(void)
{
	struct time t;
	gettime(&t);
	printf("thoi gian hien tai la: %2d:%2d:%d:%2d\n",t.ti_hour,t.ti_min,t.ti_sec,t.ti_hund);
	return 0;
}
