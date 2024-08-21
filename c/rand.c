#include <stdio.h>
#include <time.h>

int random_number(int min_num, int max_num);

int
random_number(int min_num, int max_num)
{
	int result=0, low_num=0, hi_num=0;
	struct timespec ts;

	if (min_num < max_num) {
		low_num = min_num;
		hi_num = max_num + 1; // include max_num in output
	}
	else {
		low_num = max_num + 1; // include max_num in output
		hi_num = min_num;
	}

    clock_gettime(CLOCK_MONOTONIC, &ts);

	/* using nano-seconds instead of seconds */
	srand((time_t)ts.tv_nsec);
	result = (rand() % (hi_num - low_num)) + low_num;

	return result;
}
