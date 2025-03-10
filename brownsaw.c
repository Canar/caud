#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#define FREQ 2048
#define LEN 16384
void main(){
	uint16_t buf[FREQ];
	uint64_t off=0;
	uint64_t width,i,flw;
	srand(clock());
	
	while( off < LEN ){
		flw=(off * FREQ) / LEN;
		width=( random()%( flw + 1) ) + 2 ;
		fprintf(stderr,"%d %d %d\n",width, off, flw);
		for(i=0;i<width;i++){
			buf[i]=i * ( UINT16_MAX * (LEN - off) / LEN ) / ( width - 1 ) ;
		}
		off+=write(1,buf,sizeof(buf[0])*width);
	}
}
