#include <stdio.h>
#include "hbridge.h"

int main(int argc, char*argv[]) {
	initHbridge();
	
	setSpeed(0, 10);
	
	rotate(0, 1);
	for (int i = 0; i < 100000000; i++) {}
	
	rotate(0, 0);
	for (int i = 0; i < 100000000; i++) {}
	
	
	stop(0);
	fprintf(stderr, "motors stopped\n");
}
