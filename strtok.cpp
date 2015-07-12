/* strtok example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="- This, a sample string.";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ,.-");

  char str2[] = "1.2";
  pch = strtok(str2,".");
  //printf("%s\n",pch );
  pch = strtok(NULL,".");
  printf("%s\n",pch );
  printf("%d\n","13">"14");
  // while (pch != NULL)
  // {
  //   printf ("%s\n",pch);
  //   pch = strtok (NULL, " ,.-");
  //   printf("haha\n" );
  // }

  return 0;
}