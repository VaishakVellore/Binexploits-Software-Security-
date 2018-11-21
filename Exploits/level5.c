#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char* ptr = getenv("SHELLCODE");
    printf("%p\n", ptr);
}
