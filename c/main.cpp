#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char a[10];
	char *b = (char *)malloc(10);
	printf("a size=%d\n", sizeof(a));
	printf("b size=%d\n", sizeof(*b));
	return 0;
}
