#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#define FREQ 2048
#define LEN 16384

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
void main(){
	uint64_t at=atime();
	srandom(at);
	fprintf(stderr,"%lld %ld %d\n",at,at,at);
}
