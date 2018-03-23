#include <stdio.h>
main()
{
	void thi_du(void);
	int n;
	for(n=1;n<=5;n++)
	 thi_du();
}
void thi_du(void)
{
	static int i=2;
	i++;
	printf("Goi lan thu %d\n",i);
}
