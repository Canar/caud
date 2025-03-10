#include <stdlib.h>
#include <stdint.h>
#include <time.h>

uint64_t atime(){
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC_RAW,&ts);
	uint64_t out=(uint64_t)ts.tv_sec*1000000000 + ts.tv_nsec;
	return out;
}
void seed_random(){
	uint64_t at=atime();
	srandom(at);
}
