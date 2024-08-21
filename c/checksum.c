#include <stdio.h>

int main(int argc, char *argv[]) {
    unsigned char a = 0;
    a = 0x51 + 0xaf;
    printf("a=%x\n", a);

    char b = 0;
    b = 0x52 + 0xaf;
    printf("b=%x\n", b);

    int c = 0;
    c = 0x51 + 0xaf;
    printf("c=%x\n", c);

    return 0;
}
