#include <stdio.h>

#include <stddef.h>

// Linux
#include <stdint.h>

#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>


#define kAES_CTR_Size 16

int main(int argc, char *argv[]) {
    size_t inLen = 128;

    while(inLen >= kAES_CTR_Size) {
        printf("%u\n", inLen);
        inLen -= kAES_CTR_Size;
    }

    return 0;
}
