#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char filename[256];
  long max;
  short len;
  FILE *f = NULL;

  if (argv[1] == NULL) goto error;

  max = sizeof(filename);
  len = strlen(argv[1]);

  if (argv[2] == NULL) goto error;

  if (len > max) goto error;

  strcpy(filename, argv[1]);
  if (access(filename, W_OK)) goto error;
  
  if (strncmp(filename, "/tmp/", strlen("/tmp/")) != 0) goto error;
  
  if ((f = fopen(filename, "a")) == NULL) goto error;
  fwrite(argv[2], strlen(argv[2]), 1, f);
  fclose(f);
  return 0;

 error:
  return -1;
}
  


  
 
