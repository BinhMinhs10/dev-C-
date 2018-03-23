#include <stdio.h>
main()
{
	FILE *f;
	f=fopen("sl","wb");
	fprintf(f,"%2d\n%2d\n%2d",56,7,8);
	fclose(f);
}
