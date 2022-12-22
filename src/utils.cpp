#include "utils.h"
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <memory.h>
#include <sys/time.h>

void generate_random(unsigned char* random, int size) {
	const long MAX = 1L << 32L;
	while (size > 0) {
		uint32_t r = rand() % MAX;
		for (int i = 0; i < 4; i++) {
			int x = (r >> (i * 8)) & ((1 << 8) - 1);
			memcpy(random++, &x, 1);
			if (--size <= 0) {
				break;
			}
		}
	}
}

uint64_t timeus() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_usec;
}
