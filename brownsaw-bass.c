#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#define FREQ 2048
#define LEN 65536*16

#include "common.c"

void main(){
	uint16_t buf[FREQ];
	uint16_t off=0;
	uint16_t val=0;
	uint64_t width,i,flw;
	seed_random();
	
	while( off < LEN ){
		flw=((uint64_t)off * FREQ) / LEN;
		width=random()%(flw+1)+1;
/*		fprintf(stderr,"%d %d %d\n",width, off, flw); */
		for(i=0;i<width;i++){
			val+=width;
			buf[i]=val;
		}
		if(width>0)
			off+=write(1,buf,sizeof(buf[0])*width);
	}
}
