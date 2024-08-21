#include <stdio.h>

int random(int range);

int main(void)
{
	printf("%d", random(10));
	return 0;
}

int random(int range)
{
	struct time_t t;
	int r;

	gettime(&t);
	r = t.ti_sec % range;
	return r;
}
