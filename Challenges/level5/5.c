#include <stdio.h>
#include <stdlib.h>

#define TABLELEN 7
int table[] = {2, 3, 5, 7, 11, 13, 17};

void loadTable(int *hashtable) {
  int i;
  for (i = 0; i < TABLELEN; i++) {
    hashtable[i] = table[i];
  }	
}

int main(int argc, char *argv[])
{
  int array[8];
  int index;
  int value;
  if (argc < 3) {
    fprintf(stderr, "Not enough args\n");
    return -1;
  }
  loadTable(array);
  index = (int) strtol(argv[1], NULL, 10);
  value = (int) strtoul(argv[2], NULL, 16);
  printf("Updating table value at index %d with %d: previous value was %d\n",
	 index, value, array[index]); 
  array[index] = value;
  printf("The updated table is:\n");
  for (index = 0; index < TABLELEN; index++) {
    printf("%d: %d\n", index, array[index]);
  }
  return 0;
}
