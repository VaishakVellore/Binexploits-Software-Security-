#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 512
#define DICTFILE "/usr/share/dict/words"

int checkpwd(char *p) 
{ 
  char mypwd[BUFSIZE]; 
  char word[BUFSIZE];
  FILE *f = NULL;

  strcpy(mypwd, p); /* creates copy of the password */
  printf("Checking password %s\n", mypwd);

  if ((f = fopen(DICTFILE, "r")) == NULL) {
    fprintf(stderr, "Cannot open dict file\n");
    return -1;
  }  
  while (fgets(word, BUFSIZE, f)) {
    if (!strncmp(mypwd, word, strlen(mypwd))) {
      fprintf(stderr, "Password %s is in the dictionary!\n", mypwd);
      return -1;
    }
  }
  
  return 0;
} 

int main (int argc, char *argv[]) 
{ 
  char username[BUFSIZE]; 
  char password[BUFSIZE]; 

  if ((argv[1] == NULL) || (argv[2] == NULL)) {
    fprintf(stderr, "Usage: %s <pwd> <user>\n", argv[0]);
    return -2;
  }
  strncpy(password, argv[1], BUFSIZE); 
  strncpy(username, argv[2], BUFSIZE);
  printf("Checking password %s for user %s\n", password, username);
  if (checkpwd(password)) {
    printf("User %s chose a bad password\n", username);
    return -1;
  }
  printf("User %s chose a good password\n", username);
  return 0;
} 
