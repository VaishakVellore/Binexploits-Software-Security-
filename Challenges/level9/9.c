#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
  char buf[16];

  /* No args if it's SUID */ 
  if ((getegid() != getgid()) && argc != 0) {
    exit(1);
  }

  if (strchr(argv[4], 0x90)) exit(2);
  if (strchr(argv[4], 0x31)) exit(2);

  strcpy(buf, argv[4]);
  return 0;
}
  
