#include <stdio.h>

int main ()
{
  FILE * pFile;
  long size;

  pFile = fopen ("C:\\Users\\ThuyLinh Computer\\Documents\\dev-C++\\myfile.txt","rb");
  if (pFile==NULL) perror ("Error opening file");
  else
  {
    //fseek (pFile, 0, SEEK_END);   // non-portable
    size=ftell (pFile);
    fclose (pFile);
    printf ("Size of myfile.txt: %ld bytes.\n",size);
  }
  return 0;
}
