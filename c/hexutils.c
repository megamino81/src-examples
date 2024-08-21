#include <stdio.h>
#include <stdlib.h>

char *byte_to_hex(const char *buf, int count);
int hex_to_byte( const char* hex, size_t length, char* binrary, size_t binrary_cap );

inline char hex_to_char(char c) {
    if ('0' <= c && c <= '9') {
        return c - '0';
    } else if ('a' <= c && c <= 'f') {
        return c + 10 - 'a';
    } else if ('A' <= c && c <= 'F') {
        return c + 10 - 'A';
    }
    return -1;
}

int hex_to_byte( const char* hex, size_t length, char* binrary, size_t binrary_cap )
{
    int i;

    if (length % 2 != 0 || binrary_cap < length / 2) {
        return 0;
    }

    memset(binrary, 0, binrary_cap);

    int n = 0;
    for (i = 0; i < length; i += 2, ++n) {
        char high = hex_to_char(hex[i]);
        if (high < 0) {
            return 0;
        }

        char low = hex_to_char(hex[i + 1]);
        if (low < 0) {
            return 0;
        }

        binrary[n] = high << 4 | low;
    }
    return n;
}

char *
byte_to_hex(const char *buf, int count) {
    char *out = (char *)malloc(2 * count + 1);
    char *outPtr = out;
    int i;
    for(i=0; i<count; i++) {
        outPtr += sprintf(outPtr, "%02X", buf[i]);
    }
    return out;
}


#if 0
int main(int argc, char *argv[]) {
    int i;
    char buf[5] = {10, 20, 30, 40, 50};
    int buf_len = 5;

    printf("orig byte=");
    for (i=0; i<buf_len; i++) {
        printf("%d ", buf[i]);
    }

    printf("\n");

    char *hex = byte_to_hex(buf, buf_len);
    printf("hex=%s\n", hex);

    char byte[buf_len];
    int result = hex_to_byte(hex, buf_len * 2, byte, buf_len);

    printf("new byte=");
    for (i=0; i<buf_len; i++) {
        printf("%d ", byte[i]);
    }
    printf("\n");
    return 0;
}
#endif
